#include "utils.h"

char* str_tolower(const char* str) {
  char* lowercased_string = (char*) malloc(strlen(str) * sizeof(char) + sizeof(char));
  for (int i = 0; i < strlen(str); i++) {
    lowercased_string[i] = tolower(str[i]);
  }
  lowercased_string[strlen(str)] = '\0';
  
  return lowercased_string;
}

void clear_screen(void) {
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}

void rmv_newline(char* str) {
  int len = strlen(str);
  if( str[len-1] == '\n' )
    str[len-1] = 0;
}