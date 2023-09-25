//
// Created by shecannotsee on 23-9-25.
//

#ifndef TRANSCODING_PLACEHOLDER_H
#define TRANSCODING_PLACEHOLDER_H

typedef struct {
  int   size;
  char* buffer;
} placeholder_string;

void placeholder_string_init(placeholder_string* ps);

void set_string(placeholder_string* ps, const char* new_string, int new_string_length);

int get_string(placeholder_string* ps, char** display);

int get_string_size(placeholder_string* ps);

void free_placeholder_string(placeholder_string* ps, int ps_size);

#endif //TRANSCODING_PLACEHOLDER_H
