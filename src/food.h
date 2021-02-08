#ifndef FOOD_H
#define FOOD_H

#include <mutex>
#include <random>
#include <thread>
#include <vector>
#include "SDL.h"
#include "snake.h"

class Food
{
public:
  Food(int, int, std::shared_ptr<Snake>);
  ~Food();
  void TerminateGame();
  void UpdateLocation();
  bool IsAt(int, int);
  SDL_Point GetLocation();

private:
  SDL_Point location;
  std::shared_ptr<Snake> snake;
  std::vector<std::thread> threads;
  std::mutex mtx;
  bool terminate_game{false};

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  void RandomLocationUpdate();
};
#endif