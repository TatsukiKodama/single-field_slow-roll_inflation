#include "./utils_init.h"

double *init_array(int size) {
    double *array = malloc(size * sizeof(double));
    if (array == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return array;
}

