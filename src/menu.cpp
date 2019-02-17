#include "menu.hpp"

void Menu::startMenu(int err) {

  clearScreen();

  drawAscii();
  std::cout << bold_on << "  Welcome to " << blue << "2048!" << def << bold_off;
  endl(2);
  std::cout << "          1. Play a New Game";
  endl();
  // wenchen: for this hackthon, do not save and continue game
  // std::cout << "          2. Continue Previous Game";
  // endl();
  // std::cout << "          3. View Highscores and Statistics locally";
  // endl(2);
  std::cout << "          z. Ctrl-c to exit";
  endl();

  input(err);
}

void Menu::input(int err) {

  if (err) {
    std::cout << red << "  Invalid input. Please try again." << def;
    endl(2);
  }

  std::cout << "  Enter Choice: ";
  char c;
  std::cin >> c;

  if (std::cin.eof()) {
    std::cout << std::endl;
    exit(EXIT_SUCCESS);
  }

  switch (c) {
  case '1':
    startGame();
    break;
    /*
  case '2':
    continueGame();
    break;
    */
    /*
  case '3':
    showScores();
    break;
    */
  default:
    startMenu(1);
    break;
  }
}

void Menu::startGame() {
  Game g;
  g.startGame();
}

void Menu::continueGame() {
  Game g;
  g.continueGame();
}

void Menu::showScores() {

  Scoreboard s;
  s.printScore();
  s.printStats();
}

void drawAscii() {
  std::cout << green << bold_on << title_card_2048 << bold_off << def;
  endl(3);
}
