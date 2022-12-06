#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "Item.h"
#include "SetFunctions.h"

dictionary_table_t *dictionary_table_new(const size_t hashmap_size) {
    dictionary_table_t *table = (dictionary_table_t *)set_new(hashmap_size);
    if (!table) {
        return NULL;
    }
    table->collisions = 0;
    return table;
}

dictionary_node_t *dictionary_table_search(dictionary_table_t *table, const char *key, const size_t key_len) {
    set_node_t *node = set_search(&(table->table), key, key_len);
    if (node) {
        return (dictionary_node_t *)node;
    }
    return NULL;
}

dictionary_node_t *dictionary_table_insert(dictionary_table_t *table, const char *key, const size_t key_len, void *value) {
    dictionary_node_t *node = (dictionary_node_t *)set_insert(&(table->table), key, key_len);
    if (!node) {
        return NULL;
    }
    node->value = value;
    return node;
}

dictionary_node_t *dictionary_table_remove(dictionary_table_t *table, const char *key, const size_t key_len) {
    set_node_t *node = set_remove(&(table->table), key, key_len);
    if (node) {
        return (dictionary_node_t *)node;
    }
    return NULL;
}