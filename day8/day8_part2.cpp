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
    const vector<pair<int8_t, int8_t> > directions = {
        { -1, 0},
        { 1, 0 },
        { 0, -1 },
        { 0, 1 },
    };

    uint32_t highScore = 0;
    for (size_t y = 1; y < height - 1 ; y++) {
        for (size_t x = 1; x < width - 1; x++) {
            uint32_t score = 1;
            const uint32_t currentHeight = map.at(y).at(x);
            for (auto direction : directions) {
                size_t currentX = x;
                size_t currentY = y;
                uint32_t visibleTrees = 0;
                while (currentX > 0 && currentY > 0 && currentX < width - 1 && currentY < height - 1) {
                    currentX += direction.first;
                    currentY += direction.second;
                    visibleTrees++;
                    const uint32_t height = map.at(currentY).at(currentX);

                    if (height >= currentHeight) {
                        score *= visibleTrees;
                        visibleTrees = 0;
                        break;
                    }
                }
                if (visibleTrees != 0) {
                    score *= visibleTrees;
                }
            }

            if (score > highScore) {
                highScore = score;
            }
        }

    }

    cout << highScore << endl;

    return EXIT_SUCCESS;
}
