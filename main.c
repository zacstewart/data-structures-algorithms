#include <stdio.h>
#include "test.h"
#include "test_array.h"
#include "test_list.h"

int main(int argc, char **argv) {
    printf("Running tests\n");

    test_array();
    test_list();

    test_clear();
}
