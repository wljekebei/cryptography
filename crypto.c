#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int uscharlen(const unsigned char* str);

void encode_char(const unsigned char character, bool bits[8]) {
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

unsigned char decode_char(const bool bits[8]) {
    int bit_values[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int charValue = 0;

    for(int i = 0; i < 8; i++) {
        if(bits[i] == 1) {
            charValue += bit_values[i];
        }
    }
    char symbol = (int)charValue;

    return (unsigned char)symbol;
}

void encode_string(const char string[], bool bytes[][8]) {
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

void bit_encrypt(const char* text, unsigned char* result) {
    bool bits[8];
    bool encr[8];
    int len = strlen(text);
    for(int i = 0; i < len; i++) {
        encode_char(text[i], bits);
        for(int j = 0; j < 4; j += 2) {
            encr[j] = bits[j + 1];
            encr[j + 1] = bits[j];
        }
        for(int j = 0; j < 4; j++) {
            if(encr[j] != bits[j + 4]) {
                encr[j + 4] = 1;
            } else if(encr[j] == bits[j + 4]) {
                encr[j + 4] = 0;
            }
        }
        result[i] = decode_char(encr);
    }
}

void bit_decrypt(const unsigned char* text, unsigned char* result) {
    bool bits[8];
    bool encr[8];
    int len = uscharlen(text);
    for(int i = 0; i < len; i++) {
        encode_char(text[i], bits);
        for(int j = 4; j < 8; j++) {
            if(bits[j - 4] == bits[j]) {
                encr[j] = 0;
            } else if(bits[j - 4] != bits[j]) {
                encr[j] = 1;
            }
        }
        for(int j = 0; j < 4; j += 2) {
            encr[j] = bits[j + 1];
            encr[j + 1] = bits[j];
        }
        result[i] = decode_char(encr);
        break;
    }  
}

int uscharlen(const unsigned char* str) {
    int counter = 0;
    for(int i = 0; i < 9999; i++) {
        if(str[i] != '\0' && str[i] != (char)10) {
            counter++;
        } else {
            break;
        }
    }
    printf("COUNTER: %d\n", counter);
    return counter;
}