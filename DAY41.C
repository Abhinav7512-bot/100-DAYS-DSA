#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    int N;
    scanf("%d", &N);

    char op[20];
    int value;

    for(int i = 0; i < N; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "enqueue") == 0)
        {
            scanf("%d", &value);
            enqueue(value);
        }
        else if(strcmp(op, "dequeue") == 0)
        {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}