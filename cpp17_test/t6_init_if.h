#ifndef T6_INIT_IF_H
#define T6_INIT_IF_H

namespace t6_init_if {

inline void run() {
  std::cout << "t6_init_if start------------------------------------------------------------------------------------\n";

  if (bool flag = true; flag) {
    std::cout << "flag->true\n";
  } else {
    std::cout << "flag->false\n";
  }

  switch (int i = 3; i) {
    case 0:
      std::cout << "case:0\n";
      break;
    case 1:
      std::cout << "case:1\n";
      break;
    case 2:
      std::cout << "case:2\n";
      break;
    case 3:
      std::cout << "case:3\n";
      break;
    case 4:
      std::cout << "case:4\n";
      break;
    default:
      std::cout << "case:?\n";
      break;
  }

  std::cout << "t6_init_if done\n";
}

}  // namespace t6_init_if

#endif  // T6_INIT_IF_H
