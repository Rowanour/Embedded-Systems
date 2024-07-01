#include <stdio.h>

char up(char letter);

int main() {
    char low;
    
    printf("Enter a lowercase letter: ");
    scanf("%c", &low);
    
    char u = up(low);
    printf("Uppercase equivalent: %c\n", u);
    
    return 0;
}

char up(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        // lowercase to uppercase by subtracting the ASCII difference
        return letter - (32);
    } else {
        // unchanged if the input is not a lowercase letter
        return letter;
    }
}