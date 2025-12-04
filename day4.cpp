#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  static constexpr std::size_t kSize{137};
  std::ifstream input("input/day4.txt");
  std::string padding(kSize, '.');
  std::vector<std::string> array{padding};
  std::size_t total{0};
  for (std::string line; std::getline(input, line);) {
    std::string input = ".";
    input.append(line).append(".");
    array.push_back(input);
  }
  array.push_back(padding);
  std::size_t changed{0};
  do {
    changed = 0;
    for (std::size_t i{1}; i < kSize - 1; i++) {
      for (std::size_t j{1}; j < kSize - 1; j++) {
        if (array.at(i).at(j) == '@') {
          std::size_t count{0};
          for (std::int32_t k{-1}; k <= 1; k++) {
            for (std::int32_t l{-1}; l <= 1; l++) {
              if (array.at(i + k).at(j + l) == '@') {
                count++;
              }
            }
          }
          if (count < 5) {
            total++;
            changed++;
            array.at(i).at(j) = 'x';
          }
        }
      }
    }
  } while (changed != 0);
  std::cout << total << std::endl;
  return 0;
}