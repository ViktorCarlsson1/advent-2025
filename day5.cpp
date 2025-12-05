#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  std::ifstream input("input/day5.txt");
  std::vector<std::pair<std::uint64_t, std::uint64_t>> ranges{};
  std::size_t count{0};
  for (std::string line; std::getline(input, line);) {
    auto delimiter_pos{line.find('-')};
    if (delimiter_pos != std::string::npos) {
      ranges.push_back(
          std::make_pair(std::stoll(line.substr(0, delimiter_pos)),
                         std::stoll(line.substr(delimiter_pos + 1))));
    } else if (line != "") {
      std::uint64_t id{static_cast<uint64_t>(std::stoll(line))};

      for (auto range : ranges) {
        if (id >= range.first && id <= range.second) {
          count++;
          break;
        }
      }
    }
  }
  std::cout << count << std::endl;
  return 0;
}