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
}

}  // namespace t4_type_traits

#endif  // T4_TYPE_TRAITS_H
