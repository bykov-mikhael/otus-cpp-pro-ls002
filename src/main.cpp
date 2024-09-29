#include <cstring>
#include <iostream>
#include <sort_ip.hpp>
#include <string>

int main() {
  Object obj;

  try {
    for (std::string line; std::getline(std::cin, line);) {
      obj.push_back(line);
    }

    obj.print_element();

    obj.sort();

    obj.print_element();

    obj.print_element(1);

    obj.print_element(46, 70);

    obj.print_element(46, 46, 46, 46);

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}