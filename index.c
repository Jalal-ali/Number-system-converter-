#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void decimalToBase(int decimal, int base, char *result) {
    char digits[] = "0123456789ABCDEF";
    char temp[65];
    int i = 0;

    if (decimal == 0) {
        strcpy(result, "0");
        return;
    }

    while (decimal > 0) {
        temp[i++] = digits[decimal % base];
        decimal /= base;
    }
    temp[i] = '\0';

    // reverse the string
    int len = strlen(temp);
    for (int j = 0; j < len; j++) {
        result[j] = temp[len - j - 1];
    }
    result[len] = '\0';
}

int main() {
    char number[65];
    int fromBase, toBase;

    printf("Enter the number: ");
    scanf("%s", number);

    printf("Choose Input Number System:\n");
    printf("1. Binary (2)\n");
    printf("2. Octal (8)\n");
    printf("3. Decimal (10)\n");
    printf("4. Hexadecimal (16)\n");
    printf("Enter choice: ");
    scanf("%d", &fromBase);

    printf("\nChoose Output Number System:\n");
    printf("1. Binary (2)\n");
    printf("2. Octal (8)\n");
    printf("3. Decimal (10)\n");
    printf("4. Hexadecimal (16)\n");
    printf("Enter choice: ");
    scanf("%d", &toBase);

    int bases[] = {2, 8, 10, 16};

    int decimal = strtol(number, NULL, bases[fromBase - 1]);

    char result[65];
    decimalToBase(decimal, bases[toBase - 1], result);

    printf("\nConverted Result: %s\n", result);

    return 0;
}
