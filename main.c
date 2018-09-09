#include <stdio.h>
#include "test.h"
#include "test_array.h"

int main(int argc, char **argv) {
    printf("Running tests\n");

    test_array();
    test_clear();
}
