#include "statistics.hpp"

bool Stats::collectStatistics() {

  std::ifstream statistics(DATA_FILE_PATH, std::ifstream::out);
  if (statistics.fail()) {
    return false;
  }

  statistics >> bestScore >> gameCount >> winCount >> totalMoveCount >>
      totalDuration;
  return true;
}
