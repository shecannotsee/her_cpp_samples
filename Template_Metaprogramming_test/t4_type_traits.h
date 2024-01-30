//
// Created by shecannotsee on 24-1-19.
//

#ifndef T4_TYPE_TRAITS_H
#define T4_TYPE_TRAITS_H

#define PRINT(example, result) std::cout << "[" << (example) << "]:" << (result) << std::endl

#include "she_type_traits.h"
#include "t4_type_traits.h"

template <typename... input>
struct not_test {
  using p = she::_not_::input<input...>;
};
template <typename... input>
struct or_test {
  using p = she::_or_::input<input...>;
};
template <typename... input>
struct and_test {
  using p = she::_and_::input<input...>;
};
template <typename T, T V>
struct get_type {
  using type = T;
  using p    = T;
};

namespace t4_type_traits {

void run() {
  constexpr auto get_value = [](const bool value) {
    if (value)
      return "true";
    else
      return "false";
  };
  using _1 = she::true_type;
  using _0 = she::false_type;
  /* not */ {
    using t1 = not_test<_0>::p;
    PRINT("!0", get_value(t1::value));
    using t2 = not_test<_1>::p;
    PRINT("!1", get_value(t2::value));
  }
  /* or */ {
    using t1 = or_test<>::p;
    PRINT("|", get_value(t1::value));

    using t2 = or_test<_0>::p;
    PRINT("0|", get_value(t2::value));

    using t3 = or_test<_1>::p;
    PRINT("1|", get_value(t3::value));

    using t4 = or_test<_0, _0>::p;
    PRINT("0|0", get_value(t4::value));

    using t5 = or_test<_0, _1>::p;
    PRINT("0|1", get_value(t5::value));

    using t6 = or_test<_1, _1>::p;
    PRINT("1|1", get_value(t6::value));

    using t7 = or_test<_0, _0, _0>::p;
    PRINT("0|0|0", get_value(t7::value));

    using t8 = or_test<_0, _0, _1>::p;
    PRINT("0|0|1", get_value(t8::value));

    using t9 = or_test<_0, _1, _0>::p;
    PRINT("0|1|0", get_value(t9::value));

    using t10 = or_test<_0, _1, _1>::p;
    PRINT("0|1|1", get_value(t10::value));

    using t11 = or_test<_1, _0, _0>::p;
    PRINT("1|0|0", get_value(t11::value));

    using t12 = or_test<_1, _0, _1>::p;
    PRINT("1|0|1", get_value(t12::value));

    using t13 = or_test<_1, _1, _0>::p;
    PRINT("1|1|0", get_value(t13::value));

    using t14 = or_test<_1, _1, _1>::p;
    PRINT("1|1|1", get_value(t14::value));
  }
  /* and */ {
    using t1 = and_test<>::p;
    PRINT("&", get_value(t1::value));

    using t2 = and_test<_0>::p;
    PRINT("0 &", get_value(t2::value));

    using t3 = and_test<_1>::p;
    PRINT("1 &", get_value(t3::value));

    using t4 = and_test<_0, _0>::p;
    PRINT("0 & 0", get_value(t4::value));

    using t5 = and_test<_0, _1>::p;
    PRINT("0 & 1", get_value(t5::value));

    using t6 = and_test<_1, _0>::p;
    PRINT("1 & 0", get_value(t6::value));

    using t7 = and_test<_1, _1>::p;
    PRINT("1 & 1", get_value(t7::value));

    using t8 = and_test<_0, _0, _1>::p;
    PRINT("0 & 0 & 1", get_value(t8::value));

    using t9 = and_test<_0, _1, _0>::p;
    PRINT("0 & 1 & 0", get_value(t9::value));

    using t10 = and_test<_0, _1, _1>::p;
    PRINT("0 & 1 & 1", get_value(t10::value));

    using t11 = and_test<_1, _0, _0>::p;
    PRINT("1 & 0 & 0", get_value(t11::value));

    using t12 = and_test<_1, _0, _1>::p;
    PRINT("1 & 0 & 1", get_value(t12::value));

    using t13 = and_test<_1, _1, _0>::p;
    PRINT("1 & 1 & 0", get_value(t13::value));

    using t14 = and_test<_1, _1, _1>::p;
    PRINT("1 & 1 & 1", get_value(t14::value));
  }
  /* type_support */ {
    using t1 = she::base_type::check<_0>;
    using n1 = she::base_type::get_name<_0>;
    PRINT(n1::value, get_value(t1::value));

    bool t_bool = true;
    using t2    = she::base_type::check<decltype(t_bool)>;
    using n2    = she::base_type::get_name<decltype(t_bool)>;
    PRINT(n2::value, get_value(t2::value));

    unsigned char t_uc = 0;
    using t3           = she::base_type::check<decltype(t_uc)>;
    using n3           = she::base_type::get_name<decltype(t_uc)>;
    PRINT(n3::value, get_value(t3::value));

    signed char t_sc = 0;
    using t4         = she::base_type::check<decltype(t_sc)>;
    using n4         = she::base_type::get_name<decltype(t_sc)>;
    PRINT(n4::value, get_value(t4::value));

    char t_c = 0;
    using t5 = she::base_type::check<decltype(t_c)>;
    using n5 = she::base_type::get_name<decltype(t_c)>;
    PRINT(n5::value, get_value(t5::value));

    unsigned short t_us = 0;
    using t6            = she::base_type::check<decltype(t_us)>;
    using n6            = she::base_type::get_name<decltype(t_us)>;
    PRINT(n6::value, get_value(t6::value));

    short t_s = 0;
    using t7  = she::base_type::check<decltype(t_s)>;
    using n7  = she::base_type::get_name<decltype(t_s)>;
    PRINT(n7::value, get_value(t7::value));

    unsigned int t_ui = 0;
    using t8          = she::base_type::check<decltype(t_ui)>;
    using n8          = she::base_type::get_name<decltype(t_ui)>;
    PRINT(n8::value, get_value(t8::value));

    int t_i  = 0;
    using t9 = she::base_type::check<decltype(t_i)>;
    using n9 = she::base_type::get_name<decltype(t_i)>;
    PRINT(n9::value, get_value(t9::value));

    unsigned long t_ul = 0;
    using t10          = she::base_type::check<decltype(t_ul)>;
    using n10          = she::base_type::get_name<decltype(t_ul)>;
    PRINT(n10::value, get_value(t10::value));

    long t_l  = 0;
    using t11 = she::base_type::check<decltype(t_l)>;
    using n11 = she::base_type::get_name<decltype(t_l)>;
    PRINT(n11::value, get_value(t11::value));

    unsigned long long t_ull = 0;
    using t12                = she::base_type::check<decltype(t_ull)>;
    using n12                = she::base_type::get_name<decltype(t_ull)>;
    PRINT(n12::value, get_value(t12::value));

    long long t_ll = 0;
    using t13      = she::base_type::check<decltype(t_ll)>;
    using n13      = she::base_type::get_name<decltype(t_ll)>;
    PRINT(n13::value, get_value(t13::value));
  }
}

}  // namespace t4_type_traits

#endif  // T4_TYPE_TRAITS_H
