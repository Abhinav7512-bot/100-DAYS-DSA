#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int preIndex = 0;

struct Node* build(int preorder[], int inorder[], int start, int end) {
    if (start > end) return NULL;

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = preorder[preIndex++];

    if (start == end) return node;

    int i;
    for (i = start; i <= end; i++)
        if (inorder[i] == node->data)
            break;

    node->left = build(preorder, inorder, start, i - 1);
    node->right = build(preorder, inorder, i + 1, end);

    return node;
}

void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];
    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    struct Node* root = build(preorder, inorder, 0, n - 1);

    postorder(root);
    return 0;
}