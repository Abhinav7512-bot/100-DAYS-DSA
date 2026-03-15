#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorder(struct Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int N;
    scanf("%d", &N);

    if(N == 0)
        return 0;

    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    if(arr[0] == -1)
        return 0;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[N];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while(i < N)
    {
        struct Node* current = queue[front++];

        if(i < N && arr[i] != -1)
        {
            current->left = newNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if(i < N && arr[i] != -1)
        {
            current->right = newNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    inorder(root);

    return 0;
}