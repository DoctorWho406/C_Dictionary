#include <stdlib.h>
#include "IntItem.h"

struct int_item *int_item_new(const char* key, const int value) {
    struct int_item *item = malloc(sizeof(struct int_item));
    if (!item) {
        return NULL;
    }
    item->key = key;
    item->value = value;
    return item;
}