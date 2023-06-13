#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <ctype.h>


void main(int argc, char *argv[])
{
	if(argc < 2) 
	{
		printf("Atleast one argument required!");
		return 0;
	
	}

	FILE *f;

	f = fopen(argv[1], "r+");
	if (!f) return 0;
	fseek(f, 0, SEEK_END);
	int bytes = ftell(f);
	char *ptr = malloc(bytes);
	if (ptr == NULL) return 0;

	rewind(f);
	fread(ptr, bytes, 1, f);

	for (int i = 0; i < bytes ; i++)
		ptr[i] = toupper(ptr[i]);

	rewind(f);
	fwrite(ptr, bytes, 1, f);
	free(ptr);
	fclose(f);
	
}