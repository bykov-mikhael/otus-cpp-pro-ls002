#include <gtest/gtest.h>

#include "lib.h"

TEST(gtest, test_version) { ASSERT_LT(version(), 100); }