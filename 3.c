#include <stdio.h>

int main() {
    int n, k;
    
    // Input size
    scanf("%d", &n);
    
    int arr[100];
    
    // Input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input key
    scanf("%d", &k);
    
    int found = 0;
    int comparisons = 0;
    
    // Linear Search
    for(int i = 0; i < n; i++) {
        comparisons++;
        
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("Not Found\n");
    }
    
    printf("Comparisons = %d\n", comparisons);
    
    return 0;
}