#include <cctype>
#include <cmath>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
int main() {
  std::ifstream input("input/day3.txt");
  std::size_t sum{0};
  static constexpr std::size_t kIterations{12};
  for (std::string line; std::getline(input, line);) {
    std::size_t pos{0};
    for (std::size_t iteration{0}; iteration < kIterations; iteration++) {
      std::size_t const digits_remaining{kIterations - iteration - 1};
      char largest{'0'};
      for (std::size_t i{pos}; i < line.length() - digits_remaining; i++) {
        if (!std::isdigit(line[i], std::locale{})) {
          continue;
        }
        if (line[i] > largest) {
          largest = line[i];
          pos = i;
        }
        if (largest == '9') {
          break;
        }
      }
      sum += (largest - '0') * std::pow(10, digits_remaining);
      pos++;
    }
  }
  std::cout << "Sum: " << sum << std::endl;
  return 0;
}