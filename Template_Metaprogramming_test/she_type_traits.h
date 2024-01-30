//
// Created by shecannotsee on 24-1-30.
//

#ifndef SHE_TYPE_TRAITS_H
#define SHE_TYPE_TRAITS_H

#include <string>
#include <type_traits>

namespace she {

template <typename type_, type_ value_>
struct constant_base {
  static constexpr type_ value = value_;
  static std::string get_value() {
    if (value_) {
      return "true";
    } else {
      return "false";
    }
  }
};

using true_type  = constant_base<bool, true>;
using false_type = constant_base<bool, false>;

// 这是一个条件模板，根据一个布尔值的真假选择两个不同的类型。在这里，根据第一个参数（布尔值）的真假，选择第二个类型或者第三个类型。
template <bool c, typename true_, typename false_>
struct group {
  using type = true_;
};
template <typename true_, typename false_>
struct group<false, true_, false_> {
  typedef false_ type;
};

// not
template <typename p>
struct _not_ : public constant_base<bool, !bool(p::value)> {};
// or
template <typename...>
struct _or_;
template <>
struct _or_<> : public false_type {};
template <typename c1>
struct _or_<c1> : public c1 {};
template <typename c1, typename c2>
struct _or_<c1, c2> : public group<c1::value, c1, c2>::type {};
template <typename c1, typename c2, typename c3, typename... cn>
struct _or_<c1, c2, c3, cn...> : public group<c1::value, c1, _or_<c2, c3, cn...>>::type {};
// and
template <typename...>
struct _and_;
template <>
struct _and_<> : public true_type {};
template <typename c1>
struct _and_<c1> : public c1 {};
template <typename c1, typename c2>
struct _and_<c1, c2> : public group<c1::value, c2, c1>::type {};
template <typename c1, typename c2, typename c3, typename... cn>
struct _and_<c1, c2, c3, cn...> : public group<c1::value, _and_<c2, c3, cn...>, c1>::type {};
}

#endif //SHE_TYPE_TRAITS_H
