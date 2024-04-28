#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "crypto.h"

void wait();

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
	printf("Enter your text: ");
	wait();
	fgets(input, 999, stdin);

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
	}

	// // task 3_1
	// bool bits1[8];
	// encode_char('Z', bits1);
	// for(int i = 0; i < 8; i++){
	// 	printf("%d", bits1[i]);
	// }
	// printf("\n");

	// // task 3_2
	// bool bits2[8] = {0,1,0,1,1,0,1,0};
	// printf("%c\n", decode_char(bits2));

	// // task 4_1
	// const char* text = "Hello, how are you?";
	// const int len = strlen(text);
	// bool bytes1[len+1][8];
	// encode_string(text, bytes1);
	// for(int j = 0; j <= len; j++){
	// 	printf("%c: ", text[j]);
	// 	for(int i = 0; i < 8; i++){
	// 		printf("%d", bytes1[j][i]);
	// 	}
	// 	printf("\n");
	// }

	// // task 4_2
	// bool bytes2[7][8] = {
	// 	{0,1,0,0,1,0,0,0},
	// 	{0,1,1,0,0,1,0,1},
	// 	{0,1,1,0,1,1,0,0},
	// 	{0,1,1,0,1,1,0,0},
	// 	{0,1,1,0,1,1,1,1},
	// 	{0,0,1,0,0,0,0,1},
	// 	{0,0,0,0,0,0,0,0}
	// };
	// char string[7];
	// decode_string(7, bytes2, string);
	// printf("%s\n", string);

	// // task 1
	// char reversed[255];
	// reverse("Hello world!", reversed);
	// printf("%s\n", reversed);

	// // task 2_1
	// char encrypted[255];
	// char key[] = "CoMPuTeR";
	// char inp[] = "Hello world!";
	// vigenere_encrypt(key, inp, encrypted);
	// printf("%s\n", encrypted);

	// // task 2_2
	// char decrypted[255];
	// vigenere_decrypt("CoMPuTeR", encrypted, decrypted);
	// printf("%s\n", decrypted);

	// // task 5_1
	// unsigned char encrypted2[100];
	// bit_encrypt("Hello", encrypted2);
	// for(int i=0; i < 5;i++) {
	// 	printf("%02x ", encrypted2[i]);
	// 	//80 9c 95 95 96 11 bc 96 b9 95 9d 10
	// }
	// printf("\n");

	// // task 5_2
	// unsigned char decrypted2[100];
	// bit_decrypt(encrypted2, decrypted2);
	// printf("%s\n", decrypted2);

	// return 0;
}

void wait() {
	char c;
	scanf("%c", &c);
}