#include <stdio.h>
#include <stdlib.h>

int V;

int dfs(int v, int **adj, int visited[], int recStack[]) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[v][i]) {
            if (!visited[i] && dfs(i, adj, visited, recStack))
                return 1;
            else if (recStack[i])
                return 1;
        }
    }

    recStack[v] = 0;
    return 0;
}

int hasCycle(int **adj) {
    int visited[V], recStack[V];

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack))
                return 1;
        }
    }

    return 0;
}

int main() {
    scanf("%d", &V);

    int **adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        adj[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++)
            scanf("%d", &adj[i][j]);
    }

    if (hasCycle(adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}