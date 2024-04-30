#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "crypto.h"

int main () {
	int num = 0;
	printf("Encrypt:\n");
	printf("1 - 1st lvl (Reverse + Vigenère cipher)\n2 - 2nd lvl (bit chaos)\n3 - 3rd lvl (everything)\n");
	printf("Decrypt:\n");
	printf("4 - 1st lvl decrypt\n5 - 2nd lvl decrypt\n6 - 3rd lvl decrypt\n");
	printf("\nEnter number: ");
	scanf("%d", &num);
	printf("\n");
	char input[999];
	unsigned char uinput[999];
	printf("Enter your text: ");
	char c;
	scanf("%c", &c);
	if(num != 5) {
	fgets(input, 999, stdin);
	} else {
	fgets((char *)uinput, 999, stdin);
	}

	if(num == 1) {
		//reverse
		char output[999];
		reverse(input, output);
		//vigenere
		char key[999];
		char final[999];
		printf("Enter key for Vigenère cipher: ");
		fgets(key, 999, stdin);
		vigenere_encrypt(key, output, final);
		printf("%s\n", final);
	} else if(num == 4) {
		//vigenere
		char key[999];
		char output[999];
		printf("Enter key for Vigenère cipher: ");
		fgets(key, 999, stdin);
		vigenere_decrypt(key, input, output);
		//reverse
		char final[999];
		reverse(output, final);
		printf("%s\n", final);
	} else if(num == 2) {
		unsigned char output[999];
		bit_encrypt(input, output);
		int size = strlen(input) - 1;
		for(int i=0; i < size; i++) {
			printf("%02x ", output[i]);
		}
	} else if(num == 5) { // what to input ?
		unsigned char output[999];
		bit_decrypt(uinput, output);
		printf("%s\n", output);
	} else if(num == 3) {
		//reverse
		char output[999];
		reverse(input, output);
		//vigenere
		char key[999];
		char second[999];
		printf("Enter key for Vigenère cipher: ");
		fgets(key, 999, stdin);
		vigenere_encrypt(key, output, second);
		//bits
		unsigned char final[999];
		bit_encrypt(input, final);
		int size = strlen(input) - 1;
		for(int i=0; i < size; i++) {
			printf("%02x ", output[i]);
		}
		printf("%s\n", final);
	}
	else if(num == 6) { // what to input?
		//bits
		unsigned char output[999];
		bit_encrypt(input, output);
		//vigenere
		char key[999];
		char second[999];
		printf("Enter key for Vigenère cipher: ");
		fgets(key, 999, stdin);
		vigenere_encrypt(key, (char *)output, second);
		//reverse
		char final[999];
		reverse(input, final);
		printf("%s\n", final);
	}
}