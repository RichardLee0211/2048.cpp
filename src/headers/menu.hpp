#ifndef MENU_H
#define MENU_H

#include "game.hpp"
#include "global.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>


constexpr auto title_card_2048 = R"(
   /\\\\\\\\\          /\\\\\\\                /\\\         /\\\\\\\\\
  /\\\///////\\\      /\\\/////\\\            /\\\\\       /\\\///////\\\
  \///      \//\\\    /\\\    \//\\\         /\\\/\\\      \/\\\     \/\\\
             /\\\/    \/\\\     \/\\\       /\\\/\/\\\      \///\\\\\\\\\/
           /\\\//      \/\\\     \/\\\     /\\\/  \/\\\       /\\\///////\\\
         /\\\//         \/\\\     \/\\\   /\\\\\\\\\\\\\\\\   /\\\      \//\\\
        /\\\/            \//\\\    /\\\   \///////////\\\//   \//\\\      /\\\
        /\\\\\\\\\\\\\\\   \///\\\\\\\/              \/\\\      \///\\\\\\\\\/
        \///////////////      \///////                \///         \/////////
  )";

class Menu {

private:
  void startGame();
  void showScores();
  void printMenu();
  void input(int err);
  void continueGame();

public:
  void startMenu(int err = 0);
};

void drawAscii();

#endif
