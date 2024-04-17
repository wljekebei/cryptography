#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void encode_char(const char character, bool bits[8]) {
    int bit_values[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int charValue = (int)character;

    for(int i = 0; i < 8; i++) {
        bits[i] = 0;
        if(bit_values[i] <= charValue) {
            bits[i] = 1;
            charValue -= bit_values[i];
        }
    }
}

char decode_char(const bool bits[8]) {
    int bit_values[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int charValue = 0;

    for(int i = 0; i < 8; i++) {
        if(bits[i] == 1) {
            charValue += bit_values[i];
        }
    }
    char symbol = (int)charValue;

    return symbol;
}

void encode_string(const char string[], bool bytes[strlen(string)+1][8]) {
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        encode_char(string[i], bytes[i]);
    }
}

void decode_string(const int rows, bool bytes[][8], char string[]) {
    int bit_values[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int charValue = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 8; j++) {
            if(bytes[i][j] == 1) {
                charValue += bit_values[i];
            }
        }
        string[i] = charValue;
    }
}