#include <cstdlib>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::getline;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <cmath>
using std::max;
#include <algorithm>
using std::transform;
using std::back_inserter;
#include <numeric>
using std::accumulate;
using std::max_element;

const char *INPUT_FILE = "input.txt";

int main() {
    ifstream iFile(INPUT_FILE);
    if (!iFile.is_open()) {
        return EXIT_FAILURE;
    }

    string str;
    vector<vector<uint32_t> > elves;
    vector<uint32_t> current;
    // Read the data and save it to a vector
    while (getline(iFile, str)) {
        istringstream ss(str);
        uint32_t weight;
        while (ss >> weight) {
            current.push_back(weight);
        }

        if (iFile.peek() == '\n') {
            // end of this elf
            elves.push_back(current);
            current.clear();
        }
    }

    // Push the last one
    elves.push_back(current);

    vector<int> elfWeights;
    // Calculate total sum of the calories
    transform(elves.begin(), elves.end(), back_inserter(elfWeights), [](auto weights){
        return accumulate(weights.begin(), weights.end(), 0);
    });

    // Print largest element
    cout << *max_element(elfWeights.begin(), elfWeights.end()) << endl;

    return EXIT_SUCCESS;
}
