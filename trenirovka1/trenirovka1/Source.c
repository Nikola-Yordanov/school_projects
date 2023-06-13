#include <stdio.h>

int main() {
	int a, b, c;

	printf("Enter first angle: ");
	scanf_s("%d", &a);
	printf("Enter second angle: ");
	scanf_s("%d", &b);
	if ((a + b) > 180 || a > 180 || b > 180) {

		return printf("The angles are invalid");
			
	};
			c = 180 - (a + b);

	printf("The third angle is %d", c);

}