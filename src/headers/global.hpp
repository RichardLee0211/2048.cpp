#ifndef GLOBAL_H
#define GLOBAL_H

/* PATH setting */
#define STATISTICS_PATH "./data/statistics.txt"
#define PREVIOUS_GAME_PATH "./data/previousGame"
#define DATA_FILE_PATH "./data/statistics.txt"
#define SCORE_PATH "./data/scores.txt"

#include <cstdlib>
#include <iomanip>
#include <iostream>

typedef unsigned long long ull;

void getInput(char &);

void endl(int n = 1);

void clearScreen();

std::string secondsFormat(double);


#endif
