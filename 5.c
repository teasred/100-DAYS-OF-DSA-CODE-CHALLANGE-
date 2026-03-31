#include <stdio.h>

int main() {
    int p, q;

    // Input sizes
    scanf("%d", &p);
    int arr1[100];

    for(int i = 0; i < p; i++) {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &q);
    int arr2[100];

    for(int i = 0; i < q; i++) {
        scanf("%d", &arr2[i]);
    }

    int i = 0, j = 0;

    // Merge process
    while(i < p && j < q) {
        if(arr1[i] <= arr2[j]) {
            printf("%d ", arr1[i]);
            i++;
        } else {
            printf("%d ", arr2[j]);
            j++;
        }
    }

    // Remaining elements of arr1
    while(i < p) {
        printf("%d ", arr1[i]);
        i++;
    }

    // Remaining elements of arr2
    while(j < q) {
        printf("%d ", arr2[j]);
        j++;
    }

    return 0;
}