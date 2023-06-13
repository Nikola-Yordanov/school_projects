#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <malloc.h>



struct point 
{
	//struct point* next; RING
	double x, y;

};

struct polygon {
	int n;
	struct point* points[];
	
};






double lenght(struct point* a, struct point* b)
{
	double x = &a->x - &b->x;
	double y = &a->y - &b->y;
	return sqrt(x * x + y * y);
}

/*																RING
double perimiter(struct point* ring)
{																		
	double P = 0;
	struct point* c = ring;

	do
	{
		P += lenght(c, c->next);
		c = c->next;
	} while (c != ring);

	return P;
}
*/



double perimiter(struct polygon* polygon) {

	double P = 0;

	for (int i = 0; i < polygon->n; i++)
	{

		P += lenght(polygon->points[i], polygon->points[ (i + 1)%polygon->n] );
	}

	return P;
}

//double perimiter(struct point* queue) {};

double main()
{	/*														RING
	struct point
		A = {0, 0, 0},
		B = {&A, 1, 0},
		C = {&B, 1, 1},
		D = {&C, 0, 1};
	A.next = &D;

	printf("%f", perimiter(&D));
	*/


	struct point a = { 0,0 }, b = { 1, 0 }, c = { 1, 1 }, d = { 0, 1 };
	struct point* Points =	malloc(sizeof(struct point) * 100); //= (struct point*)malloc(sizeof(struct point*)*4);

	if (Points == NULL) return 0;

	Points[0] = a, Points[1] = b, Points[2] = c, Points[3] = d;
	
	struct polygon Polygon = { 4, Points };


	printf("%lf", perimiter(&Polygon));



}