#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "parser.h"

int main (int argc, char **argv) {
  if (argc < 2) {
    printf("Not enough arguments. Terminating.\n");
    exit(-1);
  }
  char *sentence = argv[1];
  char substring[100];
  sprintf(substring, "%.4s", &sentence[10]);
  puts(substring);
}
