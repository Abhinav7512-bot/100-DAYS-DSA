#include <stdio.h>
#include <stdlib.h>

int visited[100];

struct node {
    int data;
    struct node* next;
};

struct node* adj[100];

int queue[100], front = 0, rear = -1;

void addEdge(int u, int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void bfs(int s) {
    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        struct node* temp = adj[v];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                enqueue(temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, e, u, v, s;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    scanf("%d", &s);

    bfs(s);

    return 0;
}