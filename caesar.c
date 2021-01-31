#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "caesar.h"
#include <assert.h>

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


int main() {
	
	char msg[] = {'s','e','c','r','e','t','\0'};
	
	printf("msg before encoding: %s\n",msg);
	assert(strcmp(msg,"secret") == 0);
	encode(msg,1);
	printf("msg after encoding: %s\n",msg);
	assert(strcmp(msg,"TFDSFU") == 0);
	decode(msg,1);
	printf("msg after decoding again: %s\n",msg);
	assert(strcmp(msg,"SECRET") == 0);

	char msgUpper[] = {'s','E','c','R','e','T','\0'};

	printf("\nmsg before encoding: %s\n",msgUpper);
        assert(strcmp(msgUpper,"sEcReT") == 0);
        encode(msgUpper,1);
	printf("msg after encoding: %s\n",msgUpper);
	assert(strcmp(msgUpper,"TFDSFU") == 0);
        decode(msgUpper,1);
	printf("msg after decoding again: %s\n",msgUpper);
       	assert(strcmp(msgUpper,"SECRET") == 0);
        
	char msgCycle[] = {'x','y','z','\0'};

	printf("\nmsg before encoding: %s\n",msgCycle);
	assert(strcmp(msgCycle,"xyz") == 0);
        encode(msgCycle,3);
        printf("msg after encoding: %s\n",msgCycle);
        assert(strcmp(msgCycle,"ABC") == 0);
        decode(msgCycle,3);
        printf("msg after decoding again: %s\n",msgCycle);
        assert(strcmp(msgCycle,"XYZ") == 0);

	return 0;

}
