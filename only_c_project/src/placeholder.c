//
// Created by shecannotsee on 23-9-25.
//
#include "placeholder.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

void placeholder_string_init(placeholder_string* ps) {
  ps->size = 0;
  ps->buffer = NULL;
}

void set_string(placeholder_string* ps, const char* new_string, int new_string_length) {
  ps->buffer = malloc(new_string_length);
  memcpy(ps->buffer, new_string, new_string_length);
  ps->size = new_string_length;
}

int get_string(placeholder_string* ps, char** display) {
  *display = ps->buffer;
  return ps->size;
}

int get_string_size(placeholder_string* ps) {
  return ps->size;
}

void free_placeholder_string(placeholder_string* ps, int ps_size) {
  free(ps->buffer);
  ps->buffer = NULL;
}
