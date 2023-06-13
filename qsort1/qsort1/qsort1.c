void qsort(int* l, int* r) {	// bez rekursiq
	
	while (l < r) 
	{
		int* p = l, * q = r, m = l[(r - l) / 2];
		do 
		{
			while (*p < m)
				p++;
			while (*q > m)
				q--;
			if (p <= q) {
				int t = *p;
				*p = *q;
				*q = t;
				p++, q--;}
		} while (p <= q);
		if (q - l < r - p) {
			qsort(l, q);
			l = p;
		}
		else {
			qsort(p, r);
			r = p;
		};
	}
};

void main()
{
	int a[5] = { 20, 10, 30 , 50, 0 };
	qsort(a, a + 4);
}
