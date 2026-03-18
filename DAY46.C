#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left)
            queue[rear++] = temp->left;

        if (temp->right)
            queue[rear++] = temp->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0)
        return 0;

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = createNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;

            if (leftIndex < n)
                nodes[i]->left = nodes[leftIndex];

            if (rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    levelOrder(nodes[0]);

    return 0;
}