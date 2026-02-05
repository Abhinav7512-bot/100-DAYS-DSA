#include <stdio.h>

void mergeLogs(int log1[], int n, int log2[], int m, int merged[]) {
    int i = 0, j = 0, k = 0;

    
    while (i < n && j < m) {
        if (log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }

    
    while (i < n) {
        merged[k++] = log1[i++];
    }

    
    while (j < m) {
        merged[k++] = log2[j++];
    }
}

int main() {
    int log1[] = {1, 4, 7, 10};
    int log2[] = {2, 3, 8, 12};

    int n = sizeof(log1) / sizeof(log1[0]);
    int m = sizeof(log2) / sizeof(log2[0]);

    int merged[n + m];

    mergeLogs(log1, n, log2, m, merged);

    printf("Merged Log: ");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
