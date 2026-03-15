#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if(rear == NULL)
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

int dequeue()
{
    if(front == NULL)
        return -1;

    struct Node* temp = front;
    int value = temp->data;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
    return value;
}

int isEmpty()
{
    return front == NULL;
}

int main()
{
    int N, x;
    scanf("%d", &N);

    int stack[N];
    int top = -1;

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    while(!isEmpty())
        stack[++top] = dequeue();

    while(top != -1)
        enqueue(stack[top--]);

    while(!isEmpty())
        printf("%d ", dequeue());

    return 0;
}