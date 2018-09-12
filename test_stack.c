#include <stdio.h>
#include "test.h"
#include "list.h"
#include "stack.h"

void test_stack_push() {
    List list = list_new();

    int v1 = 1;
    int v2 = 2;
    int v3 = 3;
    stack_push(&list, &v1);
    stack_push(&list, &v2);
    stack_push(&list, &v3);

    list_delete(&list);
}


void test_stack_top() {
    List list = list_new();

    int v1 = 1;
    stack_push(&list, &v1);
    ASSERT(*(int *)stack_top(&list) == 1, "Element mismatch 1");

    int v2 = 2;
    stack_push(&list, &v2);
    ASSERT(*(int *)stack_top(&list) == 2, "Element mismatch 2");

    int v3 = 3;
    stack_push(&list, &v3);
    ASSERT(*(int *)stack_top(&list) == 3, "Element mismatch 3");


    list_delete(&list);
}

void test_stack_pop() {
    List list = list_new();

    int v1 = 1;
    int v2 = 2;
    int v3 = 3;
    stack_push(&list, &v1);
    stack_push(&list, &v2);
    stack_push(&list, &v3);

    ASSERT(*(int *)stack_pop(&list) == 3, "Element mismatch 3");
    ASSERT(*(int *)stack_pop(&list) == 2, "Element mismatch 2");
    ASSERT(*(int *)stack_pop(&list) == 1, "Element mismatch 1");

    list_delete(&list);
}

void test_stack_empty() {
    List list = list_new();

    ASSERT(stack_empty(&list), "Stack should be empty");

    int v1 = 1;
    stack_push(&list, &v1);
    ASSERT(!stack_empty(&list), "Stack should not be empty");

    stack_pop(&list);
    ASSERT(stack_empty(&list), "Stack should be empty");

    list_delete(&list);
}

void test_stack() {
    printf("Testing stack\n");
    test_stack_push();
    test_stack_top();
    test_stack_pop();
    test_stack_empty();
}
