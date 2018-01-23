#include <stdio.h>


int sum_primes(int n);
int first_prime_devidor(int n);
int is_prime(int n);

int main()
{
	printf("%d\n",sum_primes(360));
	
	return 0;
}

int is_prime(int n)
{
	int i;
	
	if (n < 2)
		return 0;
	
	if (n==2)
		return 1;
	
	if (n%2 == 0)
		return 0;
	
	for (i=3; i<n/2; i+=2)
		if (n%i == 0)
			return 0;
		
	return 1;
}


int first_prime_devidor(int n)
{
	int i;
	
	for (i=2; i<n; i++)
		if (n%i == 0)
			if (is_prime(i))
				return i;
			
	return n;
	
}

int sum_primes(int n)
{
	if (n==1)
		return 0;
	
	int the_prime_devidor = first_prime_devidor(n);
	
	return the_prime_devidor + sum_primes(n/the_prime_devidor);
}
