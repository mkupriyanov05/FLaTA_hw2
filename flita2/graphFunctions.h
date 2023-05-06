#ifndef FLITA2_GRAPHFUNCTIONS_H
#define FLITA2_GRAPHFUNCTIONS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define NUMB 65
#define MATRIX_SIZE 5

typedef struct graph {
    int32_t dots[MATRIX_SIZE][MATRIX_SIZE];
    bool isWeighted;
    bool isOriented;
} Graph_t;

int graphInterpreter(int8_t *filename);

#endif //FLITA2_GRAPHFUNCTIONS_H
