//
// Created by shecannotsee on 23-5-5.
//

#ifndef T_M_TEST_T_M_TEST_M2_TRAITS_H_
#define T_M_TEST_T_M_TEST_M2_TRAITS_H_

namespace m2_traits {

template<class Iterator>
struct iterator_traits {
  using value_type = int;
};

template<typename iter1,typename iter2>
void swap_iter(iter1 it1, iter2 it2) {
  iterator_traits<iter1>::value_type temp = *it1;
  *it1 = *it2;
  *it2 = temp;
};

void main() {


};

};// namespace m2_traits

#endif //T_M_TEST_T_M_TEST_M2_TRAITS_H_
