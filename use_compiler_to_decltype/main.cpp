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
  // g++ 9.4.0: [error: aggregate ‘type_display<int> x_type’ has incomplete type and cannot be defined]
  type_display<decltype(x)> x_type;
  // g++ 9.4.0: [error: aggregate ‘type_display<const int*> y_type’ has incomplete type and cannot be defined]
  type_display<decltype(y)> y_type;

  return 0;
};
