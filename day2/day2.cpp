#include <cstdlib>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::getline;
#include <fstream>
using std::ifstream;
#include <map>
using std::map;
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

const uint8_t LOSE_SCORE = 0;
const uint8_t DRAW_SCORE = 3;
const uint8_t WIN_SCORE = 6;

enum RPS {
    Rock, Paper, Scissors,
};

enum Result {
    LOSE = LOSE_SCORE,
    DRAW = DRAW_SCORE,
    WIN = WIN_SCORE,
};

const std::map<char, uint8_t> SCORES {
    {RPS::Rock, 1},
    {RPS::Paper, 2},
    {RPS::Scissors, 3},
};

const std::map<char, RPS> PLAY_CHARS {
    {'A', RPS::Rock },
    {'B', RPS::Paper, },
    {'C', RPS::Scissors },
    {'X', RPS::Rock },
    {'Y', RPS::Paper },
    {'Z', RPS::Scissors },
};

Result checkResult(RPS first, RPS second) {
    if (first == second) {
        return Result::DRAW;
    }

    if (first == RPS::Rock && second == RPS::Scissors) {
        return Result::WIN;
    } else if (first == RPS::Paper && second == RPS::Rock) {
        return Result::WIN;
    } else if (first == RPS::Scissors && second == RPS::Paper) {
        return Result::WIN;
    }

    return Result::LOSE;
}

int main() {
    ifstream iFile(INPUT_FILE);
    if (!iFile.is_open()) {
        return EXIT_FAILURE;
    }

    string str;
    uint32_t score = 0;
    while (getline(iFile, str)) {
        istringstream ss(str);
        char firstChr;
        ss >> firstChr;
        char secondChr;
        ss >> secondChr;

        cout << firstChr << ' ' << secondChr << endl;

        const RPS first = PLAY_CHARS.at(firstChr);
        const RPS second = PLAY_CHARS.at(secondChr);

        score += SCORES.at(second);

        score += checkResult(second, first);
    }

    cout << score << endl;

    return EXIT_SUCCESS;
}
