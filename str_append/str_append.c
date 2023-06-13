#include <stdio.h>

char* str_append(char* heap_to, const char* from) {
	char* heap_to1 = malloc(strlen(heap_to) * 6);
	strcpy(heap_to1, from);
	printf("%s %s", from, heap_to);
	free(heap_to1);
}

void main() {
	str_append("World!", "Hello");
}