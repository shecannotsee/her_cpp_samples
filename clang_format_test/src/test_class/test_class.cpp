//
// Created by shecannotsee on 2023/2/9.
//

#include "test_class.h"

test_class::test_class(int data) : data_(data), no_(0) {
  data_ = data;
};

void test_class::set_data(const int& data) noexcept {
  this->data_ = data;
};

int test_class::get_data() {
  return data_;
};
