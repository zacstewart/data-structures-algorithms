#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "array.h"
#include "test.h"
#include "test_array.h"

void test_array_insert() {
    Array array = array_new(sizeof(uint8_t), 1);
    int value = 42;
    ASSERT(array_insert(&array, 0, &value) == 1, "Array insert failed");
    ASSERT(array_insert(&array, 1, &value) == 0, "Array overflow insert allowed");

    array_delete(array);
}

void test_array_get() {
    Array array = array_new(sizeof(uint8_t), 1);
    int value = 42;

    array_insert(&array, 0, &value);

    ASSERT(*(int *) array_get(&array, 0) == 42, "Element 0 mismatch");
    ASSERT(array_get(&array, 1) == NULL, "Index past end of array should return null");

    array_delete(array);
}

void test_array_chars() {
    Array array = array_new(sizeof(char), 3);

    char z = 'z';
    char a = 'a';
    char c = 'c';

    array_insert(&array, 0, &z);
    array_insert(&array, 1, &a);
    array_insert(&array, 2, &c);

    ASSERT(*(char *)array_get(&array, 0) == 'z', "Element 0 mismatch");
    ASSERT(*(char *)array_get(&array, 1) == 'a', "Element 1 mismatch");
    ASSERT(*(char *)array_get(&array, 2) == 'c', "Element 2 mismatch");

    array_delete(array);
}

void test_array_strings() {
    Array array = array_new(sizeof(char *), 3);

    char *a = "zac";
    char *b = "made";
    char *c = "array";

    array_insert(&array, 0, &a);
    array_insert(&array, 1, &b);
    array_insert(&array, 2, &c);

    ASSERT(strcmp(*(char **)array_get(&array, 0), "zac") == 0, "Element 0 mismatch");
    ASSERT(strcmp(*(char **)array_get(&array, 1), "made") == 0, "Element 1 mismatch");
    ASSERT(strcmp(*(char **)array_get(&array, 2), "array") == 0, "Element 2 mismatch");

    array_delete(array);
}

void test_array_long_long() {
    Array array = array_new(sizeof(long long), 3);

    long long v1 = 1;
    long long v2 = 2;
    long long v256 = 256;

    array_insert(&array, 0, &v1);
    array_insert(&array, 1, &v2);
    array_insert(&array, 2, &v256);

    ASSERT(*(long long *)array_get(&array, 0) == 1, "Element 0 mismatch");
    ASSERT(*(long long *)array_get(&array, 1) == 2, "Element 1 mismatch");
    ASSERT(*(long long *)array_get(&array, 2) == 256, "Element 2 mismatch");

    array_delete(array);
}

void test_array_huge() {
    Array array = array_new(sizeof(long), 1000000);
    for (size_t i = 0; i < 1000000; i++) {
        if (!array_insert(&array, i, &i)) {
            FAIL("Insert failed");
        }

        if (*(size_t *)array_get(&array,  i) != i) {
            FAIL("Element mismatch");
        }
    }

    array_delete(array);
}

void test_array_performance() {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    Array array = array_new(sizeof(long), 1000000);
    for (size_t i = 0; i < 1000000; i++) {
        array_insert(&array, i, &i);
        array_get(&array,  i);
    }
    array_delete(array);

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
    printf("\narray len 1000000 performance: %llu\n", delta_us);
}

void test_array() {
    printf("Testing array\n");
    test_array_insert();
    test_array_get();
    test_array_chars();
    test_array_strings();
    test_array_long_long();
    test_array_huge();
    test_array_performance();
}
