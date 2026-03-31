#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int postIndex;

struct Node* build(int inorder[], int postorder[], int start, int end) {
    if (start > end) return NULL;

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = postorder[postIndex--];

    if (start == end) return node;

    int i;
    for (i = start; i <= end; i++)
        if (inorder[i] == node->data)
            break;

    node->right = build(inorder, postorder, i + 1, end);
    node->left = build(inorder, postorder, start, i - 1);

    return node;
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    postIndex = n - 1;

    struct Node* root = build(inorder, postorder, 0, n - 1);

    preorder(root);
    return 0;
}