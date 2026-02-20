#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long prefix = 0;
    long long count = 0;

    int size = 2 * n + 1;
    int offset = n;
    long long *freq = (long long*)calloc(size, sizeof(long long));

    freq[offset] = 1;

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        if(prefix + offset >= 0 && prefix + offset < size)
            count += freq[prefix + offset];

        if(prefix + offset >= 0 && prefix + offset < size)
            freq[prefix + offset]++;
    }

    printf("%lld", count);

    free(freq);
    return 0;
}