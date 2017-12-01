#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>

typedef enum connective {CONJUNCTION, DISJUNCTION, NEGATION, CONDITIONAL, BICONDITIONAL, NONE} connective;
typedef enum type {ATOMIC, COMPOSITE, EMPTY} type;

typedef struct sentence_t {
  enum type sentence_type;
  enum connective connective;
  uint32_t member_1;
  uint32_t member_2;
} sentence_t;

#endif
