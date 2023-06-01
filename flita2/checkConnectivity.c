#include "checkConnectivity.h"

void dfs(Graph_t *graph, int dotIndex, bool *visitedDots, int *dotsAmount);

void checkGraphConnection(Graph_t *graph) {
    int dotsAmount = 0;
    bool *visitedDots;
    visitedDots = (bool*)calloc(graph->dotsAmount, sizeof(bool));
    dfs(graph, 0, visitedDots, &dotsAmount);
    free(visitedDots);
    if (graph->dotsAmount == dotsAmount)
        puts("Graph is connected");
    else
        puts("Graph is not connected");
}

void dfs(Graph_t *graph, int dotIndex, bool *visitedDots, int *dotsAmount) {
    (*dotsAmount)++;
    visitedDots[dotIndex] = true;
    for (int i = 0; i < graph->edgesNum; i++) {
        if (graph->matrix[dotIndex][i] == 1) {
            for (int j = 0; j < graph->dotsNumber; j++) {
                if (graph->matrix[j][i] == 1 && visitedDots[j] == 0) {
                    dfs(graph, j, visitedDots, dotsAmount);
                }
            }
        }
    }
}
