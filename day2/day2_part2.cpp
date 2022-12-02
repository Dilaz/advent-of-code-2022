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
};

const std::map<char, Result> RESULT_MAP {
    {'X', Result::LOSE},
    {'Y', Result::DRAW},
    {'Z', Result::WIN},
};

RPS getCondition(RPS first, Result result) {
    if (result == Result::DRAW) {
        return first;
    }

    if (result == Result::WIN) {
        switch (first) {
            case RPS::Rock:
                return RPS::Paper;
            case RPS::Paper:
                return RPS::Scissors;
            case RPS::Scissors:
                return RPS::Rock;
        }
    }

    // Losing condition
    switch (first) {
    case RPS::Rock:
        return RPS::Scissors;
    case RPS::Paper:
        return RPS::Rock;
    case RPS::Scissors:
        return RPS::Paper;
    }

    return first;
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

        const RPS first = PLAY_CHARS.at(firstChr);
        const Result result = RESULT_MAP.at(secondChr);
        const RPS second = getCondition(first, result);
        score += SCORES.at(second);

        score += result;
    }

    cout << score << endl;

    return EXIT_SUCCESS;
}
