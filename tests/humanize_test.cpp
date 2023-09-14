#include <humanize.h>
#include <gtest/gtest.h>
#include <iostream>

using namespace std::literals;

TEST(humanize, Duration) {
  EXPECT_EQ(humanize::duration(1.2s), "1.2s");
  EXPECT_EQ(humanize::duration(1.23ms), "1.23ms");
  EXPECT_EQ(humanize::duration(1.23ms / 1000.0), "1.23µs");

  EXPECT_EQ(humanize::duration(0.9s), "0.9s");
  EXPECT_EQ(humanize::duration(0.8ms), "0.8ms");
  EXPECT_EQ(humanize::duration(0.7ms / 1000.0), "0.7µs");
}

TEST(humanize, Bytes) {
  EXPECT_EQ(humanize::bytes(1.5 * humanize::TB), "1.5TiB");
  EXPECT_EQ(humanize::bytes(1.23* humanize::GB), "1.23GiB");
  EXPECT_EQ(humanize::bytes(1.23* humanize::MB), "1.23MiB");
  EXPECT_EQ(humanize::bytes(1.23* humanize::KB), "1.23KiB");
  EXPECT_EQ(humanize::bytes(1.23), "1B");

  EXPECT_EQ(humanize::bytes(0.9 * humanize::TB), "0.9TiB");
  EXPECT_EQ(humanize::bytes(0.9 * humanize::GB), "0.9GiB");
  EXPECT_EQ(humanize::bytes(0.9 * humanize::MB), "0.9MiB");
  EXPECT_EQ(humanize::bytes(0.9 * humanize::KB), "0.899KiB");

  EXPECT_EQ(humanize::bytes(0.09 * humanize::TB), "92.2GiB");
  EXPECT_EQ(humanize::bytes(0.09 * humanize::GB), "92.2MiB");
  EXPECT_EQ(humanize::bytes(0.09 * humanize::MB), "92.2KiB");
  EXPECT_EQ(humanize::bytes(0.09 * humanize::KB), "92B");
}