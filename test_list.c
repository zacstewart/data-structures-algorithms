#include <stdio.h>
#include <sys/time.h>
#include "list.h"
#include "test.h"

void test_list_push_front() {
    List list = list_new();

    int v1 = 1;
    int v2 = 2;
    int v3 = 3;
    list_push_front(&list, &v1);
    list_push_front(&list, &v2);
    list_push_front(&list, &v3);

    list_delete(&list);
}

void test_list_pop_front() {
    List list = list_new();

    int v1 = 1;
    int v2 = 2;
    int v3 = 3;
    list_push_front(&list, &v1);
    list_push_front(&list, &v2);
    list_push_front(&list, &v3);

    ASSERT(*(int *)list_pop_front(&list) == 3, "Element mismatch 3");
    ASSERT(*(int *)list_pop_front(&list) == 2, "Element mismatch 2");
    ASSERT(*(int *)list_pop_front(&list) == 1, "Element mismatch 1");

    list_delete(&list);
}

void test_list_push_back() {
    List list = list_new();

    int v1 = 1;
    int v2 = 2;
    int v3 = 3;
    list_push_back(&list, &v1);
    list_push_back(&list, &v2);
    list_push_back(&list, &v3);

    ASSERT(*(int *)list_pop_front(&list) == 1, "Element mismatch 1");
    ASSERT(*(int *)list_pop_front(&list) == 2, "Element mismatch 2");
    ASSERT(*(int *)list_pop_front(&list) == 3, "Element mismatch 3");

    list_delete(&list);
}

void test_list_pop_back() {
    List list = list_new();

    int v1 = 1;
    int v2 = 2;
    int v3 = 3;
    list_push_back(&list, &v1);
    list_push_back(&list, &v2);
    list_push_back(&list, &v3);

    ASSERT(*(int *)list_pop_back(&list) == 3, "Element mismatch 3");
    ASSERT(*(int *)list_pop_back(&list) == 2, "Element mismatch 2");
    ASSERT(*(int *)list_pop_back(&list) == 1, "Element mismatch 1");

    list_delete(&list);
}

void test_list_performance_push_pop_front() {
    size_t len = 1000000;
    struct timespec start, end;
    size_t vals[len];
    for (size_t i = 0; i < len; i++) {
        vals[i] = i;
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    List list = list_new();
    for (size_t i = 0; i < len; i++) {
        list_push_front(&list, &vals[i]);
    }

    size_t element;
    for (size_t i = 0; i < len; i++) {
        element = *(size_t *)list_pop_front(&list);
        if (element != (len - i - 1)) {
            FAIL("Element mismatch");
        }
    }

    list_delete(&list);

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
    printf("\nlist len %zu push/pop front performance: %llu\n", len, delta_us);
}

void test_list_performance_push_pop_back() {
    size_t len = 1000000;
    struct timespec start, end;
    size_t vals[len];
    for (size_t i = 0; i < len; i++) {
        vals[i] = i;
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    List list = list_new();
    for (size_t i = 0; i < len; i++) {
        list_push_back(&list, &vals[i]);
    }

    size_t element;
    for (size_t i = 0; i < len; i++) {
        element = *(size_t *)list_pop_back(&list);
        if (element != (len - i - 1)) {
            FAIL("Element mismatch");
        }
    }

    list_delete(&list);

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
    printf("\nlist len %zu push/pop back performance: %llu\n", len, delta_us);
}

void test_list() {
    printf("Testing list\n");
    test_list_push_front();
    test_list_pop_front();
    test_list_push_back();
    test_list_pop_back();
    test_list_performance_push_pop_front();
    test_list_performance_push_pop_back();
}
