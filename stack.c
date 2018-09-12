#include "stack.h"

void stack_push(List *list, void *value) {
    list_push_front(list, value);
}

void *stack_top(List *list) {
    return list->head->value;
}

void *stack_pop(List *list) {
    return list_pop_front(list);
}

int stack_empty(List *list) {
    return list_empty(list);
}
