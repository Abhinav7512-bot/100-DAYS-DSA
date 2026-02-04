#include <stdio.h>

int main() {
    int n, k, i;
    int arr[100];
    int comparisons = 0;
    int found = 0;

    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    printf("Enter key to search: ");
    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        comparisons++;   
        if(arr[i] == k) {
            found = 1;
            break;
        }
    }

   
    if(found)
        printf("Key found at position %d\n", i + 1);
    else
        printf("Key not found\n");

    printf("Total comparisons = %d\n", comparisons);

    return 0;
}
