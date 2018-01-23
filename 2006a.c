#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 7

void find_min_row(int **a, int *min, int n, int m);
int min_in_one_row(int *a, int m);
int max_in_one_col(int **a, int col, int n);
void find_max_col(int **a, int *max,int n, int m);
void get_info_from_file(FILE *fp,int **a, int size);

int main()
{
	int **a;
	int size;
	FILE *fp;
	int i;
	int *min;
	int *max;
	
	fp = fopen("data.txt","r");
	
	if (!fp)
		exit(1);
	
	fscanf(fp,"%d",&size);
	
	a = (int **) malloc (size*sizeof(int *));
	
	for (i=0; i<size; i++)
		a[i] = (int *) malloc (size*sizeof(int));
	
	get_info_from_file(fp,a,size);
	
	min = (int *) malloc (size*sizeof(int));
	max = (int *) malloc (size*sizeof(int));
	
	
	find_max_col(a,max,size,size);
	find_min_row(a,min,size,size);
	
	for (i=0; i<size; i++)
		if (max[i] == min[i])
			printf("\n\n%d\n\n",min[i]);
	return 0;
}


void get_info_from_file(FILE *fp,int **a, int size)
{
	int i,j;
	
	for (i=0; i<size; i++)
		for (j=0; j<size; j++)
			fscanf(fp,"%d",&a[i][j]);
	
}


void find_max_col(int **a, int *max,int n, int m)
{
	int i;
	
	for (i=0; i<m; i++)
	{
		max[i] = max_in_one_col(a,i,m);
	}
}


int max_in_one_col(int **a, int col, int n)
{
	int i;
	int max = a[0][col];
	
	for (i=1; i<n; i++)
		if (a[i][col] > max)
			max = a[i][col];
		
	return max;
}


void find_min_row(int **a, int *min, int n, int m)
{
	int i;
	
	for (i=0; i<n; i++)
		min[i] = min_in_one_row(a[i],m);
}


int min_in_one_row(int *a, int m)
{
	int i;
	int min = a[0];
	
	
	for (i=0; i<m; i++)
		if (a[i] < min)
			min = a[i];
		
	return min;
}