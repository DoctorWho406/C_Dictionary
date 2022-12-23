#include <stdlib.h>
#include <stdio.h>
#include "IntItem.h"
#include "Dictionary.h"

#define to_table (dictionary_table_t *)
#define to_node (dictionary_node_t *)
#define to_int_item (int_item_t *)

int main() {
    dictionary_table_t *dictionary = dictionary_table_new(2);

    dictionary_table_insert(dictionary, to_node int_item_new("Hello", 0), 5);
    dictionary_table_insert(dictionary, to_node int_item_new("World", 1), 5);
    dictionary_table_insert(dictionary, to_node int_item_new("Hello World", 2), 11);
    dictionary_table_insert(dictionary, to_node int_item_new("Good", 3), 4);

    printf("==========DICTIONARY==========\n");
    int_item_t **current_nodes = (int_item_t **)dictionary->table.nodes;
    int_item_t *head_node;
    for (size_t index = 0; index < dictionary->table.hashmap_size; ++index) {
        if ((head_node = current_nodes[index])) {
            printf("Index [%llu]:\n", index);
            int_item_t *current_node = head_node;
            while (current_node) {
                printf("\t%s - %d\n", current_node->key, current_node->value);
                current_node = to_int_item current_node->node.node.node.next;
            }
        }
    }

    int_item_t *searched = int_item_new("Good", -1);
    int_item_t *finded = to_int_item dictionary_table_search(dictionary, to_node searched, 4);
    if (!finded) {
        printf("Node Good not founded\n");
    } else {
        printf("Founded %s with value %d\n", finded->key, finded->value);
    }
    free(searched);

    searched = int_item_new("Goof", -1);
    finded = to_int_item dictionary_table_search(dictionary, to_node searched, 4);
    if (!finded) {
        printf("Node Goof not founded\n");
    } else {
        printf("Founded %s with value %d\n", finded->key, finded->value);
    }
    free(searched);

    searched = int_item_new("Hello World", -1);
    finded = to_int_item dictionary_table_remove(dictionary, to_node searched, 11);
    if (!finded) {
        printf("Node Hello World not founded\n");
    } else {
        printf("Founded %s with value %d\n", finded->key, finded->value);
        free(finded);
    }
    free(searched);

    searched = int_item_new("Goods", -1);
    finded = to_int_item dictionary_table_remove(dictionary, to_node searched, 5);
    if (!finded) {
        printf("Node Goods not founded\n");
    } else {
        printf("Founded %s with value %d\n", finded->key, finded->value);
        free(finded);
    }
    free(searched);

    printf("==========REMOVE FROM DICTIONARY==========\n");
    for (size_t index = 0; index < dictionary->table.hashmap_size; ++index) {
        if ((head_node = current_nodes[index])) {
            printf("Index [%llu]:\n", index);
            int_item_t *current_node = head_node;
            while (current_node) {
                printf("\t%s - %d\n", current_node->key, current_node->value);
                current_node = to_int_item current_node->node.node.node.next;
            }
        }
    }
}