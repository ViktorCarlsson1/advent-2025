#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  static constexpr std::int32_t kMaxPosition{100};
  static constexpr std::int32_t kStartPosition{50};
  static constexpr std::int32_t kGoalPosition{0};
  std::ifstream input("input/day1.txt");

  std::int32_t position{kStartPosition};
  std::string current_direction{"R"};
  std::size_t password{0};

  std::cout << "Computing password..." << std::endl;

  for (std::string line; std::getline(input, line);) {
    std::string const direction{line.substr(0, 1)};
    std::int32_t amount{static_cast<std::int32_t>(std::stoi(line.substr(1)))};

    // If direction is reversed, reverse position in order to keep going in a
    // positive direction.
    if (direction != current_direction) {
      position = (kMaxPosition - position) % kMaxPosition;
      current_direction = direction;
    }

    position += amount;

    // Password is amount of times dial has passed 0.
    password += abs(position) / 100;
    position = position % 100;
  }
  std::cout << "The password is: " << password << std::endl;
  return 0;
}