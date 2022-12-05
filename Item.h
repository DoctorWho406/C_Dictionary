#include <stdio.h>
#include "SetItem.h"

typedef struct dictionary_node{
    set_node_t *node;
    int value;
} dictionary_node_t;

typedef struct set_table dictionary_table_t;