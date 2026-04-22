#include <stdio.h>
#include <limits.h>

int graph[100][100], visited[100];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            graph[i][j] = INT_MAX;

    int u, v, w;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    visited[1] = 1;
    int edges = 0, minCost = 0;

    while(edges < n - 1) {
        int min = INT_MAX, x = 0, y = 0;

        for(int i = 1; i <= n; i++) {
            if(visited[i]) {
                for(int j = 1; j <= n; j++) {
                    if(!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        visited[y] = 1;
        minCost += min;
        edges++;
    }

    printf("%d", minCost);
    return 0;
}