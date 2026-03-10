#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int count;
} Deque;

Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->count = 0;
    return dq;
}

int empty(Deque* dq) {
    return dq->count == 0;
}

int size(Deque* dq) {
    return dq->count;
}

void push_front(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (empty(dq))
        dq->rear = newNode;
    else
        dq->front->prev = newNode;

    dq->front = newNode;
    dq->count++;
}

void push_back(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (empty(dq))
        dq->front = newNode;
    else
        dq->rear->next = newNode;

    dq->rear = newNode;
    dq->count++;
}

void pop_front(Deque* dq) {
    if (empty(dq)) return;

    Node* temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
    dq->count--;
}

void pop_back(Deque* dq) {
    if (empty(dq)) return;

    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
    dq->count--;
}

int front(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->front->data;
}

int back(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->rear->data;
}

void clear(Deque* dq) {
    while (!empty(dq))
        pop_front(dq);
}