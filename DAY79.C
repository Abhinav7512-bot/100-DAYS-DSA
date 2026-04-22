#include <stdio.h>
#include <limits.h>

int graph[100][100], dist[100], visited[100];

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

    int source;
    scanf("%d", &source);

    for(int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    for(int i = 1; i <= n; i++) {
        int min = INT_MAX, u = -1;

        for(int j = 1; j <= n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for(int v = 1; v <= n; v++) {
            if(graph[u][v] != INT_MAX && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for(int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    return 0;
}