#include <stdio.h>
#include <stdlib.h>
#include "./utils_file.h"

FILE *open_file(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    return fp;
}
