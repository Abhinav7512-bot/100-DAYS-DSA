#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int v, dist;
} Node;

typedef struct {
    Node heap[MAX];
    int size;
} MinHeap;

void swap(Node *a, Node *b){
    Node t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap *h, int i){
    while(i && h->heap[i].dist < h->heap[(i-1)/2].dist){
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapifyDown(MinHeap *h, int i){
    int l = 2*i+1, r = 2*i+2, smallest = i;
    if(l < h->size && h->heap[l].dist < h->heap[smallest].dist)
        smallest = l;
    if(r < h->size && h->heap[r].dist < h->heap[smallest].dist)
        smallest = r;
    if(smallest != i){
        swap(&h->heap[i], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(MinHeap *h, int v, int dist){
    h->heap[h->size].v = v;
    h->heap[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

Node pop(MinHeap *h){
    Node root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapifyDown(h, 0);
    return root;
}

int isEmpty(MinHeap *h){
    return h->size == 0;
}

void dijkstra(int n, int graph[MAX][MAX], int src){
    int dist[MAX];
    for(int i=0;i<n;i++) dist[i] = INT_MAX;

    MinHeap h;
    h.size = 0;

    dist[src] = 0;
    push(&h, src, 0);

    while(!isEmpty(&h)){
        Node node = pop(&h);
        int u = node.v;

        for(int v=0; v<n; v++){
            if(graph[u][v] && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
                push(&h, v, dist[v]);
            }
        }
    }

    for(int i=0;i<n;i++)
        printf("Distance to %d = %d\n", i, dist[i]);
}

int main(){
    int n = 5;
    int graph[MAX][MAX] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };

    dijkstra(n, graph, 0);
    return 0;
}