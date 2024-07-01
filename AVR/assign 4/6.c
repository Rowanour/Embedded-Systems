#include <stdio.h>

int main() {
    int n;

    // ask the user for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];

    // input elements into the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int *ptr1 = arr;
    int *ptr2 = arr + n - 1;
// swap
    while (ptr1 < ptr2) {
        int temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;

        ptr1++;
        ptr2--;
    }

    // print
    printf("Reversed Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
