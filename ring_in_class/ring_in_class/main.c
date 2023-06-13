struct ring
{
	struct ring* next;
};


void main()
{
	struct ring a, b, c;
	a.next = &b;
	b.next = &c;
	c.next = &a;
}