#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 6
#define COLS 10

void make_string(char *a, char *b, int size_a);
int is_in_col(char **a, char *string_to_find, int col);
int string_is_in_char_matrix(char **a, char *string_to_find);
int is_in_char_array(char *char_array, char *string_to_find, int size_of_char_array);

int main()
{
	char string_to_find[] = "eee";
	char **a;
	int i,j;
	
	a = (char **) malloc (ROWS*sizeof(char *));
	
	for (i=0; i<ROWS; i++)
		a[i] = (char *) malloc (COLS*sizeof(char));
	
	
	for (i=0; i<ROWS; i++)
		for (j=0; j<COLS; j++)
			a[i][j] = 'a' + i;
	
	if (string_is_in_char_matrix(a,string_to_find))
		printf("string  %s is in char matrix\n",string_to_find);
	
	return 0;
}

void make_string(char *a, char *b, int size_a)
{
	int i;
	
	i=0;
	while( i<size_a)
	{
		b[i] = a[i];
		i++;
	}
	
	b[i] = '\0';
}

int is_in_char_array(char *char_array, char *string_to_find, int size_of_char_array)
{
	char *char_array_as_string;
	
	char_array_as_string = (char *) malloc ((size_of_char_array+1) * sizeof(char));
	
	make_string(char_array,char_array_as_string,size_of_char_array);
	
	if (strstr(char_array_as_string,string_to_find) != NULL)
		return 1;
	
	return 0;
	
}

int string_is_in_char_matrix(char **a, char *string_to_find)
{
	int i;
	
	for (i=0; i<ROWS; i++)
		if (is_in_char_array(a[i],string_to_find,COLS))
			return 1;
		
	for (i=0; i<COLS; i++)
	{
		if (is_in_col(a,string_to_find,i))
			return 1;
	}
	
	return 0;
}

int is_in_col(char **a, char *string_to_find, int col)
{
	int i;
	char col_as_row[ROWS+1];
	
	for (i=0; i<ROWS; i++)
		col_as_row[i] = a[i][col];
	
	if (is_in_char_array(col_as_row,string_to_find,ROWS))
		return 1;
	return 0;
		
}


