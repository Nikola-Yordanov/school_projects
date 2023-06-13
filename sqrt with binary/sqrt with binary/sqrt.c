int sqrt(x) {
	int r = x;
	int l = 0;
	int m = 1;
	do {
		m = (r + l) / 2;
		if (m * m > x) r = m;
		else l = m;
	} while (r - l > 1);
	return l;
}

void main() {
	int res = 0;
	do {
		if (res != sqrt(res * res))
			sqrt(res * res);
		res = res + 1;
	} while (res < 100000);
	sqrt(res);
}