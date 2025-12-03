#include <cctype>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
int main() {
  std::ifstream input("input/day3.txt");
  std::size_t sum{0};
  for (std::string line; std::getline(input, line);) {
    char largest{'0'};
    std::size_t joltage{0};
    std::size_t pos{0};
    for (std::size_t i{0}; i < line.length() - 1; i++) {
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
    joltage = (largest - '0') * 10;
    largest = '0';
    for (std::size_t i{pos + 1}; i < line.length(); i++) {
      if (!std::isdigit(line[pos], std::locale{})) {
        continue;
      }
      if (line[i] > largest) {
        largest = line[i];
      }
      if (largest == '9') {
        break;
      }
    }
    joltage += largest - '0';
    sum += joltage;
  }
  std::cout << "Sum: " << sum << std::endl;
  return 0;
}