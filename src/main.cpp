#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>  // string
#include "controller.h"
#include "game.h"
#include "renderer.h"

std::string return_current_time_and_date()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

void OutputResult(int gameScore, int snakeSize)
{

  std::string now = return_current_time_and_date();

  std::cout << "Game has terminated successfully! " << now << "\n";
  std::cout << "Score: " << gameScore << "\n";
  std::cout << "Size: " << snakeSize << "\n";

  std::ofstream resultFile("./result",std::ofstream::app);
  if(resultFile) {
    resultFile << "Game has terminated successfully! " << now << "\n";
    resultFile << "Score: " << gameScore << "\n";
    resultFile << "Size: " << snakeSize << "\n";
  }
}

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  OutputResult(game.GetScore(), game.GetSize());
  return 0;
}