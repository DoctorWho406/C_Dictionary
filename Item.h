#include <stdio.h>
#define INIT_SET_NODE
#include "SetItem.h"

typedef struct dictionary_node {
    set_node_t node;
    void *value;
} dictionary_node_t;

typedef struct dictionary_table {
    set_table_t table;
    size_t collisions;
} dictionary_table_t;