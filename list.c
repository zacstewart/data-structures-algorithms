#include <stdio.h>
#include "list.h"

List list_new() {
    List list;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

void list_delete(List *list) {
    Element *element = list->head;
    while (element != NULL) {
        Element *next = element->next;
        free(element);
        element = next;
    }
}

void *list_pop_front(List *list) {
    Element *head = list->head;
    list->head = head->next;
    void *value = head->value;
    free(head);
    return value;
}

void *list_pop_back(List *list) {
    Element *tail = list->tail;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail = list->head;
        while (list->tail->next->next != NULL) {
            list->tail = list->tail->next;
        }
        list->tail->next = NULL;
    }

    void *value = tail->value;
    free(tail);
    return value;
}

void list_push_front(List *list, void *value) {
    Element *element = malloc(sizeof(Element));
    element->value = value;
    element->next = list->head;

    list->head = element;
    if (list->tail == NULL) {
        list->tail = element;
    }
}

void list_push_back(List *list, void *value) {
    Element *element = malloc(sizeof(Element));
    element->value = value;
    element->next = NULL;

    if (list->tail == NULL) {
        list->head = element;
    } else {
        list->tail->next = element;
    }
    list->tail = element;
}
