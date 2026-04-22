#include <stdio.h>

int adj[100][100], visited[100], n, m;

void dfs(int v) {
    visited[v] = 1;
    for(int i = 1; i <= n; i++) {
        if(adj[v][i] && !visited[i])
            dfs(i);
    }
}

int main() {
    int u, v;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    dfs(1);

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}