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

struct Instruction {
    uint32_t amount;
    uint32_t from;
    uint32_t to;
};

void addIf(const char *str, size_t index, vector<vector<char> > &stacks) {
    if (str[0] == '[') {
        stacks.at(index).push_back(str[1]);
    }
}
void printStack(const vector<vector<char> > &stacks) {
    for (auto i : stacks) {
        for (auto j : i) {
            cout << j;
        }
        cout << endl;
    }
}

int main() {
   ifstream iFile(INPUT_FILE);
    if (!iFile.is_open()) {
        return EXIT_FAILURE;
    }

    vector<vector<char> > stacks;

    string str;
    while (getline(iFile, str)) {
        istringstream ss(str);

        // Init stacks the first time
        if (stacks.size() == 0) {
            for (uint32_t i = 0; i < std::ceil(str.size() / 4.); i++) {
                stacks.push_back({});
            }
        }

        char buffer[4];

        size_t index = 0;
        while (ss.good()) {
            ss.read(buffer, 3);
            addIf(buffer, index, stacks);

            // Skip ' '
            if (ss.good()) {
                ss.read(buffer, 1);
            }

            index++;
        }

        if (iFile.peek() == '\n') {
            break;
        }
    }

    printStack(stacks);

    for (auto i = stacks.begin(); i != stacks.end(); i++) {
        std::reverse(i->begin(), i->end());
    }

    vector<Instruction> instructions;
    // Skip one line
    getline(iFile, str);

    while (getline(iFile, str)) {
        Instruction instr;
        std::sscanf(str.c_str(), "move %u from %u to %u", &instr.amount, &instr.from, &instr.to);
        instructions.push_back(instr);
    }


    vector<char> buffer;
    for (auto instr : instructions) {
        cout << instr.amount << " from " << instr.from << " to " << instr.to << endl;
        for (uint32_t i = instr.amount; i > 0; i--) {
            buffer.push_back(stacks.at(instr.from - 1).back());
            stacks.at(instr.from - 1).pop_back();
        }
        while (buffer.size() > 0) {
            stacks.at(instr.to - 1).push_back(buffer.back());
            buffer.pop_back();
        }
    }

    for (auto i : stacks) {
        cout << i.back();
    }
    cout << endl;

    return EXIT_SUCCESS;
}
