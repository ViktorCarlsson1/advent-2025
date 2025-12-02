#include <cmath>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
// Part 1
std::set<std::size_t> findInvalidIds(std::string start, std::string end,
                                     std::size_t n) {
  std::set<std::size_t> to_add_{};
  std::size_t number_of_digits_{end.length()};

  std::size_t check_start_{static_cast<std::size_t>(std::stoll(start))};
  std::size_t check_end_{static_cast<std::size_t>(std::stoll(end))};

  for (std::size_t i{check_start_}; i < check_end_; i++) {
    std::size_t number_of_digits_{std::to_string(i).length()};
    auto const oom{std::max(number_of_digits_ / n, 1UL)};
    if (i < 10 || std::to_string(i).at(number_of_digits_ - oom) == '0') {
      continue;
    }
    std::set<std::size_t> parts{};
    std::size_t const temp{static_cast<std::size_t>(std::pow(10, oom))};
    std::size_t copy{i};
    std::size_t count{0};

    while (copy > 0) {
      if (std::to_string(copy).length() < number_of_digits_ - (oom * count)) {
        parts.insert(1);
      }
      parts.insert(copy % temp);
      copy /= temp;
      count++;
    }

    if (parts.size() == 1) {
      std::cout << i << '\n';
      to_add_.insert(i);
    }
  }
  return to_add_;
}

// Part 2
std::set<std::size_t> getRange(std::size_t n) {
  std::set<std::size_t> res{};
  for (std::size_t i{2}; i <= ((n / 2) + 1); i++) {
    res.insert(i);
  }
  res.insert(n);
  return res;
}
// std::size_t findInvalidIdMultiple(std::string start, std::string end) {
//   std::size_t to_add_{0};
//   std::size_t number_of_digits_{start.length()};

//   std::size_t check_start_{static_cast<std::size_t>(std::stoll(start))};
//   std::size_t check_end_{static_cast<std::size_t>(std::stoll(end))};

//   for (std::size_t i : getFactors(number_of_digits_)) {
//     std::cout << start << " " << std::pow(10, i) - 1 << std::endl;
//     to_add_ += findInvalidId(
//         std::to_string(static_cast<std::size_t>(std::pow(10, i - 1))),
//         std::to_string(static_cast<std::size_t>(std::pow(10, i)) - 1U));
//   }

//   return to_add_;
// }

int main() {
  static constexpr char kDelimiter{','};
  static constexpr char kSecondDelimiter{'-'};

  std::ifstream input("input/day2.txt");
  std::string line{};
  std::getline(input, line);
  std::string token{line.substr(0, line.find(kDelimiter))};
  std::size_t sum{0};
  std::set<std::size_t> to_add{};

  while (token != "") {
    std::cout << token << std::endl;
    auto pos{line.find(kDelimiter)};
    line.erase(0, pos == std::string::npos ? 10 : pos + 1);

    std::string first_id{token.substr(0, token.find(kSecondDelimiter))};
    std::string second_id{token.substr(token.find(kSecondDelimiter) + 1)};

    for (std::size_t i : getRange(second_id.length())) {
      std::cout << "i: " << i << " adds:" << std::endl;
      auto j{findInvalidIds(first_id, second_id, i)};
      to_add.insert(j.begin(), j.end());
      //   sum += j;
    }
    // sum += findInvalidId(first_id, second_id, 2);

    token = pos == std::string::npos ? line.substr(0)
                                     : line.substr(0, line.find(kDelimiter));
  }

  std::cout << "Adding...\n";
  for (auto it{to_add.begin()}; it != to_add.end(); it++) {
    std::cout << *it << '\n';
    sum += *it;
  }

  std::cout << "The sum is: " << sum << std::endl;

  return 0;
}