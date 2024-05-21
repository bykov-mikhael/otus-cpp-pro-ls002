#define BOOST_TEST_MODULE btest

#include <boost/test/unit_test.hpp>

#include "lib.h"

BOOST_AUTO_TEST_SUITE(btest)

BOOST_AUTO_TEST_CASE(test_version) { BOOST_CHECK(version() != 100); }

BOOST_AUTO_TEST_SUITE_END()