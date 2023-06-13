#include <stdarg.h>
void vmax(int type, void* out, int cnt, ...) {
	va_list l;
	va_start(l, cnt);
	double m = type ? va_arg(l, double) : va_arg(l, int);
	cnt--;
	if (type == 0) {
		while (cnt != 0) {
			int m2 = va_arg(l, int);
			if (m < m2) m = m2;
			cnt--;
		}; 
	}
	else while (cnt) {
		double m2 = va_arg(l, double);
		if (m < m2) m = m2;
		cnt--;

	}
		va_end(l);
		return m;

};				// type 0 - int, type 1 - double

void main()
{
	double res;
	vmax(1, &res, 4, .1, 2., 3., .4);
}