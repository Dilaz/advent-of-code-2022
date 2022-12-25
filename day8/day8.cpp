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
using std::pair;
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

    set<pair<uint32_t, uint32_t> > visibleTrees;
    vector<vector<uint32_t> > map;
    string str;
    while (getline(iFile, str)) {
        vector<uint32_t> row;
        for (char chr : str) {
            row.push_back(chr - '0');
        }

        map.push_back(row);
    }

    const size_t height = map.size();
    const size_t width = map.at(0).size();
    uint32_t max = 0;
    const vector<pair<uint32_t, uint32_t> > directions = {
        { -1, 0},
        { 1, 0 },
        { 0, -1 },
        { 0, 1 },
    };

    for (size_t y = 1; y < height - 1 ; y++) {
        for (size_t x = 1; x < width - 1; x++) {
            uint32_t score = 1;
            for (auto direction : direction) {
                size_t currentX = x;
                size_t currentY = y;
                const uint32_t currentHeight = map.at(y).at(x);
                uint32_t visibleTrees = 0;
                while (x > 0 && y > 0 && x < width - 1 && y < height - 1) {
                    currentX += direction.first;
                    currentY += direction.second;
                    visibleTrees++;
                    const uint32_t height = map.at(currentY).at(currentX);

                    if (height >= currentHeight) {
                        score *= visibleTrees;
                        break;
                    }
                }
            }

            cout << score << endl;
        }
    }

    return EXIT_SUCCESS;
}
