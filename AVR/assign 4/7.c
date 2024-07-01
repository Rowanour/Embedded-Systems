#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements in the arrays: ");
    scanf("%d", &n);

    int sourceArray[n];
    int destinationArray[n];

    printf("Enter %d elements for the source array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &sourceArray[i]);
    }

    int *srcPtr = sourceArray;
    int *destPtr = destinationArray;

    for (int i = 0; i < n; i++) {
        *destPtr = *srcPtr;
        destPtr++;
        srcPtr++;
    }

    printf("Copied Array (destinationArray): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", destinationArray[i]);
    }
    printf("\n");

    return 0;
}
