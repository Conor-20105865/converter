#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void stringReverse(char*);

char* decimalToBinary(int decimal) {
    char* binary = (char*)malloc(33);
    int i = 0;
    
    // Handle 0 input
    if (decimal == 0) {
        binary[0] = '0';
        binary[1] = '\0';
        return binary;
    }
    //convert decimal to binary using bitwise operator
    while(decimal) {
//get least significant bit of decimal
        binary[i++] = '0' + (decimal & 1);
//right shift decimal by 1
        decimal >>= 1;
    }
    binary[i] = '\0';
//reverse the binary string
    stringReverse(binary);
    return binary;
}

int binaryToDecimal(char binary[]) {
    int decimal = 0;
    int length = strlen(binary);
//process each digit building the decimal value
    for(int i = 0; i < length; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            return -1; // Invalid binary input
        }
        decimal = decimal * 2 + (binary[i] - '0');
    }
    return decimal;
}

char* decimalToOctal(int decimal) {
//allocate memory for octal string of 32 bit number
    char* octal = (char*)malloc(12);
    if (octal == NULL) {
        printf("Memory allocation has Failed.\n");
        exit(1);
    }
//sprintf built in octal conversion function
    sprintf(octal, "%o", decimal);
    return octal;
}

char* octalToDecimal(char octal[]) {
    char* decimal = (char*)malloc(12);
    if (decimal == NULL) {
        printf("Memory allocation has Failed.\n");
        exit(1);
    }
    
    // Convert octal string to integer
    int dec = 0;
    for (int i = 0; octal[i] != '\0'; i++) {
        if (octal[i] < '0' || octal[i] > '7') {
            free(decimal);
            return NULL; // Invalid octal input
        }
        dec = dec * 8 + (octal[i] - '0');
    }
    
    sprintf(decimal, "%d", dec);
    return decimal;
}

char* hexadecimalToBinary(char hex[]) {
    char* binary = (char*)malloc(33);
    if (binary == NULL) {
        printf("Memory allocation has Failed.\n");
        exit(1);
    }
    
    binary[0] = '\0';
    char temp[5];
    //converts each hex digit to binary 4 bit
    for(int i = 0; hex[i] != '\0'; i++) {
        switch(hex[i]) {
            case '0': strcat(binary, "0000"); break;
            case '1': strcat(binary, "0001"); break;
            case '2': strcat(binary, "0010"); break;
            case '3': strcat(binary, "0011"); break;
            case '4': strcat(binary, "0100"); break;
            case '5': strcat(binary, "0101"); break;
            case '6': strcat(binary, "0110"); break;
            case '7': strcat(binary, "0111"); break;
            case '8': strcat(binary, "1000"); break;
            case '9': strcat(binary, "1001"); break;
            case 'A': case 'a': strcat(binary, "1010"); break;
            case 'B': case 'b': strcat(binary, "1011"); break;
            case 'C': case 'c': strcat(binary, "1100"); break;
            case 'D': case 'd': strcat(binary, "1101"); break;
            case 'E': case 'e': strcat(binary, "1110"); break;
            case 'F': case 'f': strcat(binary, "1111"); break;
            default: 
                free(binary);
                return NULL; // Invalid hex input
        }
    }
    return binary;
}

char* binaryToHexadecimal(char binary[]) {
    char* hex = (char*)malloc(9);
    if (hex == NULL) {
        printf("Memory allocation has Failed.\n");
        exit(1);
    }
    
    int len = strlen(binary);
    int hexIndex = 0;
    
    // Pad with zeros if needed
    char padded[33] = {0};
    int padding = (4 - (len % 4)) % 4;
    for (int i = 0; i < padding; i++) {
        padded[i] = '0';
    }
    strcat(padded, binary);
    
    // Convert each group of 4 bits to hex
    for (int i = 0; padded[i] != '\0'; i += 4) {
        int value = 0;
        for (int j = 0; j < 4; j++) {
            if (padded[i + j] != '0' && padded[i + j] != '1') {
                free(hex);
                return NULL; // Invalid binary input
            }
            value = value * 2 + (padded[i + j] - '0');
        }
        hex[hexIndex++] = value < 10 ? '0' + value : 'A' + (value - 10);
    }
    hex[hexIndex] = '\0';
    return hex;
}

//main function for menu interface
int main() {
    int choice;
    char input[100];
    
    while(1) {
//options
        printf("\nMenu\n");
        printf("1.) Decimal To Binary\n");
        printf("2.) Binary To Decimal\n");
        printf("3.) Decimal To Octal\n");
        printf("4.) Octal To Decimal\n");
        printf("5.) Hexadecimal To Binary\n");
        printf("6.) Binary To Hexadecimal\n");
        printf("7.) Exit\n");
        printf("Enter Number: ");
        scanf("%d", &choice);
        
        if (choice == 7) {
            printf("SHUTTING DOWN ...\n");
            break;
        }
        
        char* result;
        int decimalResult;

//switch case for menu options
//process each user option
        switch (choice) {
            case 1:
                printf("Enter decimal number: ");
                scanf("%d", &decimalResult);
                result = decimalToBinary(decimalResult);
                printf("Decimal To Binary: %s\n", result);
                free(result);
                break;
                
            case 2:
                printf("Enter a Binary Number: ");
                scanf("%s", input);
                decimalResult = binaryToDecimal(input);
                if (decimalResult == -1) {
                    printf("Invalid binary input!\n");
                } else {
                    printf("Binary to Decimal: %d\n", decimalResult);
                }
                break;
                
            case 3:
                printf("Enter decimal number: ");
                scanf("%d", &decimalResult);
                result = decimalToOctal(decimalResult);
                printf("Decimal to Octal: %s\n", result);
                free(result);
                break;
                
            case 4:
                printf("Enter octal number: ");
                scanf("%s", input);
                result = octalToDecimal(input);
                if (result == NULL) {
                    printf("Invalid octal input!\n");
                } else {
                    printf("Octal to Decimal: %s\n", result);
                    free(result);
                }
                break;
                
            case 5:
                printf("Enter hexadecimal number: ");
                scanf("%s", input);
                result = hexadecimalToBinary(input);
                if (result == NULL) {
                    printf("Invalid hexadecimal input!\n");
                } else {
                    printf("Hexadecimal to Binary: %s\n", result);
                    free(result);
                }
                break;
                
            case 6:
                printf("Enter binary number: ");
                scanf("%s", input);
                result = binaryToHexadecimal(input);
                if (result == NULL) {
                    printf("Invalid binary input!\n");
                } else {
                    printf("Binary to Hexadecimal: %s\n", result);
                    free(result);
                }
                break;
                
            default:
                printf("Please enter a valid option.\n");
        }
    }
    return 0;
}
//function for string reversal
void stringReverse(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
}