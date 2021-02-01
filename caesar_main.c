#include <stdio.h>
#include <assert.h>
#include "caesar.h"
#include "caesar.c"


int main() {

char msg[] = {'s','e','c','r','e','t','\0'};
int key = 1;

printf("msg before encoding: %s\nkey: %d\n",msg, key);
assert(strcmp(msg,"secret") == 0);
encode(msg,key);
printf("msg after encoding: %s\n",msg);
assert(strcmp(msg,"TFDSFU") == 0);
decode(msg,key);
printf("msg after decoding again: %s\n",msg);
assert(strcmp(msg,"SECRET") == 0);

char msgUpper[] = {'s','E','c','R','e','T','\0'};

printf("\nmsg before encoding: %s\nkey: %d\n",msgUpper, key);
assert(strcmp(msgUpper,"sEcReT") == 0);
encode(msgUpper,key);
printf("msg after encoding: %s\n",msgUpper);
assert(strcmp(msgUpper,"TFDSFU") == 0);
decode(msgUpper,key);
printf("msg after decoding again: %s\n",msgUpper);
assert(strcmp(msgUpper,"SECRET") == 0);

char msgCycle[] = {'x','y','z','\0'};
key = 3;

printf("\nmsg before encoding: %s\nkey: %d\n",msgCycle, key);
assert(strcmp(msgCycle,"xyz") == 0);
encode(msgCycle,key);
printf("msg after encoding: %s\n",msgCycle);
assert(strcmp(msgCycle,"ABC") == 0);
decode(msgCycle,key);
printf("msg after decoding again: %s\n",msgCycle);
assert(strcmp(msgCycle,"XYZ") == 0);

return 0;

}

