int wrdcnt(const char* s) {
	int i = 0, cnt = 0;
	while (s[i] != 0) {
		if (s[i] == ' ')
		{
			cnt++;
		}
		i++;
	}
	if (i != 0) cnt++;
	return cnt;
}
void main() {
	wrdcnt("one two three");
}