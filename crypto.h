#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void reverse( char* text, char* result);

void vigenere_encrypt( char* key,  char* text, char* result);

void vigenere_decrypt( char* key,  char* text, char* result);

void encode_char( unsigned char character, bool bits[8]);

unsigned char decode_char( bool bits[8]);

void encode_string( char string[], bool bytes[][8]);

void decode_string( int rows, bool bytes[][8], char string[]);

void bit_encrypt( char* text, unsigned char* result);

void bit_decrypt( unsigned char* text, unsigned char* result);

int uscharlen(unsigned char* str);