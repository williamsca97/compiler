#include <stdint.h>

typedef enum connective {CONJUNCTION, DISJUNCTION, NEGATION, CONDITIONAL, BICONDITIONAL, NONE} connective;
typedef enum type {ATOMIC, COMPOSITE, EMPTY} type;

typedef struct sentence_t {
  enum type sentence_type;
  enum connective connective;
  struct sentence_t *member_1;
  struct sentence_t *member_2;
  char atomic_sentence[2];
} sentence_t;
