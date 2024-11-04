#ifndef T1_H
#define T1_H

#include "foo.h"

inline void t1() {
  std::cout << "[====Test====]constructor test\n"; {
    foo<int> entity_1("entity_1", 10);
    std::cout << __LINE__ << "\n"; {
      foo<int> entity_2(entity_1);
      std::cout << "entity_2 name: " << entity_2.get_name() << std::endl;
      entity_2.set_name("entity_2");
    }
    std::cout << __LINE__ << "\n"; {
      foo<int> entity_3(std::move(entity_1));
      std::cout << "entity_3 name: " << entity_3.get_name() << std::endl;
      entity_3.set_name("entity_2");
    }
    std::cout << __LINE__ << "\n";
    std::cout << "entity_1 name: " <<entity_1.get_name() << "\n"; {}
    entity_1.set_name("entity_1");
  }
  std::cout << "\n[====Test====]assignment operator\n"; {
    foo<int> entity_1("entity_1", 10);

    std::cout << __LINE__ << "\n"; {
      foo<int> temp("temp", 20);
      temp = entity_1;
      std::cout << "temp name: " << temp.get_name() << std::endl;
      temp.set_name("temp");
    }
    std::cout << __LINE__ << "\n"; {
      foo<int> temp("temp", 20);
      temp = std::move(entity_1);
      std::cout << "entity_2 name: " << temp.get_name() << std::endl;
      temp.set_name("temp");
    }
    std::cout << "entity_1 name: " <<entity_1.get_name() << "\n"; {}
    entity_1.set_name("entity_1");
  }
}

#endif //T1_H
