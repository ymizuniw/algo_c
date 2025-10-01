#include <stdio.h>
// #include <>

int gcd(int, int);

int main(void)
{
    int a, b;
    printf("enter two integers\n");
    scanf("%d %d", &a, &b);
    printf("gcd: %d\n", gcd(a,b));
}

int gcd(int m, int n)
{
    if (m==n)
        return m;
    if (m>n)
        return (gcd(m-n, n));
    else
        return (gcd(m, n-m));
}

