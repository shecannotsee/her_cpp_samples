#include "api_2.h"

#include "foo.h"

void api_2::print() {
  foo_inline();
}

void api_2::print_s() {
  foo_static();
}
