#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int size;
	int **matrix;
	int i,j;
	
	fp = fopen("numbers.txt","r");
	
	if (fp == NULL)
		exit(1);
	
	fscanf(fp,"%d",&size);
	
	matrix = (int **) malloc (size*sizeof(int *));
	
	for (i=0; i<size; i++)
		matrix[i] = (int *) malloc (size*sizeof(int));
	
	
	for (i=0; i<size; i++)
		for (j=0; j<size; j++)
			fscanf(fp,"%d",&a[i][j]);
	
	
	
	
	return 0;
}