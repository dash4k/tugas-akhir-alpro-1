#include "utils.h"


char* str_tolower(const char* str) {
  char* lowercased_string = (char*) malloc(strlen(str) * sizeof(char) + sizeof(char));
  for (int i = 0; i < strlen(str); i++) {
    lowercased_string[i] = tolower(str[i]);
  }
  lowercased_string[strlen(str)] = '\0';
  
  return lowercased_string;
}