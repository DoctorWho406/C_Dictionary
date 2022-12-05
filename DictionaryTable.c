#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "Functions.h"
#include "SetFunctions.h"

dictionary_table_t *dictionary_table_new(const size_t hasmap_size) {
    return set_new(hasmap_size);
}

dictionary_node_t *dictionary_table_search(dictionary_table_t *table, const char *key,  const size_t key_len) {
    set_node_t *node = set_search(table, key, key_len);
    if(node) {
        return (dictionary_node_t *)node;
    }   
    return NULL;
}

dictionary_node_t *dictionary_table_insert(dictionary_table_t *table, const char *key, const size_t key_len, int value) {
    set_node_t *node = set_insert(table, key, key_len);
    if(node) {
        ((dictionary_node_t *)node)->value = value;
    }
    return NULL;
}

dictionary_node_t *dictionary_table_remove(dictionary_table_t *table, const char *key,  const size_t key_len) {
    set_node_t *node = set_remove(table, key, key_len);
    if(node) {
        return (dictionary_node_t *) node;
    }
    return NULL;
}