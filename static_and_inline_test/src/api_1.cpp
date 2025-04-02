#include "api_1.h"

#include "foo.h"

void api_1::print() {
  foo_inline();
}

void api_1::print_s() {
  foo_static();
}
