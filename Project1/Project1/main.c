char switch_case(char a)
{
	if ('A' <= a && a <= 'Z')
		return a - 'A' + 'a';
	if ('a' <= a && a <= 'z')
		return a - 'a' + 'A';
	return a ;
}


void main() {

	switch_case('a');


}