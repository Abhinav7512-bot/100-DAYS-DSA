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

int dfs(int v, int parent) {
    visited[v] = 1;

    struct node* temp = adj[v];
    while (temp != NULL) {
        int u = temp->data;

        if (!visited[u]) {
            if (dfs(u, v))
                return 1;
        } else if (u != parent) {
            return 1;
        }

        temp = temp->next;
    }
    return 0;
}

int main() {
    int n, e, u, v;

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

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}