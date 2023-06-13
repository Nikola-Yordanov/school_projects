#define M1(x) M2(4*(x)+0) M2(4*(x)+1) M2(4*(x)+2) M2(4*(x)+3)
#define M2(x) M3(4*(x)+0) M3(4*(x)+1) M3(4*(x)+2) M3(4*(x)+3)
#define M3(x) M4(4*(x)+0) M4(4*(x)+1) M4(4*(x)+2) M4(4*(x)+3)
#define M4(x) (UPCASE(x)),

#define UPCASE(x) ('a'<=(x) & (x)<='z'?(x)-'a'+'A':(x))

const char upcase[] = { M1(0) M1(1) M1(2) M1(3) };
void main() {

	char a = upcase['a'];

}