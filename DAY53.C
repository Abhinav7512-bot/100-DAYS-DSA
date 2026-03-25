#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Pair {
    struct Node* node;
    int hd;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Pair* queue = (struct Pair*)malloc(1000 * sizeof(struct Pair));
    int front = 0, rear = 0;

    int hd_map[2000][100];
    int count[2000] = {0};

    int offset = 1000;

    queue[rear++] = (struct Pair){root, 0};

    while (front < rear) {
        struct Pair temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        int index = hd + offset;
        hd_map[index][count[index]++] = curr->data;

        if (curr->left)
            queue[rear++] = (struct Pair){curr->left, hd - 1};

        if (curr->right)
            queue[rear++] = (struct Pair){curr->right, hd + 1};
    }

    for (int i = 0; i < 2000; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++)
                printf("%d ", hd_map[i][j]);
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}