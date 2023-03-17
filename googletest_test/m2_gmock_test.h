//
// Created by shecannotsee on 2023/3/17.
//

#ifndef GOOGLETEST_TEST_GOOGLETEST_TEST_M2_GMOCK_TEST_H_
#define GOOGLETEST_TEST_GOOGLETEST_TEST_M2_GMOCK_TEST_H_

#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace m2_gmock_test {

class function {
 public:
  virtual int get_number_8() const = 0;
  virtual void do_this(int n) = 0;
};

class mock_function : public function {
 public:
  MOCK_METHOD(int, get_number_8, (), (const, override));
  MOCK_METHOD(void, do_this, (int n), (override));
};

TEST(mock, function_test) {
  mock_function temp;/* set action */ {
    EXPECT_CALL(temp, get_number_8())
      .WillOnce(testing::Return(8));
  };

  EXPECT_EQ(8,temp.get_number_8());
};


int main(int argc,char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
};

};// namespace m2_gmock_test

#endif //GOOGLETEST_TEST_GOOGLETEST_TEST_M2_GMOCK_TEST_H_
