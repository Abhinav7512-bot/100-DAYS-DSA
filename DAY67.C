#include <stdio.h>
#include <stdlib.h>

int V;

void dfs(int v, int **adj, int visited[], int stack[], int *top) {
    visited[v] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i])
            dfs(i, adj, visited, stack, top);
    }

    stack[++(*top)] = v;
}

void topoSort(int **adj) {
    int visited[V], stack[V], top = -1;

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i, adj, visited, stack, &top);
    }

    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}

int main() {
    scanf("%d", &V);

    int **adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        adj[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++)
            scanf("%d", &adj[i][j]);
    }

    topoSort(adj);
    return 0;
}