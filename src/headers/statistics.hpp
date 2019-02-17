#ifndef STATISTICS_H
#define STATISTICS_H

#include "global.hpp"
#include <fstream>
#include<string>


class Stats {

public:
  bool collectStatistics();
  ull bestScore;
  ull totalMoveCount;
  int gameCount;
  double totalDuration;
  int winCount;
};

#endif
