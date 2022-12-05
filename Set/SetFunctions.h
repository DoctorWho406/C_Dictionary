#ifdef _WIN32
#define EXPORTFUNC __declspec(dllexport)
#else
#define EXPORTFUNC
#endif

#include "SetItem.h"

EXPORTFUNC set_table_t *set_new(const size_t hasmap_size);

EXPORTFUNC set_node_t *set_insert(set_table_t *table, const char *key, const size_t key_len);

EXPORTFUNC set_node_t *set_search(set_table_t *table, const char *key,  const size_t key_len);

EXPORTFUNC set_node_t *set_remove(set_table_t *table, const char *key,  const size_t key_len);