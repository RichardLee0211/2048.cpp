log
================================================================================
the total goal: I need to got to demo stage

I could and try to add these features to to 2048.cpp in this hackthon
- [ ] class store and cold start feature
- [ ] Config file to config key bounding
- [ ] Roll back feature
- [ ] Database application??
- [ ] network leaderboard
- [ ]

the code design doc

something I need know more:
- [ ] chrono
- [ ]

```cpp
  std::minstd_rand re;
  std::uniform_int_distribution<> dist;
```

statistics.hpp would be what I need to transfer

how to do this?: in color.hpp
```cpp
    std::cout<<red<<blue
    std::cout<<bold_on
    std::cout<<def
    std::cout << bold_on
                << "  Please enter your name to save this score: " << bold_off;
    endl(3);
```

TODO:
need to creat this own data if it doesn't exist

TODO:
I don't need to select game size

TODO:
it seems to be mess, game is generate in memu...

2048.cpp is the driver main function
game.cpp is the main logic
memu.cpp
scores.cpp for reading and writeing score
statistics.cpp for the top records

and there is onething I don't like, that's
using something.hpp to include everything needed in something.cpp.

in desing pattern, this should be one instance design pattern

statistics and scores are not well designed

this doesn't seem to be managable
```cpp
      std::cout << "  "
                   "┌─────┬────────────────────┬──────────┬──────┬───────┬─────"
                   "─────────┬──────────────┐";
      endl();
      std::cout << "  │ " << bold_on << "No." << bold_off << " │ " << bold_on
                << "Name" << bold_off << "               │ " << bold_on
                << "Score" << bold_off << "    │ " << bold_on << "Won?"
                << bold_off << " │ " << bold_on << "Moves" << bold_off << " │ "
                << bold_on << "Largest Tile" << bold_off << " │ " << bold_on
                << "Duration    " << bold_off << " │";
      endl();
      std::cout << "  "
                   "├─────┼────────────────────┼──────────┼──────┼───────┼─────"
                   "─────────┼──────────────┤";
      endl();
    }

    std::cout << "  │ " << std::setw(2) << size - i << ". │ " << playerName;
    padding(playerName);
    std::cout << " │ " << std::setw(8) << playerScore << " │ " << std::setw(4)
              << won << " │ " << std::setw(5) << moveCount << " │ "
              << std::setw(12) << largestTile << " │ " << std::setw(12)
              << secondsFormat(duration) << " │ ";
    endl();
```

this design...
```cpp
    void Game::saveStats() {
      Stats stats;
      stats.collectStatistics();
      stats.bestScore = stats.bestScore < score ? score : stats.bestScore;
      stats.gameCount++;
      stats.winCount = win ? stats.winCount + 1 : stats.winCount;
```

now, I don't wanna touch this code, leave his logic alone

not a nice solution, but got to make it work

about YCM "Maximum number of diagnostics exceeded."
[here](https://github.com/theodelrieu/dotfiles/blob/master/.ycm_extra_conf.py)
the recommanded [.ycm_extra_config](https://github.com/theodelrieu/dotfiles/blob/master/.ycm_extra_conf.py)

TODO: need more checks??
```cpp
  std::ifstream statistics("../data/statistics.txt");
```

go to check the compter network code
--------------------------------------------------------------------------------

got segmentation fault at the first time I run it


they
================================================================================
they talked about their idea
they named their team
they designed their webpage
they designed the logo
they encounter online API problems

host
================================================================================

get a lot of food

sushi
poptea
bread/sandwiches
cockies
