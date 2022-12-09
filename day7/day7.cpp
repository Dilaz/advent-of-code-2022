#include <cstdlib>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::getline;
#include <fstream>
using std::ifstream;
#include <set>
using std::set;
using std::pair;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <cmath>
using std::max;
#include <algorithm>
using std::back_inserter;
using std::sort;
#include <numeric>
using std::accumulate;
#include <memory>
using std::shared_ptr;
using std::make_shared;

const char *INPUT_FILE = "input.txt";
const uint32_t MAX_DIR_SIZE = 100000;

struct Dir {
    shared_ptr<Dir> parent = nullptr;
    vector<pair<string, uint32_t> > files;
    vector<pair<string, shared_ptr<Dir> > > dirs;
};

shared_ptr<Dir> mkDir(shared_ptr<Dir> &current, string dirName) {
    cout << "mkDir: " << dirName << endl;
    shared_ptr<Dir> newDir = make_shared<Dir>();
    newDir->parent = current;
    current->dirs.push_back({dirName, newDir});

    return newDir;
}

void handleCd(shared_ptr<Dir> &current, string dirName) {
    cout << "handleCd: " << dirName << endl;

    if (dirName == "/") {
        while (current->parent) {
            current = current->parent;
        }
        return;
    }
    if (dirName == "..") {
        current = current->parent;
        return;
    }

    for (auto dir : current->dirs) {
        if (dir.first == dirName) {
            current = dir.second;
            return;
        }
    }

    // Not found, create a new one
    shared_ptr<Dir> newDir = mkDir(current, dirName);
    current = newDir;
}

void createFile(shared_ptr<Dir> &current, const string &fileName, uint32_t fileSize) {
    cout << "createFile: " << fileName << ' ' << fileSize << endl;

    current->files.push_back({fileName, fileSize});
}

uint32_t getDirSize(shared_ptr<Dir> &dir) {
    uint32_t sum = accumulate(dir->files.begin(), dir->files.end(), 0, [](uint32_t s, pair<string, uint32_t> file) { return s + file.second; });
    for (auto iter = dir->dirs.begin(); iter != dir->dirs.end(); iter++) {
        sum += getDirSize(iter->second);
    }

    return sum;
}


void findDirs(shared_ptr<Dir> &dir, uint32_t &sum) {
    const uint32_t size = getDirSize(dir);
    if (size <= MAX_DIR_SIZE) {
        sum += size;
    }

    for (auto iter = dir->dirs.begin(); iter != dir->dirs.end(); iter++) {
        findDirs(iter->second, sum);
    }
}

int main() {
   ifstream iFile(INPUT_FILE);
    if (!iFile.is_open()) {
        return EXIT_FAILURE;
    }

    shared_ptr<Dir> root = make_shared<Dir>();
    shared_ptr<Dir> current(root);

    string str;
    bool readingFiles = false;
    while (getline(iFile, str)) {
        if (readingFiles) {
            if (str.at(0) == '$') {
                readingFiles = false;                
            } else {
                if (str.substr(0, 3) == "dir") {
                    mkDir(current, str.substr(4));
                } else {
                    istringstream ss(str);
                    uint32_t fileSize = 0;
                    string fileName;
                    ss >> fileSize >> fileName;
                    createFile(current, fileName, fileSize);
                }
            }
        }
        if (str.substr(0, 5) == "$ cd ") {
            handleCd(current, str.substr(5));
        } else if (str.substr(0, 4) == "$ ls") {
            readingFiles = true;
        }
    }

    uint32_t sum = 0;
    findDirs(root, sum);
    cout << sum << endl;


    return EXIT_SUCCESS;
}
