#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  static constexpr std::int32_t kStartPosition{50};
  static constexpr std::int32_t kGoalPosition{0};
  std::ifstream input("input/day1.txt");

  std::int32_t position{kStartPosition};
  std::size_t password{0};

  std::cout << "Computing password..." << std::endl;

  for (std::string line; std::getline(input, line);) {
    std::string const direction{line.substr(
        0, 1)}; // Should be "L" for left or "R" for right, otherwise invalid.
    std::int32_t amount{static_cast<std::int32_t>(std::stoi(line.substr(1)))};

    if (direction == "L") {
      amount *= -1;
    } else if (direction != "R") {
      continue; // Invalid direction
    }

    position += amount;

    position = position % 100;

    // Password is amount of times dial has hit 0.
    if (position == kGoalPosition) {
      password++;
    }
  }
  std::cout << "The password is: " << password << std::endl;
  return 0;
}