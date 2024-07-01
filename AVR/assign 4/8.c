#include <stdio.h>

char toUpperCase(char lowercaseChar) {
    if (lowercaseChar >= 'a' && lowercaseChar <= 'z') {
        return lowercaseChar - 32;
    } else {
        return lowercaseChar;
    }
}

int main() {
    char lowercaseLetter;

    printf("Enter a lowercase letter: ");
    scanf(" %c", &lowercaseLetter);

    char uppercaseLetter = toUpperCase(lowercaseLetter);

    printf("Uppercase equivalent: %c\n", uppercaseLetter);

    return 0;
}
