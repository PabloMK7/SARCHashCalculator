

#include <stdio.h>
#include <string.h>
#include <conio.h>

/*Credits to Gericom/MKDS3 for RE the sarc hash algorithm*/
int SARC_gethash(char *name, int size) {
	int i, res = 0;
	for (i = 0; i < size; i++) {
		res = (*(name + i) + res * 0x65) & 0xFFFFFFFF;
	}
	return res;
}

int main(int argc, char **argv)
{
	char name[128];
	int hash;
	start:
		memset(name, 0, 128);
		printf("filename: ");
		fgets(name, 128, stdin);
		hash = SARC_gethash(name, strlen(name) - 1);
		printf("Hash: 0x%08X\n\n", hash);
		goto start;
	return 0;
}

