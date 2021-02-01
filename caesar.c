#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "caesar.h"

//Encodes the string `plaintext` using the Caesar cipher by
//shifting characters key` positions in the alphabet 
void encode(char *plaintext, int key)
{	
	for (int i = 0; i < strlen(plaintext); i++){
		int start = toupper(plaintext[i])-65;
		int placement = (start + key)%26;
		plaintext[i] = placement+65;
	}
}

//Decodes the string at `plaintext` using the Caesar cipher by
//shifting the characters `key` positions back in the alphabet
void decode(char *ciphertext, int key)
{
	for (int i = 0; i < strlen(ciphertext); i++){
		int start = toupper(ciphertext[i])-65;
		int placement = start-key < 0 ? start-key+26 : start-key%26;
		ciphertext[i] = placement+65;
	}
}
