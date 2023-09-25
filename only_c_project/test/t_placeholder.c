//
// Created by shecannotsee on 23-9-25.
//
#include "t_placeholder.h"
#include <placeholder.h>
#include <malloc.h>
#include <string.h>

void t_placeholder() {
  placeholder_string string;
  placeholder_string_init(&string);

  const char* str = "aaaaaaaaaaaaaaaaaaaaaaaaz";
  int str_length = (int)strlen(str);
  set_string(&string, str,str_length);

  int size = get_string_size(&string);
  printf("%d\n", size);

  char* display_str = NULL;
  get_string(&string, &display_str);
  printf("%.*s \n", size, display_str);
}
