#include <stdio.h>
#include <stdlib.h>
typedef struct {
	double x,y;
}point;

typedef struct {
	double a,b;
}line;


int are_colinear(point *p1, point *p2, point *p3);
line *get_line(point *p1, point *p2);

int main()
{
	point p1;
	point p2;
	point p3;
	
	line *the_line;
	
	p1.x = 3;
	p1.y = 3;
	
	p2.x = 2;
	p2.y = 2;
	
	
	p3.x = 1;
	p3.y = 1;
	
	the_line = get_line(&p1,&p2);
	
	
	printf("y = %lfx + %lf\n",the_line->a,the_line->b);
	
	if (are_colinear(&p1,&p2,&p3))
	{
		printf("are colinear\n");
	}
	
	free(the_line);
	return 0;
}


line *get_line(point *p1, point *p2)
{
	line *the_line;
	
	if ((p1->x)-(p2->x) == 0)
		return NULL;
	
	the_line = (line *) malloc (sizeof(line));
	
	
	the_line->a = ((p1->y)-(p2->y))/((p1->x)-(p2->x));
	
	
	the_line->b = (p1->y)-(the_line->a)*(p1->x);
	
	return the_line;
}

int are_colinear(point *p1, point *p2, point *p3)
{
	line *line1;
	line *line2;
	
	line1 = get_line(p1,p2);
	line2 = get_line(p1,p3);
	
	if(!line1 || !line2)
		return 0;
	
	return (line1->a == line2->a);
}
