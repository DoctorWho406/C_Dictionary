#include <stddef.h>
#include "Item.h"

dictionary_table_t *dictionary_table_new(const size_t hasmap_size);

dictionary_node_t *dictionary_table_insert(dictionary_table_t *table, const char *key, const size_t key_len, int value);

dictionary_node_t *dictionary_table_search(dictionary_table_t *table, const char *key,  const size_t key_len);

dictionary_node_t *dictionary_table_remove(dictionary_table_t *table, const char *key,  const size_t key_len);