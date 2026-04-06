#include <stdio.h>
#include <stdlib.h>

int visited[100];

struct node {
    int data;
    struct node* next;
};

struct node* adj[100];

void addEdge(int u, int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            dfs(temp->data);
        }
        temp = temp->next;
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

    dfs(s);

    return 0;
}