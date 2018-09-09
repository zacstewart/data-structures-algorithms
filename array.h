typedef struct {
    size_t size;
    size_t elem_size;
    char *data;
} Array;

Array array_new(size_t, size_t);

void array_delete(Array);

/**
 * Returns 1 if insert is success, 0 otherwise.
 */
int array_insert(Array*, size_t, void *);

/**
 * Returns pointer to element or NULL if out of bounds
 */
void * array_get(Array*, size_t);
