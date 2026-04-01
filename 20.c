#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix_sum = 0;
    int count = 0;

    // Simple hash map using array (range assumption)
    int freq[2 * MAX + 1] = {0};

    // To handle negative sums (shift index)
    int offset = MAX;

    freq[offset] = 1; // prefix_sum = 0 already seen once

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // If this prefix sum was seen before
        if(freq[prefix_sum + offset] > 0) {
            count += freq[prefix_sum + offset];
        }

        // Increase frequency
        freq[prefix_sum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}