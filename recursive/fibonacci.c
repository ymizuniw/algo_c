#include <stdio.h>
#include <stdlib.h>

// #include <>

long	fib(long);

int	main(void)
{
	long	n;

	for (n = 1; n <= 20; n++)
		printf("%3ld: %ld\n", n, fib(n));
	return (0);
}

long	fib(long n)
{
	if (n == 1 || n == 2)
		return (1L);
	return (fib(n - 1) + fib(n - 2));
}
