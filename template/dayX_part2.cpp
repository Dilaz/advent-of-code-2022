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

const char *INPUT_FILE = "test_input.txt";

int main() {
   ifstream iFile(INPUT_FILE);
    if (!iFile.is_open()) {
        return EXIT_FAILURE;
    }

    string str;
    while (getline(iFile, str)) {
    }


    return EXIT_SUCCESS;
}
