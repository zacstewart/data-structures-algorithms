#include <stdlib.h>
#include "array.h"

Array array_new(size_t elem_size, size_t size) {
    Array array;
    array.size = size;
    array.elem_size = elem_size;
    array.data = malloc(elem_size * size);
    return array;
}

void array_delete(Array array) {
    free(array.data);
}

int array_insert(Array *array, size_t position, void *value) {
    if (position >= array->size) {
        return 0;
    }

    char *src = (char *) value;
    char *dst = (array->data + (array->elem_size * position));

    for (size_t i = 0; i < array->elem_size; i++) {
        *(dst++) = *(src++);
    }

    return 1;
}

void * array_get(Array *array, size_t position) {
    if (position >= array->size) {
        return NULL;
    }

    return array->data + (array->elem_size * position);
}
