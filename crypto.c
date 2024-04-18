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
                charValue += bit_values[j];
            }
        }
        string[i] = charValue;
        charValue = 0;
    }
}

void reverse(const char* text, char* result) {
    int amount = strlen(text);
    int j = 0;
    for(int i = amount - 1; i >= 0; i--) {
        result[j] = text[i];
        j++;
    }
}

void vigenere_encrypt(const char* key, const char* text, char* result) {
    int textLength = strlen(text);
    int keyLength = strlen(key); // 6
    // Hello world! => Helloworld
    for (int i = 0, j = 0; i < textLength; i++, j++) {
        if (j >= keyLength) {
            j = 0;
        }
        char textSymbol = text[i];
        if (textSymbol >= 97 && textSymbol <= 122) {
            textSymbol -= 32; // to uppercase
        }
        // is not a letter
        if (!(textSymbol >= 65 && textSymbol <= 90)) {
            j--;
            result[i] = textSymbol;
            continue;
        }
        char keySymbol = key[j];
        if (keySymbol >= 97 && keySymbol <= 122) {
            keySymbol -= 32; // to uppercase
        }
        int shift = (int)keySymbol - 65; // 2
        char tmp = textSymbol + shift; // 88 (X) + 10
        if (tmp > 90) {
            tmp -= 26; // 
        }
        result[i] = tmp;
    }
}

void vigenere_decrypt(const char* key, const char* text, char* result) {
    int textLength = strlen(text);
    int keyLength = strlen(key); // 6
    // Hello world! => Helloworld
    for (int i = 0, j = 0; i < textLength; i++, j++) {
        if (j >= keyLength) {
            j = 0;
        }
        char textSymbol = text[i];
        if (textSymbol >= 97 && textSymbol <= 122) {
            textSymbol -= 32; // to uppercase
        }
        // is not a letter
        if (!(textSymbol >= 65 && textSymbol <= 90)) {
            j--;
            result[i] = textSymbol;
            continue;
        }
        char keySymbol = key[j];
        if (keySymbol >= 97 && keySymbol <= 122) {
            keySymbol -= 32; // to uppercase
        }
        int shift = (int)keySymbol - 65; // 2
        char tmp = textSymbol - shift; // 88 (X) - 10
        if (tmp < 65) {
            tmp += 26;
        }
        result[i] = tmp;
        printf("%d ", (int)tmp);
    }
}