#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void stringReverse (char*);

//decimal to binary

char* decimalToBinary(int decimal)
{
	char* binary = (char*)malloc(33);
	int i = 0;
	
	while(decimal) {
		binary [i++] = '0' + (decimal & 1);
		decimal >>= 1;
		binary[i] = '\0';
		stringReverse(binary);
		return binary;
	}
}
	
//binary to decimal

int* binaryToDecimal(char binary [])
{
	int decimal = 0;
	int length = strlen(binary);
	for(int i = 0; i< length; i++){
		decimal = decimal * 2 + (binary[i] - '0');
	}
	return decimal;
}

char* decimlToOctal(char decimal[])
{	
	char* octal = (char*)malloc(12);
	if (octal == NULL){
		printf("Memory allocation has Failed.\n");
		exit(1);
		}
	sprintf(octal, "%o", decimal);
	return octal;
	}

char* octalToDecimal(char octal[])
{
	return 0;
	}

char* hexadecimalToBinary(char hex[])
{	
	return 0;
	}

char* binaryToHexadecimal(char binary[])
{
	return 0;
	}

//menu driver

int main(){
	int choice;
	while(1){
		printf("\nMenu\n");
		printf("1.) Decimal To Binary\n");
		printf("2.)Binary To Decimal\n");
		printf("3.) Decimal To Octal\n");
		printf("4.) Octal To Decimal\n");
		printf("5.) Hexadecimal To Binary\n");
		printf("6.) Binary To Hexadecimal\n");
		printf("7.) Exit\n");
		printf("Enter Number: \n");
		scanf("%d", &choice);
	}
	
	if (choice == 7){
		printf("SHUTTING DOWN ...\n");
		break;
	}
	
	char intput[100];
	switch (choice) {
		case 1:
			printf("Enter decimal number: ");
			scanf("%d", &choice);
			char* result = decimalToBinary(choice);
			printf("Decimal To Binary: %s\n", result);
			free(result);
			break;
		case 2:
			printf("Enter a Binary Number: ");
			scanf("%s", input);
			//result
			int binaryResult = binaryToDecimal(input);
			printf("Binary to Decimmal %d\n", result);
			break;
		case 3:
			printf("Enter decimal number: ");
			scanf("%d", &choice); 
			//result
			result = decimalToOctal(choice);
			printf("Decimal to Octal: %s\n", result);
			free(result);
			break;
		case 4:
			printf("");
			//may need to be changed
			scanf("%d", &choice);
			//result
			printf("x to y: %s\n", resultname);
			free(result);
			break;
		case 5:
			printf("");
			//may need to be changed
			scanf("%d", &choice);
			//result
			printf("x to y: %s\n", resultname);
			free(result);
			break;
		case 6:
			printf("");
			//may need to be changed
			scanf("%d", &choice);
			//result
			printf("x to y: %s\n", resultname);
			free(result);
			break;
		default:
			printf("please enter a valid" "option.\n");
			
					}
			}
	return 0;


void stringReverse(char* str){
	int i = 0;
	int j = strlen(str) -1;
	while (i < j){
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
}
