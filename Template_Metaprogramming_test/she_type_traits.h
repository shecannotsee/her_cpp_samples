//
// Created by shecannotsee on 24-1-30.
//

#ifndef SHE_TYPE_TRAITS_H
#define SHE_TYPE_TRAITS_H

#include <type_traits>

namespace she {

template <typename type_, type_ value_>
struct integral_constant {
  using type                   = integral_constant;
  static constexpr type_ value = value_;
};

using true_type  = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

// 这是一个条件模板，根据一个布尔值的真假选择两个不同的类型。在这里，根据第一个参数（布尔值）的真假，选择第二个类型或者第三个类型。
template <bool c, typename true_, typename false_>
struct conditional {
  using type = true_;
};
template <typename true_, typename false_>
struct conditional<false, true_, false_> {
  using type = false_;
};

namespace _not_ {
template <typename value_>
struct input {
  // The typename keyword is used to tell the compiler that
  // [group<c1::value, c1, c2>::type] is a type and not a static member variable
  using type                  = typename integral_constant<bool, !bool(value_::value)>::type;
  static constexpr bool value = type::value;
};
}  // namespace _not_
namespace _or_ {
// Generic templates
template <typename...>
struct input;
// Template specialization: default
template <>
struct input<> {
  using type                  = integral_constant<bool, false>::type;
  static constexpr bool value = type::value;
};
// Template specialization: one param
template <typename c1>
struct input<c1> {
  using type                  = c1;
  static constexpr bool value = type::value;
};
// Template specialization: double params
template <typename c1, typename c2>
struct input<c1, c2> {
  // The typename keyword is used to tell the compiler that
  // [group<c1::value, c1, c2>::type] is a type and not a static member variable
  using type                  = typename conditional<c1::value, c1, c2>::type;
  static constexpr bool value = type::value;
};
// Template specialization: more params
template <typename c1, typename c2, typename c3, typename... cn>
struct input<c1, c2, c3, cn...> {
  using type                  = typename conditional<c1::value, c1, input<c2, c3, cn...>>::type;
  static constexpr bool value = type::value;
};
}  // namespace _or_
namespace _and_ {
// Generic templates
template <typename...>
struct input;
// Template specialization: default
template <>
struct input<> : public true_type {};
// Template specialization: one param
template <typename c1>
struct input<c1> {
  using type                  = typename c1::type;
  static constexpr bool value = type::value;
};
// Template specialization: double params
template <typename c1, typename c2>
struct input<c1, c2> {
  using type                  = typename conditional<c1::value, c2, c1>::type;
  static constexpr bool value = type::value;
};
// Template specialization: more params
template <typename c1, typename c2, typename c3, typename... cn>
struct input<c1, c2, c3, cn...> {
  using type                  = typename conditional<c1::value, input<c2, c3, cn...>, c1>::type;
  static constexpr bool value = type::value;
};
}  // namespace _and_
namespace base_type {
template <typename>
struct check {
  using type                  = false_type;
  static constexpr bool value = type::value;
};

template <>
struct check<bool> {
  using type                  = true_type;
  static constexpr bool value = type::value;
};

template <>
struct check<unsigned char> {
  using type                  = true_type;
  static constexpr bool value = type::value;
};

template <>
struct check<signed char> {
  using type                  = true_type;
  static constexpr bool value = type::value;
};

template <>
struct check<char> {
  using type                  = true_type;
  static constexpr bool value = type::value;
};

template <>
struct check<unsigned short> {
  using type                  = true_type;
  static constexpr bool value = type::value;
};

template <>
struct check<short> {
  using type                  = true_type;
  static constexpr bool value = type::value;
};

template <>
struct check<unsigned int> {
  using type                  = true_type;
  static constexpr bool value = type::value;
};

template <>
struct check<int> {
  using type                  = true_type;
  static constexpr bool value = type::value;
};

template <>
struct check<unsigned long> {
  using type                  = true_type;
  static constexpr bool value = type::value;
};

template <>
struct check<long> {
  using type                  = true_type;
  static constexpr bool value = type::value;
};

template <>
struct check<unsigned long long> {
  using type                  = true_type;
  static constexpr bool value = type::value;
};

template <>
struct check<long long> {
  using type                  = true_type;
  static constexpr bool value = type::value;
};

template <typename>
struct get_name {
  using type                      = false_type;
  inline static const char* value = "unknow";
};

template <>
struct get_name<bool> {
  using type                      = true_type;
  inline static const char* value = "bool";
};

template <>
struct get_name<unsigned char> {
  using type                      = true_type;
  inline static const char* value = "unsigned char";
};

template <>
struct get_name<signed char> {
  using type                      = true_type;
  inline static const char* value = "signed char";
};

template <>
struct get_name<char> {
  using type                      = true_type;
  inline static const char* value = "char";
};

template <>
struct get_name<unsigned short> {
  using type                      = true_type;
  inline static const char* value = "unsigned short";
};

template <>
struct get_name<short> {
  using type                      = true_type;
  inline static const char* value = "short";
};

template <>
struct get_name<unsigned int> {
  using type                      = true_type;
  inline static const char* value = "unsigned int";
};

template <>
struct get_name<int> {
  using type                      = true_type;
  inline static const char* value = "int";
};

template <>
struct get_name<unsigned long> {
  using type                      = true_type;
  inline static const char* value = "unsigned long";
};

template <>
struct get_name<long> {
  using type                      = true_type;
  inline static const char* value = "long";
};

template <>
struct get_name<unsigned long long> {
  using type                      = true_type;
  inline static const char* value = "unsigned long long";
};

template <>
struct get_name<long long> {
  using type                      = true_type;
  inline static const char* value = "long long";
};


}  // namespace base_type
}

#endif //SHE_TYPE_TRAITS_H
