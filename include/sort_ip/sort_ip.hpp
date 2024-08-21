#pragma once

#include <iostream>
#include <vector>

using ip_addr = std::tuple<int, int, int, int>;
using ip_addrs = std::vector<ip_addr>;

class Object {
public:
  Object();
  ~Object();

  void push_back(std::string &sStrLine);

  void sort();

  void print_element();
  void print_element(int iOct1);
  void print_element(int iOct1, int iOct2);
  void print_element(int iOct1, int iOct2, int iOct3, int iOct4);

  ip_addr operator[](const int iPos) const;

private:
  ip_addrs m_ip_addrs_pool;

  auto extract_element(std::string sSourceString);

  static bool IPAddrLE(ip_addr ConditionValueL, ip_addr ConditionValueR);
};