#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "parser.h"

#define EXIT_ARGS           1
#define EXIT_PAREN_MISMATCH 2
#define EXIT_INVALID_CHARS  3
#define EXIT_ATOMIC_PARENS  4
#define EXIT_TWO_ATOMS      5

void exit_args() {
  printf("Not enough arguments. Terminating.\nError code: %d\n", EXIT_ARGS);
  exit(EXIT_ARGS);
}

void exit_parens() {
  printf("Mismatched parentheses. Terminating.\nError code: %d\n", EXIT_PAREN_MISMATCH);
  exit(EXIT_PAREN_MISMATCH);
}

void exit_invalid_chars() {
  printf("Mismatched parentheses. Terminating.\nError code: %d\n", EXIT_INVALID_CHARS);
  exit(EXIT_INVALID_CHARS);
}

void exit_atomic_parens() {
  printf("No connective between atomic sentence and parenthetical sentence. Terminating.\nError code: %d\n", EXIT_ATOMIC_PARENS);
  exit(EXIT_ATOMIC_PARENS);
}

void exit_two_atoms() {
  printf("Two consecutive atomic sentences with no binary connective linking them together. Terminating.\n Error code: %d\n", EXIT_TWO_ATOMS);
  exit(EXIT_TWO_ATOMS);
}

void *parse_sentence(char *input, sentence_t *sentence) {
  int i = 0;
  int lookahead = 0;
  int in_parens = 0;
  int prev_is_atom = 0;
  int prev_is_binary_connective = 0;
  int prev_is_negation = 0;
  int prev_is_start_parens = 0;
  int prev_is_end_parens = 0;
  int atom_num = 0;

  sentence = malloc(sizeof(sentence_t*));

  while (i < strlen(input)) {
    lookahead = i;
    switch(input[i]) {
      case ' ':
        // do nothing
	break;
      case '(':
        in_parens += 1;
	prev_is_start_parens = 1;
	prev_is_atom = 0;
	prev_is_binary_connective = 0;
	prev_is_negation = 0;
	prev_is_end_parens = 0;
        break;
      case ')':
        if (!in_parens) {
          exit_parens();
        }
        else {
          in_parens -= 1;
	  prev_is_end_parens = 1;
          prev_is_start_parens = 0;
          prev_is_atom = 0;
          prev_is_binary_connective = 0;
          prev_is_negation = 0;
        }
        break;
      case 'A':
      case 'B':
      case 'C':
      case 'D':
      case 'E':
      case 'F':
      case 'G':
      case 'H':
      case 'I':
      case 'J':
      case 'K':
      case 'L':
      case 'M':
      case 'N':
      case 'O':
      case 'P':
      case 'Q':
      case 'R':
      case 'S':
      case 'T':
      case 'U':
      case 'V':
      case 'W':
      case 'X':
      case 'Y':
      case 'Z':
        if (!prev_is_atom) {
          sentence->atomic_sentence[atom_num];
          atom_num += 1;
        }
        else {
          exit_two_atoms();
        }
        break;
      default:
        exit_invalid_chars();
    }
    i += 1;
  }
  if (in_parens) {
    printf("Mismatched parentheses. Terminating.\n");
    exit_parens;
  }
}

int main (int argc, char **argv) {
  if (argc < 2) {
    exit_args();
  }
  char *sentence = argv[1];
  char substring[100];

  sentence_t *top;
  parse_sentence(sentence, top);
}
