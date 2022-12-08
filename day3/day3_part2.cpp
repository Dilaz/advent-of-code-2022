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

uint32_t countGroupScore(const vector<string> &group) {
    uint32_t sum = 0;
    string intersection;
    string intersection2;
    string first = group.at(0);
    string second = group.at(1);
    string third = group.at(2);

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    sort(third.begin(), third.end());

    std::set_intersection(first.begin(), first.end(), second.begin(), second.end(), back_inserter(intersection));
    std::set_intersection(third.begin(), third.end(), intersection.begin(), intersection.end(), back_inserter(intersection2));
    const set<char> uniqueIntersection(intersection2.begin(), intersection2.end());

    return strToPriority(uniqueIntersection);
}

int main() {
   ifstream iFile(INPUT_FILE);
    if (!iFile.is_open()) {
        return EXIT_FAILURE;
    }

    string str;
    uint32_t sum = 0;
    vector<string> group;
    uint32_t counter = 0;
    while (getline(iFile, str)) {
        group.push_back(str);

        if ((counter + 1) % 3 == 0) {
            sum += countGroupScore(group);
            group.clear();
        }

        counter++;
    }

    cout << sum << endl;

    return EXIT_SUCCESS;
}
