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

uint32_t strToPriority(const set<char> &str) {
    uint32_t score = 0;
    for (char chr : str) {
        // Lowercase
        if ('a' <= chr && chr <= 'z') {
            score += chr - 'a' + 1;
        } else {
            score += chr - 'A' + 27;
        }
    }

    return score;
}

int main() {
   ifstream iFile(INPUT_FILE);
    if (!iFile.is_open()) {
        return EXIT_FAILURE;
    }

    string str;
    uint32_t sum = 0;
    while (getline(iFile, str)) {
        string first = str.substr(0, str.length() / 2);
        string second = str.substr(str.length() / 2);
        string intersection;
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        std::set_intersection(first.begin(), first.end(), second.begin(), second.end(), back_inserter(intersection));
        set<char> uniqueIntersection(intersection.begin(), intersection.end());

        sum += strToPriority(uniqueIntersection);
    }

    cout << sum << endl;

    return EXIT_SUCCESS;
}
