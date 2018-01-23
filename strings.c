#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_OF_A 8
#define SIZE_OF_B_AND_C 3

void make_string(char *char_array, char *string);

int main()
{
	char a[] = {'a','s','d','f','g','h','j','k'};
	char b[] = {'d','f','g'};
	char c[] = {'k','j','k'};
	char *a_as_string;
	char *b_as_string;
	char *c_as_string;
	
	
	b_as_string = (char *) malloc (SIZE_OF_B_AND_C+1 * sizeof(char));
	a_as_string = (char *) malloc (SIZE_OF_A+1 * sizeof(char));
	c_as_string = (char *) malloc (SIZE_OF_B_AND_C+1 * sizeof(char));
	
	make_string(a,a_as_string);
	make_string(b,b_as_string);
	make_string(c,c_as_string);
	
	if (strstr(a_as_string,b_as_string))
		printf("yup its inside\n");
	
	if (strstr(a_as_string,c_as_string))
		printf("yup its inside\n");
	
}

void make_string(char *char_array, char *string)
{
	int i;
	
	for (i=0; i<SIZE_OF_A; i++)
	{
		string[i] = char_array[i];
	}
	string[i] = '\0';
}

