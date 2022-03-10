#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <fstream>

int main()
{
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  std::string user;
  int score, speed;
  std::ofstream userData;

  userData.open("users.txt", std::ios::app);
  std::cout << "Enter a Username \n";
  std::cin >> user;

  std::cout << "Select desired speed, enter 1 for fast, 2 for slow \n";
  std::cin >> speed;
  

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.setSnakeSpeed(speed);

  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";

  score = game.GetScore();
  userData << user << ',' << score << '\n';

  return 0;
}