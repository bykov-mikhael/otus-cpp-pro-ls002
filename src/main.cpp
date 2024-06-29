#include <cstring>
#include <iostream>
#include <string>

#include <sort_ip.hpp>

int main() {

  Object obj;

  try {

    for (std::string line; std::getline(std::cin, line);) {
      obj.push_back(line);
    }

    std::cout << "0. Полный список адресов без сортировки. Одна строка - "
                 "один адрес."
              << std::endl;

    obj.print_element();

    std::cout << "1. Полный список адресов после сортировки. Одна строка - "
                 "один адрес."
              << std::endl;

    obj.sort();

    obj.print_element();

    std::cout << "2. Сразу следом список адресов, первый байт которых равен "
                 "1. Порядок сортировки не меняется. Одна строка - один "
                 "адрес. Списки ничем не разделяются."
              << std::endl;

    obj.print_element(1);

    std::cout << "3. Сразу продолжается список адресов, первый байт которых "
                 "равен 46, а второй 70. Порядок сортировки не меняется. "
                 "Одна строка - один адрес. Списки ничем не разделяются."
              << std::endl;

    obj.print_element(46, 70);

    std::cout << "4. Сразу продолжается список адресов, любой байт которых "
                 "равен 46. Порядок сортировки не меняется. Одна строка - "
                 "один адрес. Списки ничем не разделяются."
              << std::endl;

    obj.print_element(46, 46, 46, 46);

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}