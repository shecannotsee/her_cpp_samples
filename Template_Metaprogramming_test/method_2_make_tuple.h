//
// Created by  shecannotsee on 2023/1/14.
//

#ifndef TEMPLATE_METAPROGRAMMING_TEST_METHOD_2_MAKE_TUPLE_H
#define TEMPLATE_METAPROGRAMMING_TEST_METHOD_2_MAKE_TUPLE_H

#include <string>
#include <vector>


namespace method_2_make_tuple {

bool contains(std::string name,std::vector<std::string> t) {
  return false;
}

void main() {
  std::vector<std::string> t{"int","bool","float"};
  contains("double",t);
};

};// namespace method_2_make_tuple

#endif //TEMPLATE_METAPROGRAMMING_TEST_METHOD_2_MAKE_TUPLE_H
