#include <math.h>

struct ring
{
	double x, y;
	struct ring* next;
};

/*
struct point
{
	double x, y;
	struct point* next;
};

struct polygon
{
	unsigned  points;
	struct point* array[];
};
*/

double len(struct ring* a, struct ring* b)
{
	double x = a->x - b->x;
	double y = a->y - b->y;

	return sqrt(x * x + y * y);

}

double perimiter(struct ring* ring)
{
	if (!ring) return;

	double P = 0;
	struct ring* dopulnitelen = ring;

	do
	{
		P += len(dopulnitelen, dopulnitelen->next);
		dopulnitelen = dopulnitelen->next;

	} while (dopulnitelen != ring);

	return P;

}


/*
double perimiter(struct polygon* p)
{
	double P = 0;

	for (int i = 0; i < p->points; i++)
		P += len(&p->array[i], &p->array[(i + 1) % p->points]);


	return P;

}
*/
/*
double perimiter(struct point* list)
{
	struct point* p = list;
	double perimeter = 0;
	do
	{
		perimeter += len(p, p->next);
		p = p->next;
	} while (p->next != list);
	return perimeter + len(p, list);
}
*/

void main()
{
	struct ring a = { 0, 0, 0 };
	struct ring b = {1, 0, &a};
	struct ring c= {1, 1, &b};
	struct ring d = {0, 1, &c};
	a.next = &d;

	struct ring* p = &a;



	double x = perimiter(&a);


}

