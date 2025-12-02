#include <cmath>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

std::size_t findInvalidId(std::string start, std::string end) {
  std::size_t to_add_{0};
  std::size_t number_of_digits_{start.length()};

  std::size_t check_start_{static_cast<std::size_t>(std::stoll(start))};
  std::size_t check_end_{static_cast<std::size_t>(std::stoll(end))};

  if (start.length() % 2 == 1 && end.length() % 2 == 1 &&
      start.length() == end.length()) {
    return to_add_;
  }
  if (start.length() % 2 == 1) {
    check_start_ = std::pow(10, start.length());
    number_of_digits_ = {end.length()};
  }
  if (end.length() % 2 == 1) {
    check_end_ = std::pow(10, end.length() - 1);
  }

  for (std::size_t i{check_start_}; i < check_end_; i++) {
    std::size_t const temp{
        static_cast<std::size_t>(std::pow(10, number_of_digits_ / 2))};

    std::size_t const remainder{i % temp};
    std::size_t const top{i / temp};

    if (top == remainder) {
      to_add_ += i;
    }
  }
  return to_add_;
}

int main() {
  static constexpr char kDelimiter{','};
  static constexpr char kSecondDelimiter{'-'};

  std::ifstream input("input/day2.txt");
  std::string line{};
  std::getline(input, line);
  std::string token{line.substr(0, line.find(kDelimiter))};
  std::size_t sum{0};

  while (token != "") {
    auto pos{line.find(kDelimiter)};
    line.erase(0, pos == std::string::npos ? 10 : pos + 1);

    std::string first_id{token.substr(0, token.find(kSecondDelimiter))};
    std::string second_id{token.substr(token.find(kSecondDelimiter) + 1)};

    sum += findInvalidId(first_id, second_id);

    token = pos == std::string::npos ? line.substr(0)
                                     : line.substr(0, line.find(kDelimiter));
  }

  std::cout << "The sum is: " << sum << std::endl;

  return 0;
}