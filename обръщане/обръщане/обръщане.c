void f(int a[10])
{
	int x = 11, y = 9;

	do {
		a[y] = x * y;
		y--;

	} while (y >=0);


	y = 0;
	int z = 9;

	do {
		a[z] = x * y;
		y++;
		z--;

	} while (y < 10);

};
void main() {
	int a[10];
	f(a);
}

