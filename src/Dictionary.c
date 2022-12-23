#include <stdlib.h>
#include <string.h>
#include "Set.h"
#include "Dictionary.h"

dictionary_table_t *dictionary_table_new(const size_t hashmap_size) {
    dictionary_table_t *table = (dictionary_table_t *)set_table_new(hashmap_size);
    if (!table) {
        return NULL;
    }
    table->collisions = 0;
    return table;
}

dictionary_node_t *dictionary_table_search(dictionary_table_t *table, dictionary_node_t *item, const size_t size_of_key) {
    set_node_t *node = set_table_search(&(table->table), &(item->node), size_of_key);
    if (node) {
        return (dictionary_node_t *)node;
    }
    return NULL;
}

dictionary_node_t *dictionary_table_insert(dictionary_table_t *table, dictionary_node_t *item, const size_t size_of_key) {
    return (dictionary_node_t *)set_table_insert(&(table->table), &(item->node), size_of_key);
}

dictionary_node_t *dictionary_table_remove(dictionary_table_t *table, dictionary_node_t *item, const size_t size_of_key) {
    set_node_t *node = set_table_remove(&(table->table), &(item->node), size_of_key);
    if (node) {
        return (dictionary_node_t *)node;
    }
    return NULL;
}