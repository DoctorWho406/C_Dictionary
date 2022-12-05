#include <stdio.h>
#include "Functions.h"

int main() {
    dictionary_table_t *dictionary = dictionary_table_new(2);

    int a = 0;
    dictionary_table_insert(dictionary, "Hello", 5, &a);
    int b = 1;
    dictionary_table_insert(dictionary, "World", 5, &b);
    int c = 2;
    dictionary_table_insert(dictionary, "Hello World", 11, &c);
    int d = 3;
    dictionary_table_insert(dictionary, "Good", 4, &d);
    
    printf("==========DICTIONARY==========\n");
    dictionary_node_t **current_nodes = (dictionary_node_t **)dictionary->table.nodes;
    size_t index = 0;
    dictionary_node_t *head_node;
    for (size_t index = 0; index < dictionary->table.hashmap_size; index++) {
        if ((head_node = current_nodes[index])) {
            printf("Index [%llu]:\n", index);
            dictionary_node_t *current_node = head_node;
            while(current_node) {
                printf("\t%s - %d\n", current_node->node.key, *((int *)current_node->value));
                current_node = (dictionary_node_t *)current_node->node.next;
            }
        }
    }

    dictionary_node_t *finded = dictionary_table_search(dictionary, "Good", 4);
    if(!finded) {
        printf("Node not founded\n");
    } else {
        printf("Founded %s\n", finded->node.key);
    }

    finded = dictionary_table_search(dictionary, "Goof", 4);
    if(!finded) {
        printf("Node not founded\n");
    } else {
        printf("Founded %s\n", finded->node.key);
    }

    dictionary_table_remove(dictionary, "Hello World", 11);
    dictionary_table_remove(dictionary, "Goods", 5);
    printf("==========REMOVE FROM DICTIONARY==========\n");
    index = 0;
    for (size_t index = 0; index < dictionary->table.hashmap_size; index++) {
        if ((head_node = current_nodes[index])) {
            printf("Index [%llu]:\n", index);
            dictionary_node_t *current_node = head_node;
            while(current_node) {
                printf("\t%s - %d\n", current_node->node.key, *((int *)current_node->value));
                current_node = (dictionary_node_t *)current_node->node.next;
            }
        }
    }

}