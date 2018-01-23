#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5

typedef struct {
	char *name;
	char *last_name;
	char age;
} musician;

int check_strings(char *name1, char *name2);
int check_if_col_is_going_up(musician **musicians, int col);
int cols_in_order(musician **musicians);
int musician_order (musician *m1, musician *m2);

int main()
{
	musician m1;
	musician m2;
	
	m1.name = (char *) malloc (5*sizeof(char));
	m2.name = (char *) malloc (5*sizeof(char));
	
	m1.last_name = (char *) malloc (5*sizeof(char));
	m2.last_name = (char *) malloc (5*sizeof(char));
	
	m1.age = 12;
	m2.age = 15;
	
	strcpy(m1.name, "amich");
	strcpy(m2.name,"amici");
	
	strcpy(m1.last_name, "amich");
	strcpy(m2.last_name,"amici");
	
	
	if (musician_order(&m1,&m2))
		printf("yup biatch\n");
	
	return 0;
}


int musician_order (musician *m1, musician *m2)
{
	int first_name_order;
	
	first_name_order = check_strings(m1->name, m2->name);
	
	if (first_name_order == 0)
		return check_strings(m1->last_name, m2->last_name);
	
	return first_name_order;

}

int check_strings(char *name1, char *name2)
{
	return strcmp(name1,name2);
}

int cols_in_order(musician **musicians)
{
	int i;
	int col_count = 0;
	
	for (i=0; i<N; i++)
		if (check_if_col_is_going_up(musicians,i))
			col_count++;
		
	return col_count;
}


int check_if_col_is_going_up(musician **musicians, int col)
{
	int i;
	
	for (i=0; i<N-1; i++)
		if (musician_order(&musicians[i][col],&musicians[i+1][col]) == -1)
			return 0;
		
	return 1;
}