#include <stdio.h>
// #include <>


int gcd(int, int);

int main(void)
{
    int a, b;

    printf("enter two integers\n");
    scanf("%d %d", &a, &b);
    printf("gcd: %d\n", gcd(a, b));
    return (0);
}

int count = 0;

int gcd(int m, int n)
{
    if (n==0)
        return m;
    else
    {
        count++;
        printf("count: %d\nm:%d n:%d\n\n", count, m, n);
        return (gcd(n, m%n));
    }
}
