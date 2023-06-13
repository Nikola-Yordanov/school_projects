str_cmp(const char* l, const char* r)
{
	while (*l == *r & *l != 0)
	{
		l++;
		r++;
	}
	return *l - *r;
};

void qsort_str(const char** l, const char** r) {


};
void main()
{
	const char* a[] = { "one", "two", "three", "four", "five" };
	qsort_str(a + 0, a + 4);
}