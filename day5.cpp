#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <set>
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
    } // else if (line != "") {
    //   std::uint64_t id{static_cast<uint64_t>(std::stoll(line))};

    //   for (auto range : ranges) {
    //     if (id >= range.first && id <= range.second) {
    //       count++;
    //       break;
    //     }
    //   }
    // }
  }
  std::vector<std::pair<std::uint64_t, std::uint64_t>> ranges_without_overlap{};
  std::sort(ranges.begin(), ranges.end());
  for (auto range : ranges) {
    for (auto range_no_overlap : ranges_without_overlap) {
      if (range.first >= range_no_overlap.first &&
          range.first <= range_no_overlap.second) {
        range.first = range_no_overlap.second + 1;
      }
      if (range.second >= range_no_overlap.first &&
          range.second <= range_no_overlap.second) {
        range.second = range_no_overlap.first - 1;
      }
    }
    if (range.first <= range.second) {
      ranges_without_overlap.push_back(range);
    }
  }
  std::uint64_t sum{0};
  std::sort(ranges_without_overlap.begin(), ranges_without_overlap.end());
  for (auto range_no_overlap : ranges_without_overlap) {
    std::cout << range_no_overlap.first << " " << range_no_overlap.second
              << std::endl;
    sum += (range_no_overlap.second - range_no_overlap.first) + 1;
  }
  std::cout << sum << std::endl;
  return 0;
}