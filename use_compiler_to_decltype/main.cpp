//
// Created by shecannotsee on 23-5-18.
//
#include <vector>

template<typename T>
class type_display;

int main() {
  const int value = 10;
  auto x = value;
  auto y = &value;
  type_display<decltype(x)> x_type;
  type_display<decltype(y)> y_type;

  return 0;
};
