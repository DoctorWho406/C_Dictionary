#define CLOVE_SUITE_NAME DictionaryTest
#include "clove-unit.h"
#include "dictionary.h"
#define HASH_IMPLEMENTATION
#include "hash.h"
#include <stdlib.h>

dictionary_table_t *dictionary;

CLOVE_SUITE_SETUP() {
    dictionary_table_create(&dictionary, 5);
}

CLOVE_SUITE_TEARDOWN() {
    dictionary_table_destroy(dictionary);
}

typedef struct test_item {
    list_node_t node;
    const char *key;
    int value;
} test_item_t;

test_item_t *new_test_item(const char *key, const int value) {
    test_item_t *item = malloc(sizeof(test_item_t));
    if (!item) {
        return NULL;
    }
    item->key = key;
    item->value = value;
    return item;
}

CLOVE_TEST(CreateSetWithOneItem) {
    CLOVE_NOT_NULL(dictionary);
    test_item_t *first = new_test_item("First", 1);

    CLOVE_NOT_NULL(first);

    dictionary_table_insert(dictionary, (dictionary_node_t *)first, 6);

    int first_index = hash_djb33x("First", 6) % dictionary->table.hashmap_size;
    CLOVE_PTR_EQ(first, dictionary->table.nodes[first_index]);

    free(first);
}

CLOVE_TEST(CreateSetWithTwoItem) {
    test_item_t *first = new_test_item("First", 1);
    test_item_t *second = new_test_item("Second", 2);

    CLOVE_NOT_NULL(first);
    CLOVE_NOT_NULL(second);

    dictionary_table_insert(dictionary, (dictionary_node_t *)first, 6);
    dictionary_table_insert(dictionary, (dictionary_node_t *)second, 7);

    int first_index = hash_djb33x("First", 6) % dictionary->table.hashmap_size;
    int second_index = hash_djb33x("Second", 7) % dictionary->table.hashmap_size;
    CLOVE_PTR_EQ(first, dictionary->table.nodes[first_index]);
    if (first_index == second_index) {
        CLOVE_PTR_EQ(second, dictionary->table.nodes[first_index]->node.next);
    } else {
        CLOVE_PTR_EQ(second, dictionary->table.nodes[second_index]);
    }

    free(first);
    free(second);
}

CLOVE_TEST(SearchFromSetWithZeroItem) {
    test_item_t *to_find = new_test_item("ToFind", 1);

    dictionary_node_t *finded = dictionary_table_search(dictionary, (dictionary_node_t *)to_find, 7);

    CLOVE_NULL(finded);

    free(to_find);
}

CLOVE_TEST(SearchFromSetWithOneItem) {
    test_item_t *first = new_test_item("First", 1);
    dictionary_table_insert(dictionary, (dictionary_node_t *)first, 6);

    dictionary_node_t *finded = dictionary_table_search(dictionary, (dictionary_node_t *)first, 6);

    CLOVE_PTR_EQ(first, finded);

    free(first);
}

CLOVE_TEST(SearchNewItemFromSetWithOneItem) {
    test_item_t *first = new_test_item("First", 1);
    dictionary_table_insert(dictionary, (dictionary_node_t *)first, 6);

    test_item_t *to_find = new_test_item("First", 1);

    dictionary_node_t *finded = dictionary_table_search(dictionary, (dictionary_node_t *)to_find, 6);

    CLOVE_PTR_EQ(first, finded);

    free(first);
    free(to_find);
}

CLOVE_TEST(SearchFromSetWithTwoItem) {
    test_item_t *first = new_test_item("First", 1);
    test_item_t *second = new_test_item("Second", 2);
    dictionary_table_insert(dictionary, (dictionary_node_t *)first, 6);
    dictionary_table_insert(dictionary, (dictionary_node_t *)second, 7);

    dictionary_node_t *finded = dictionary_table_search(dictionary, (dictionary_node_t *)second, 7);

    CLOVE_PTR_EQ(second, finded);

    free(first);
    free(second);
}

CLOVE_TEST(SearchNewItemFromSetWithTwoItem) {
    test_item_t *first = new_test_item("First", 1);
    test_item_t *second = new_test_item("Second", 2);
    dictionary_table_insert(dictionary, (dictionary_node_t *)first, 6);
    dictionary_table_insert(dictionary, (dictionary_node_t *)second, 7);

    test_item_t *to_find = new_test_item("Second", 2);
    dictionary_node_t *finded = dictionary_table_search(dictionary, (dictionary_node_t *)to_find, 7);

    CLOVE_PTR_EQ(second, finded);

    free(first);
    free(second);
    free(to_find);
}

CLOVE_TEST(RemoveFromSetWithZeroItem) {
    test_item_t *to_remove = new_test_item("ToRemove", 1);

    dictionary_node_t *removed = dictionary_table_remove(dictionary, (dictionary_node_t *)to_remove, 9);
    CLOVE_NULL(removed);

    free(to_remove);
}

CLOVE_TEST(RemoveFromSetWithOneItem) {
    test_item_t *first = new_test_item("First", 1);
    dictionary_table_insert(dictionary, (dictionary_node_t *)first, 6);

    dictionary_node_t *removed = dictionary_table_remove(dictionary, (dictionary_node_t *)first, 6);

    int first_index = hash_djb33x("First", 6) % dictionary->table.hashmap_size;
    CLOVE_PTR_EQ(first, removed);
    CLOVE_NULL(dictionary->table.nodes[first_index]);

    free(first);
}

CLOVE_TEST(RemoveNewItemFromSettWithOneItem) {
    test_item_t *first = new_test_item("First", 1);
    dictionary_table_insert(dictionary, (dictionary_node_t *)first, 6);

    test_item_t *to_remove = new_test_item("First", 1);
    dictionary_node_t *removed = dictionary_table_remove(dictionary, (dictionary_node_t *)to_remove, 6);

    int first_index = hash_djb33x("First", 6) % dictionary->table.hashmap_size;
    CLOVE_PTR_EQ(first, removed);
    CLOVE_NULL(dictionary->table.nodes[first_index]);

    free(first);
    free(to_remove);
}

CLOVE_TEST(RemoveFromSetWithTwoItem) {
    test_item_t *first = new_test_item("First", 1);
    test_item_t *second = new_test_item("Second", 2);
    dictionary_table_insert(dictionary, (dictionary_node_t *)first, 6);
    dictionary_table_insert(dictionary, (dictionary_node_t *)second, 7);

    dictionary_node_t *removed = dictionary_table_remove(dictionary, (dictionary_node_t *)first, 6);

    CLOVE_PTR_EQ(first, removed);
    int first_index = hash_djb33x("First", 6) % dictionary->table.hashmap_size;
    int second_index = hash_djb33x("Second", 7) % dictionary->table.hashmap_size;
    if (first_index == second_index) {
        CLOVE_PTR_EQ(second, dictionary->table.nodes[second_index]);
        CLOVE_NULL(dictionary->table.nodes[first_index]->node.next);
    } else {
        CLOVE_NULL(dictionary->table.nodes[first_index]);
    }

    free(first);
    free(second);
}

CLOVE_TEST(RemoveNewItemFromSetWithTwoItem) {
    test_item_t *first = new_test_item("First", 1);
    test_item_t *second = new_test_item("Second", 2);
    dictionary_table_insert(dictionary, (dictionary_node_t *)first, 6);
    dictionary_table_insert(dictionary, (dictionary_node_t *)second, 7);

    test_item_t *to_remove = new_test_item("First", 1);
    dictionary_node_t *removed = dictionary_table_remove(dictionary, (dictionary_node_t *)to_remove, 6);

    CLOVE_PTR_EQ(first, removed);
    int first_index = hash_djb33x("First", 6) % dictionary->table.hashmap_size;
    int second_index = hash_djb33x("Second", 7) % dictionary->table.hashmap_size;
    if (first_index == second_index) {
        CLOVE_PTR_EQ(second, dictionary->table.nodes[second_index]);
        CLOVE_NULL(dictionary->table.nodes[first_index]->node.next);
    } else {
        CLOVE_NULL(dictionary->table.nodes[first_index]);
    }

    free(first);
    free(second);
    free(to_remove);
}