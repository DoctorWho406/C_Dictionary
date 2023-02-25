#include <string.h>
#include "dictionary.h"

int dictionary_table_create(dictionary_table_t **table, const size_t hashmap_size) {
    if (set_table_create((set_table_t **)table, hashmap_size) != 0) {
        return -1;
    }
    (*table)->collisions = 0;
    return 0;
}

dictionary_node_t *dictionary_table_search(dictionary_table_t *table, dictionary_node_t *item, const size_t size_of_key) {
    return (dictionary_node_t *)set_table_search(&(table->table), &(item->node), size_of_key);
}

int dictionary_table_insert(dictionary_table_t *table, dictionary_node_t *item, const size_t size_of_key) {
    return set_table_insert(&(table->table), &(item->node), size_of_key);
}

dictionary_node_t *dictionary_table_remove(dictionary_table_t *table, dictionary_node_t *item, const size_t size_of_key) {
    return (dictionary_node_t *)set_table_remove(&(table->table), &(item->node), size_of_key);
}

void dictionary_table_destroy(dictionary_table_t *table) {
    set_table_destroy(&(table->table));
}