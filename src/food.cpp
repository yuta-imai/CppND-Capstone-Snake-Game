#include <iostream>
#include "food.h"

Food::Food(int grid_width, int grid_height, std::shared_ptr<Snake> snake_)
    : snake(snake_),
      engine(dev()),
      random_w(0, grid_width),
      random_h(0, grid_height)  {
    threads.emplace_back(std::thread(&Food::RandomLocationUpdate, this));
  }

Food::~Food(){
    std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
        t.join();
    });
  }

void Food::TerminateGame() {
  terminate_game = true;
}

void Food::UpdateLocation() {
  std::cout << "Updating food location!" << std::endl;
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake->SnakeCell(x, y)) {
      std::lock_guard<std::mutex> lock(mtx);
      location.x = x;
      location.y = y;
      return;
    }
  }
}

bool Food::IsAt(int target_x, int target_y){
  std::lock_guard<std::mutex> lock(mtx);
  return (location.x == target_x && location.y == target_y);
}

SDL_Point Food::GetLocation() {
  std::lock_guard<std::mutex> lock(mtx);
  SDL_Point result = location;
  return result;
}

void Food::RandomLocationUpdate() {
  const int phase_duration_from  = 4;
  const int phase_duration_to    = 6;
  std::uniform_int_distribution<int>  distr(phase_duration_from, phase_duration_to);
  std::chrono::steady_clock::time_point cycledAt = std::chrono::steady_clock::now();
  while(true)
    {
        {
          std::lock_guard<std::mutex> lock(mtx);
          if(terminate_game){
            return;
          }
        }
        std::chrono::steady_clock::time_point now =  std::chrono::steady_clock::now();
        int elapsedSinceLastCycle = std::chrono::duration_cast<std::chrono::seconds>(now - cycledAt).count();
        int cycleDurationInSecond = distr(engine);

        if(elapsedSinceLastCycle >= cycleDurationInSecond)
        {
          UpdateLocation();
          cycledAt = std::chrono::steady_clock::now();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}