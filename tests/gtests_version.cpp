#include <gtest/gtest.h>

#include <fstream>

#include <lib.h>
#include <sort_ip.hpp>
#include <tuple>

// TEST(gtest, test_version) { ASSERT_LT(version(), 100); }

TEST(gtest, read_file) {

  std::ifstream in("ip_filter.tsv");

  Object obj;

  try {

    if (in.is_open()) {
      std::string line;

      while (std::getline(in, line, '\n')) {
        obj.push_back(line);
      }

      auto t = std::make_tuple(0, 0, 0, 0);

      ASSERT_EQ(obj[1], t);
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    in.close();
  }
  in.close();
}