#include <stddef.h>
#include "Set.h"

#ifndef __DICTIONARY_H
#define __DICTIONARY_H

typedef struct dictionary_node {
    set_node_t node;
} dictionary_node_t;

typedef struct dictionary_table {
    set_table_t table;
    size_t collisions;
} dictionary_table_t;

#ifdef _WIN32
#define EXPORTFUNC __declspec(dllexport)
#else
#define EXPORTFUNC
#endif

EXPORTFUNC dictionary_table_t *dictionary_table_new(const size_t hasmap_size);

EXPORTFUNC dictionary_node_t *dictionary_table_insert(dictionary_table_t *table, dictionary_node_t *item, const size_t size_of_key);

EXPORTFUNC dictionary_node_t *dictionary_table_search(dictionary_table_t *table, dictionary_node_t *item, const size_t size_of_key);

EXPORTFUNC dictionary_node_t *dictionary_table_remove(dictionary_table_t *table, dictionary_node_t *item, const size_t size_of_key);

#endif //__DICTIONARY_H