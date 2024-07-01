#include <stdio.h>

int countFunctionCalls() {
    static int count = 0;
    return ++count;
}

int main() {
    int i;

    for (i = 0; i < 5; i++) {
        int count = countFunctionCalls();
        printf("Function called %d times.\n", count);
    }

    return 0;
}
