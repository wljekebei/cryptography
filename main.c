#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "crypto.h"

int main () {
	// task 3_1
	bool bits1[8];
	encode_char('Z', bits1);
	for(int i = 0; i < 8; i++){
		printf("%d", bits1[i]);
	}
	printf("\n");

	// task 3_2
	bool bits2[8] = {0,1,0,1,1,0,1,0};
	printf("%c\n", decode_char(bits2));

	// task 4_1
	char* text = "Hello, how are you?";
	const int len = strlen(text);
	bool bytes1[len+1][8];
	encode_string(text, bytes1);
	for(int j = 0; j <= len; j++){
		printf("%c: ", text[j]);
		for(int i = 0; i < 8; i++){
			printf("%d", bytes1[j][i]);
		}
		printf("\n");
	}

	// task 4_2
	bool bytes2[7][8] = {
		{0,1,0,0,1,0,0,0},
		{0,1,1,0,0,1,0,1},
		{0,1,1,0,1,1,0,0},
		{0,1,1,0,1,1,0,0},
		{0,1,1,0,1,1,1,1},
		{0,0,1,0,0,0,0,1},
		{0,0,0,0,0,0,0,0}
	};
	char string[7];
	decode_string(7, bytes2, string);
	printf("%s\n", string);

	// task 1
	char reversed[255];
	reverse("Hello world!", reversed);
	printf("%s\n", reversed);

	// task 2_1
	char encrypted[255];
	vigenere_encrypt("CoMPuTeR", "Hello world!", encrypted);
	printf("%s\n", encrypted);

	// task 2_2
	char decrypted[255];
	vigenere_decrypt("CoMPuTeR", encrypted, decrypted);
	printf("%s\n", decrypted);


	return 0;
}