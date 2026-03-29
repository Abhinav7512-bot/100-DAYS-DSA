#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void init(struct Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void rightView(struct Node* root) {
    if (root == NULL) return;

    struct Queue q;
    init(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int size = q.rear - q.front;

        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue(&q);

            if (i == size - 1)
                printf("%d ", curr->data);

            if (curr->left) enqueue(&q, curr->left);
            if (curr->right) enqueue(&q, curr->right);
        }
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    rightView(root);
    return 0;
}