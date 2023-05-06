#include "graphFunctions.h"


int printingToFile(Graph_t newGraph);

int graphInterpreter(int8_t *filename) {
    Graph_t newGraph;
    int8_t string[NUMB];
    int8_t delimiter[3] = " ";
    int8_t *weight;

    FILE *file1 = fopen(filename, "r");

    if (file1 == NULL) {
        puts("File opening error");
        exit(1);
    }

    newGraph.isWeighted = false;
    newGraph.isOriented = false;

    for (uint16_t y = 0; fgets(string, NUMB, file1) != NULL; y++) {
        uint16_t x = 0;
        weight = strtok(string, delimiter);
        while (strcmp(weight, "\n") != 0) {
            newGraph.dots[y][x] = atoi(weight);

            if (newGraph.dots[y][x] > 1)
                newGraph.isWeighted = true;

            if (newGraph.dots[y][x] != newGraph.dots[x][y] && y >= x) {
                newGraph.isOriented = true;
            }

            printf("%d ", newGraph.dots[y][x]);

            x++;
            weight = strtok(NULL, delimiter);
        }
        puts("");
    }

    fclose(file1);

    printingToFile(newGraph);

    return 0;
}


int printingToFile(Graph_t newGraph) {
    FILE *file2 = fopen("../cmake-build-debug/stdout.dot", "w");

    if (file2 == NULL) {
        puts("File opening error");
        exit(1);
    }

    int8_t *orientation;
    if (newGraph.isOriented) {
        orientation = "->";
        fputs("digraph graph_name {\n", file2);
    } else {
        orientation = "--";
        fputs("graph graph_name {\n", file2);
    }

    for (uint32_t y = 0; y < MATRIX_SIZE; ++y) {
        for (uint32_t x = y; x < MATRIX_SIZE; ++x) {
            if (newGraph.dots[y][x] != 0 || newGraph.dots[x][y] != 0) {

                if (newGraph.dots[y][x] > newGraph.dots[x][y])
                    fprintf(file2, "%d %s %d", y, orientation, x);
                else
                    fprintf(file2, "%d %s %d", x, orientation, y);

                if (newGraph.isWeighted == true)
                    fprintf(file2, " [label=%d, weight=%d, penwidth=%d]",
                            newGraph.dots[y][x], newGraph.dots[y][x], newGraph.dots[y][x]);
                else
                    fputs(" ", file2);

                fputs("\n", file2);
            }
        }
    }

    fputs("}\n", file2);

    fclose(file2);
    return 0;
}