//
// Created by shecannotsee on 23-12-25.
//

#include "global_test_set.h"

namespace t2_gmock_easy {

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

}// namespace t2_gmock_easy

TEST(t2_gmock_easy, function_test) {
  t2_gmock_easy::mock_function temp;/* set action */ {
    EXPECT_CALL(temp, get_number_8())
      .WillOnce(testing::Return(8));
  };

  EXPECT_EQ(8,temp.get_number_8());
}
