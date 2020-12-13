#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Vigenère cipher and decipher
https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher

Made after a friend told me she was making it an uni, decided to give it a shot ;P
*/

char *text = "IF YOU READ THIS YOU WILL PASS THE EXAM";
char *worm = "CKQWC";

char *cipher(char *, char *);
char *decipher(char *, char *);
char *replicateWorm(char*, int);
int min(int, int);

int main() {
    printf("Original Text: %s\t|\tWorm: %s\n", text, worm);
    char *ciphred = cipher(text, worm);
    printf("Encrypted text: %s\n", ciphred);

    printf("Encrypted Text: %s\t|\tWorm: %s\n", ciphred, worm);
    char *deciphred = decipher(ciphred, worm);
    printf("Decrypted text: %s\n", deciphred);
}

char *cipher(char *a_text, char *a_worm) {
    //First: create result string by allocating as much memory as used for text
    char *result = malloc(strlen(a_text) * sizeof(char));

    if(strlen(a_text) != strlen(a_worm)) a_worm = replicateWorm(a_worm, strlen(a_text));

    for (int i = 0; i < strlen(a_text); i++) {
        char ascii_char_result = ' ';
        if (a_text[i] != ' ') {
            //Get the ASCII integer of the char in both text and it's corresponding worm and substract 64 to get the index in the alphabet
            //Little reminder: A in ascii is 65, every other capital letter comes after in increasing order (B is 66, C is 67...)
            //Just subtract 65 from the ascii integer to get the index  in the alphabeth -1 for the given char (So A is 9, B is 1...)
            //Start counting from 0 is needed because of how the modulo operation works (%26 counts number from 0 up to 25)
            int ascii_int_text = ((int)a_text[i]) - 65;
            int ascii_int_worm = ((int)a_worm[i]) - 65;

            //Compute encrypted char
            int ascii_int_result = (ascii_int_text + ascii_int_worm) % 26;

            //Now add 64 again to get the ascii integer from the alphabet index
            ascii_char_result = (char)(ascii_int_result + 65);
        }

        //Insert the character in the string
        result[i] = ascii_char_result;
    }
    return result;
}

char *decipher(char *a_text, char *a_worm) {
    //First: create result string by allocating as much memory as used for text
    char *result = malloc(strlen(a_text) * sizeof(char));

    if(strlen(a_text) != strlen(a_worm)) a_worm = replicateWorm(a_worm, strlen(a_text));

    for (int i = 0; i < strlen(a_text); i++) {
        char ascii_char_result = ' ';
        if (a_text[i] != ' ') {
            //Get the ASCII integer of the char in both text and it's corresponding worm and substract 64 to get the index in the alphabet
            //Little reminder: A in ascii is 65, every other capital letter comes after in increasing order (B is 66, C is 67...)
            //Just subtract 65 from the ascii integer to get the index  in the alphabeth -1 for the given char (So A is 9, B is 1...)
            //Start counting from 0 is needed because of how the modulo operation works (%26 counts number from 0 up to 25)
            int ascii_int_text = ((int)a_text[i]) - 65;
            int ascii_int_worm = ((int)a_worm[i]) - 65;

            //Compute encrypted char
            int ascii_int_result = (ascii_int_text - ascii_int_worm + 26) % 26;

            //Now add 64 again to get the ascii integer from the alphabet index
            ascii_char_result = (char)(ascii_int_result + 65);
        }

        //Insert the character in the string
        result[i] = ascii_char_result;
    }
    return result;
}

//Replicate the worm until it gets up to the desired length
char* replicateWorm(char* a_worm, int len){

    char* result1 = malloc(strlen(a_worm) * sizeof(char) * len);

    while(strlen(result1) < len){
        //The strncat(dest, src, n) functions copy the first n characterc of ssrc into dest
        //We simply copy the minimum between how many characters we still have left to copy (len - strlen(result1)) and the length of the worm
        //This will copy the full worm until the number of remaining characters will be less than the length of the worm, when it will copy just the first len - strlen(result1) of the worm
        result1 = strncat(result1, a_worm, min((len - strlen(result1)), strlen(a_worm)));
        printf("%s", a_worm);
    }

    return result1;

}

//Returns minimum between a and b
int min(int a, int b){
    // This is just a nice short way of writing
    // if(a <= b){
    // return a;
    // }else{
    // return b;
    // }
    //Could probably to a macro for it but idc atm

    return a <= b ? a : b;
}