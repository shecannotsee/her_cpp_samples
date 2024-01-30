//
// Created by shecannotsee on 24-1-19.
//

#ifndef T4_TYPE_TRAITS_H
#define T4_TYPE_TRAITS_H

#define PRINT(module, str) std::cout << "[" << (module) << "]:" << (str) << std::endl

#include "she_type_traits.h"

namespace t4_type_traits {

void run() {
  using namespace she;

  PRINT("true_type", true_type::get_value());
  PRINT("false_type", false_type::get_value());
  PRINT("_or_<>", _or_<>::get_value());
  PRINT("_or_<false_type>", _or_<false_type>::get_value());
  PRINT("_or_<true_type>", _or_<true_type>::get_value());
  /* !1 */ {
    using t = _not_<true_type>;
    PRINT("_not_<true_type>", t::get_value());
  }
  /* !0 */ {
    using t = _not_<false_type>;
    PRINT("_not_<false_type>", t::get_value());
  }
  /* 1|1 */ {
    using t = _or_<true_type, true_type>;
    PRINT("_or_<true_type, true_type>", t::get_value());
  }
  /* 1|0 */ {
    using t = _or_<true_type, false_type>;
    PRINT("_or_<true_type, false_type>", t::get_value());
  }
  /* 0|1 */ {
    using t = _or_<false_type, true_type>;
    PRINT("_or_<false_type, true_type>", t::get_value());
  }
  /* 0|0 */ {
    using t = _or_<false_type, false_type>;
    PRINT("_or_<false_type, false_type>", t::get_value());
  }
  /* 1|0|1|1 */ {
    using t = _or_<true_type, false_type, true_type, true_type>;
    PRINT("_or_<true_type, false_type, true_type, true_type>", t::get_value());
  }
  /* 0|0|0|0 */ {
    using t = _or_<false_type, false_type, false_type, false_type>;
    PRINT("_or_<false_type, false_type, false_type, false_type>", t::get_value());
  }
  /* 1&1 */ {
    using t = _and_<true_type,true_type>;
    PRINT("_and_<true_type,true_type>", t::get_value());
  }
  /* 1&0 */ {
    using t = _and_<true_type,false_type>;
    PRINT("_and_<true_type,false_type>", t::get_value());
  }
  /* 0&1 */ {
    using t = _and_<false_type,true_type>;
    PRINT("_and_<false_type,true_type>", t::get_value());
  }
  /* 0&0 */ {
    using t = _and_<false_type,false_type>;
    PRINT("_and_<false_type,false_type>", t::get_value());
  }
  /* 1 & 1 & 1 & 1 */ {
    using t = _and_<true_type, true_type, true_type, true_type>;
    PRINT("_and_<true_type, true_type, true_type, true_type>", t::get_value());
  }
  /* 1 & 0 & 1 & 1 */ {
    using t = _and_<true_type, false_type, true_type, true_type>;
    PRINT("_and_<true_type, false_type, true_type, true_type>", t::get_value());
  }
  /* 0 & 0 & 0 & 0 */ {
    using t = _and_<false_type, false_type, false_type, false_type>;
    PRINT("_and_<false_type, false_type, false_type, false_type>", t::get_value());
  }
}

}  // namespace t4_type_traits

#endif  // T4_TYPE_TRAITS_H
