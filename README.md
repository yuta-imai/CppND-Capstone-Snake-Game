# CPPND: Capstone Snake Game Example

This is a my Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

## Work summary

In my project, I made food randomly update its location so the game gets more exciting. To achieve this, I add `Food` class which manages its location and performs random location update by using a thread.

## Work in detail

- `main.cpp`: Made it to write result to a file, not only console.
- `Snake`: Added `IsAlive()` and `PoisonPill()` so we can observe if its alive and let it die without touching member vaiables directly.
- `Food`: As mentioned in summary, this is a representation of food, which manages its location and performs random location update by using a thread.
- `Controller`: Now you can terminate game by `ESC` key.

## vs. Rubrics

### README

- Has README which describes project and work.
### Compiling and Testing
- It compiles.

### Loops, Functions, I/O

- It writes result to a file.
- The project accepts arrow keys and ESC key.

### Object Oriented Programming

- The project uses object oriented programming techniques.
- For `Snake` class, it encapsulates private members and provides clearer methods than having accessed members directly.

### Memory Management

- The project uses smart pointer `shared_ptr` to share `Snake` object among `Game` and `Food`.

### Concurrency

- The project uses `thread` inside `Food` to run random update of its location.
- For safe access to `Food` members from main game thread and thead inside `Food`, the project uses `std::mutex` and `std::lock_guard`.


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.