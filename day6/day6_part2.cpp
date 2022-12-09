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

const char *INPUT_FILE = "input.txt";
const size_t WINDOW_SIZE = 14;

int main() {
   ifstream iFile(INPUT_FILE);
    if (!iFile.is_open()) {
        return EXIT_FAILURE;
    }

    string str;
    getline(iFile, str);

    for (auto iter = str.begin(); iter != str.end(); iter++) {
        set<char> unique(iter, iter + WINDOW_SIZE);

        if (unique.size() == WINDOW_SIZE) {
            cout << std::distance(str.begin(), iter) + WINDOW_SIZE << endl;
            break;
        }
    }

    return EXIT_SUCCESS;
}
