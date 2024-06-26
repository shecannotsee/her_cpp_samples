#ifndef T5_STRUCTURED_BINDING_H
#define T5_STRUCTURED_BINDING_H

#include <iostream>
#include <string>

namespace t5_structured_binding {

struct people {
  std::string name;
  int age;
};

inline void run() {
  std::cout << "t5_structured_binding start-------------------------------------------------------------------------\n";

  people author{"shecannotsee", 26};
  auto [my_name, my_age] = author;
  std::cout << author.name << " is " << author.age << std::endl;
  std::cout << my_name << " is " << my_age << std::endl;

  std::cout << "t5_structured_binding done\n";
}

}  // namespace t5_structured_binding

#endif  // T5_STRUCTURED_BINDING_H
