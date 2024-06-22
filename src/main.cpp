#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using ip_addr = std::tuple<int, int, int, int>;
using ip_addrs = std::vector<ip_addr>;

enum sort_type { LE = 0, LT = 1, EQ = 2, GT = 3, GE = 4 };

ip_addrs ip_addrs_pool;

auto extract_element(std::string sSourceString) {

  std::vector<int> iReturnValue;
  std::string sReturnString{};

  for (char symbol : sSourceString) {
    switch (symbol) {
    case '\t':
      iReturnValue.push_back(std::stoi(sReturnString));
      break;
    case '.':
      iReturnValue.push_back(std::stoi(sReturnString));
      sReturnString.erase();
      break;
    default:
      sReturnString.push_back(symbol);
      break;
    }
  }
  return std::make_tuple(iReturnValue[0], iReturnValue[1], iReturnValue[2],
                         iReturnValue[3]);
}

bool IPAddrGE(ip_addr ConditionValueL, ip_addr ConditionValueR) {

  return std::get<0>(ConditionValueL) > std::get<0>(ConditionValueR);
}

/*
1.10.1.1
1.2.1.1
1.1.1.1
1.1.1.2
12.155.92.10
12.155.92.10
*/

bool IPAddrLE(ip_addr ConditionValueL, ip_addr ConditionValueR) {

  if (std::get<0>(ConditionValueL) < std::get<0>(ConditionValueR)) {
    return true;
  } else if (std::get<1>(ConditionValueL) < std::get<1>(ConditionValueR)) {
    return true;
  } else if (std::get<2>(ConditionValueL) < std::get<2>(ConditionValueR)) {
    return true;
  }
  if (std::get<3>(ConditionValueL) < std::get<3>(ConditionValueR)) {
    return true;
  }

  if (std::get<0>(ConditionValueL) == std::get<0>(ConditionValueR)) {
    if (std::get<1>(ConditionValueL) == std::get<1>(ConditionValueR)) {
      if (std::get<2>(ConditionValueL) == std::get<2>(ConditionValueR)) {
        if (std::get<3>(ConditionValueL) == std::get<3>(ConditionValueR)) {
          return false;
        }
      }
    }
  }
  return false;
}

void print_element(ip_addrs IPAddr) {

  for (auto pos : IPAddr) {
    std::cout << std::get<0>(pos) << "." << std::get<1>(pos) << "."
              << std::get<2>(pos) << "." << std::get<3>(pos) << std::endl;
  }
}

void print_element(ip_addrs IPAddr, int iOct1, int iOct2) {

  for (auto pos : IPAddr) {
    if (std::get<0>(pos) == iOct1 && std::get<1>(pos) == iOct2) {
      std::cout << std::get<0>(pos) << "." << std::get<1>(pos) << "."
                << std::get<2>(pos) << "." << std::get<3>(pos) << std::endl;
    }
  }
}

void print_element(ip_addrs IPAddr, int iAnyOct) {

  for (auto pos : IPAddr) {
    if (std::get<0>(pos) == iAnyOct || std::get<1>(pos) == iAnyOct ||
        std::get<2>(pos) == iAnyOct || std::get<3>(pos) == iAnyOct) {
      std::cout << std::get<0>(pos) << "." << std::get<1>(pos) << "."
                << std::get<2>(pos) << "." << std::get<3>(pos) << std::endl;
    }
  }
}

int main() {

  std::ifstream in("ip_filter.tsv");

  try {

    if (in.is_open()) {
      std::string line;

      while (std::getline(in, line, '\n')) {
        ip_addrs_pool.push_back(extract_element(line));
      }

      // std::cout << "0. Полный список адресов без сортировки. Одна
      // строка - "
      //              "один адрес."
      //           << std::endl;

      // print_element(ip_addrs_pool);

      std::cout << "1. Полный список адресов после сортировки. Одна строка - "
                   "один адрес."
                << std::endl;

      std::sort(ip_addrs_pool.begin(), ip_addrs_pool.end(), IPAddrLE);

      print_element(ip_addrs_pool);

      std::cout << "2. Сразу следом список адресов, первый байт которых равен "
                   "1. Порядок сортировки не меняется. Одна строка - один "
                   "адрес. Списки ничем не разделяются."
                << std::endl;

      print_element(ip_addrs_pool, 1);

      std::cout << "3. Сразу продолжается список адресов, первый байт которых "
                   "равен 46, а второй 70. Порядок сортировки не меняется. "
                   "Одна строка - один адрес. Списки ничем не разделяются."
                << std::endl;

      print_element(ip_addrs_pool, 46, 70);

      std::cout << "4. Сразу продолжается список адресов, любой байт которых "
                   "равен 46. Порядок сортировки не меняется. Одна строка - "
                   "один адрес. Списки ничем не разделяются."
                << std::endl;

      print_element(ip_addrs_pool, 46);
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    in.close();
  }

  in.close();
  return 0;
}