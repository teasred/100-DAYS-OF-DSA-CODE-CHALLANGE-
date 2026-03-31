#include <stdio.h>

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int arr[100];

    // Input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int start = 0;
    int end = n - 1;

    // Reverse using two pointers
    while(start < end) {
        // Swap
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    // Print reversed array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}