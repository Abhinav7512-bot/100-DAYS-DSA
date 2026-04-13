#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

void bellmanFord(int n, int m, Edge edges[], int src){
    int dist[MAX];

    for(int i=0;i<n;i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for(int i=1;i<=n-1;i++){
        for(int j=0;j<m;j++){
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int j=0;j<m;j++){
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    for(int i=0;i<n;i++){
        printf("Distance to %d = %d\n", i, dist[i]);
    }
}

int main(){
    int n = 5, m = 8;

    Edge edges[] = {
        {0,1,-1},
        {0,2,4},
        {1,2,3},
        {1,3,2},
        {1,4,2},
        {3,2,5},
        {3,1,1},
        {4,3,-3}
    };

    bellmanFord(n, m, edges, 0);
    return 0;
}