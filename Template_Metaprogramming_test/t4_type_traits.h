//
// Created by shecannotsee on 24-1-19.
//

#ifndef T4_TYPE_TRAITS_H
#define T4_TYPE_TRAITS_H

#define PRINT(module, str) std::cout<<"["<<(module)<<"]:"<<(str)<<std::endl

#include "she_type_traits.h"

namespace t4_type_traits {

void run() {
  using namespace she;
  PRINT("true_type",
    true_type::get_value());
  PRINT("false_type",
    false_type::get_value());
  PRINT("_or_<>",
    _or_<>::get_value());
  PRINT("_or_<false_type>",
    _or_<false_type>::get_value());
  PRINT("_or_<true_type>",
    _or_<true_type>::get_value());
}

}

#endif //T4_TYPE_TRAITS_H
