#include <stdlib.h>

typedef struct Element {
    void *value;
    struct Element *previous;
    struct Element *next;
} Element;

typedef struct List {
    Element *head;
    Element *tail;
} List;

List list_new();

void list_delete(List *);

void *list_pop_front(List *list);

void *list_pop_back(List *list);

void list_push_front(List *list, void *value);

void list_push_back(List *list, void *value);
