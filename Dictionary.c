#include <stdio.h>
#include "Functions.h"

int main() {
    dictionary_table_t *dictionary = dictionary_table_new(2);
    
    dictionary_table_insert(dictionary, "Hello", 5, 0);
    dictionary_table_insert(dictionary, "World", 5, 1);
    dictionary_table_insert(dictionary, "Hello World", 11, 2);
    dictionary_table_insert(dictionary, "Good", 4, 3);

    
    printf("==========DICTIONARY==========\n");
    dictionary_node_t **current_nodes = (dictionary_node_t **)dictionary->nodes;
    size_t index = 0;
    dictionary_node_t *head_node;
    for (size_t index = 0; index < dictionary->hashmap_size; index++) {
        if ((head_node = current_nodes[index])) {
            printf("Index [%llu]:\n", index);
            dictionary_node_t *current_node = head_node;
            while(current_node) {
                printf("\t%s - %d\n", current_node->node->key, current_node->value);
                current_node = (dictionary_node_t *)current_node->node->next;
            }
        }
    }
}