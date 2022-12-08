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

int main() {
   ifstream iFile(INPUT_FILE);
    if (!iFile.is_open()) {
        return EXIT_FAILURE;
    }

    string str;
    uint32_t sum = 0;
    while (getline(iFile, str)) {
        uint32_t firstStart, firstEnd, secondStart, secondEnd;
        std::sscanf(str.c_str(), "%u-%u,%u-%u", &firstStart, &firstEnd, &secondStart, &secondEnd);
        if ((firstStart >= secondStart && firstEnd <= secondEnd) || (secondStart >= firstStart && secondEnd <= firstEnd)) {
            sum++;
        }
    }

    cout << sum << endl;

    return EXIT_SUCCESS;
}
