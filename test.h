#ifndef ASSERT
#define ASSERT(condition, message) \
    if (condition) { \
        printf("."); \
    } else { \
        FAIL(message); \
    }
#endif

#ifndef FAIL
#define FAIL(message) \
    printf("\n%s:%d: %s\n", __FILE__, __LINE__, message); \
    return;
#endif

void test_clear();
