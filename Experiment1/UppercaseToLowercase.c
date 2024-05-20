#include <stdio.h>


int main() {
    char str[100];
    int i;

    printf("Enter an uppercase string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        str[i] = str[i]+32;
        
    }

    printf("Lowercase string: %s\n", str);

    return 0;
}
