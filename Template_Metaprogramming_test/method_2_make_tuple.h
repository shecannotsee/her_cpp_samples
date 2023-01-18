//
// Created by  shecannotsee on 2023/1/14.
//

#ifndef TEMPLATE_METAPROGRAMMING_TEST_METHOD_2_MAKE_TUPLE_H
#define TEMPLATE_METAPROGRAMMING_TEST_METHOD_2_MAKE_TUPLE_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>


namespace method_2_make_tuple {

template<bool condition, typename THEN, typename ELSE>
struct if_;

template<typename THEN, typename ELSE>
struct if_<true, THEN, ELSE> {
  using type = THEN;
};

template<typename THEN, typename ELSE>
struct if_<false, THEN, ELSE> {
  using type = ELSE;
};

// function_1
template<typename SEARCH, typename TUPLE, size_t start_from=0>
struct contains_type :
        if_< // IF
          std::is_same<std::tuple_element_t<start_from, TUPLE>, SEARCH>::value,
          // THEN
          std::true_type,
          // ELSE
          typename if_ <
            (start_from == std::tuple_size<TUPLE>::value -1 ),
            // THEN
            std::false_type,
            // ELSE
            contains_type<SEARCH, TUPLE, start_from +1 >
          >::type
        >::type
{};

// function_2
template<typename SEARCH>
struct contains_type<SEARCH, std::tuple<>, 0> : std::false_type {};

bool contains(const std::string& search,const std::vector<std::string>& v,size_t start_from = 0 ) {
  if (v[start_from] == search) {
    return true;
  }
  else {
    if ( start_from == v.size() - 1 ) {
      return false;
    }
    else {
      return contains(search, v, start_from+1);
    }
  }
};

void main() {
  std::vector<std::string> vec{"int","bool","float"};
  std::cout << std::boolalpha << contains("bool",  vec) << "\n";
  std::cout << std::boolalpha << contains("double",vec) << "\n";


  std::tuple<int, bool, float> tuple;
  std::cout << std::boolalpha<<contains_type<bool, decltype(tuple)>::value   << "\n";// function_1
  std::cout << std::boolalpha<<contains_type<double, decltype(tuple)>::value << "\n";// function_1

  std::cout<< contains_type<bool, std::tuple<> >::value<<"\n";// function_2
};

};// namespace method_2_make_tuple

#endif //TEMPLATE_METAPROGRAMMING_TEST_METHOD_2_MAKE_TUPLE_H
