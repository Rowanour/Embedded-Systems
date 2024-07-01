#include <stdio.h>

struct std {
    char arx[20];
    double name;
    double gpa;
};

int main() {
    printf("%lu", sizeof(struct std));
    return 0;
}
