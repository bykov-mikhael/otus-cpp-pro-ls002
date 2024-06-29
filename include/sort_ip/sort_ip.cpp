#include <algorithm>
#include <iostream>
#include <tuple>

#include "sort_ip.hpp"

Object::Object() { ; }

Object::~Object() { ; }

auto Object::extract_element(std::string sSourceString) {

  ip_addrs RetVal;

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

void Object::push_back(std::string &sStrLine) {
  m_ip_addrs_pool.push_back(extract_element(sStrLine));
}

void Object::sort() {
  std::sort(m_ip_addrs_pool.begin(), m_ip_addrs_pool.end(), IPAddrLE);
}

bool Object::IPAddrLE(ip_addr ConditionValueL, ip_addr ConditionValueR) {

  if (std::get<0>(ConditionValueL) > std::get<0>(ConditionValueR)) {
    return true;
  }

  if (std::get<0>(ConditionValueL) == std::get<0>(ConditionValueR)) {
    if (std::get<1>(ConditionValueL) > std::get<1>(ConditionValueR)) {
      return true;
    }
  }

  if (std::get<1>(ConditionValueL) == std::get<1>(ConditionValueR)) {
    if (std::get<2>(ConditionValueL) > std::get<2>(ConditionValueR)) {
      return true;
    }
  }

  if (std::get<2>(ConditionValueL) == std::get<2>(ConditionValueR)) {
    if (std::get<3>(ConditionValueL) > std::get<3>(ConditionValueR)) {
      return true;
    }
  }

  if (std::get<3>(ConditionValueL) == std::get<3>(ConditionValueR)) {
    return true;
  }

  return false;
}

void Object::print_element() {

  for (auto pos : m_ip_addrs_pool) {
    std::cout << std::get<0>(pos) << "." << std::get<1>(pos) << "."
              << std::get<2>(pos) << "." << std::get<3>(pos) << std::endl;
  }
}

void Object::print_element(int iOct1) {

  for (auto pos : m_ip_addrs_pool) {
    if (std::get<0>(pos) == iOct1) {
      std::cout << std::get<0>(pos) << "." << std::get<1>(pos) << "."
                << std::get<2>(pos) << "." << std::get<3>(pos) << std::endl;
    }
  }
}

void Object::print_element(int iOct1, int iOct2) {

  for (auto pos : m_ip_addrs_pool) {
    if (std::get<0>(pos) == iOct1 && std::get<1>(pos) == iOct2) {
      std::cout << std::get<0>(pos) << "." << std::get<1>(pos) << "."
                << std::get<2>(pos) << "." << std::get<3>(pos) << std::endl;
    }
  }
}

void Object::print_element(int iOct1, int iOct2, int iOct3, int iOct4) {

  for (auto pos : m_ip_addrs_pool) {
    if (std::get<0>(pos) == iOct1 || std::get<1>(pos) == iOct2 ||
        std::get<2>(pos) == iOct3 || std::get<3>(pos) == iOct4) {
      std::cout << std::get<0>(pos) << "." << std::get<1>(pos) << "."
                << std::get<2>(pos) << "." << std::get<3>(pos) << std::endl;
    }
  }
}

ip_addr Object::operator[](const int iPos) const {

  return m_ip_addrs_pool.at(iPos);
}