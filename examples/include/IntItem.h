#include "Dictionary.h"

typedef struct int_item {
    dictionary_node_t node;
    const char* key;
    int value;
} int_item_t;

int_item_t *int_item_new(const char *key, const int value);