#include <stdio.h>

int m[7][7] = {{2,2,2,2,2,2,2},
                {2,0,0,0,0,0,2},
                {2,0,2,0,2,0,2},
                {2,0,0,2,0,2,2},
                {2,2,0,2,0,2,2},
                {2,0,0,0,0,0,2},
                {2,2,2,2,2,2,2}};
int Si, Sj,Ei,Ej, success,
    sp, ri[100], rj[100];

int visit(int, int);

int main(void)
{
    sp=0;
    success=0;
    Si=1; Sj=1; Ei=5; Ej=5;
    printf("\nsearch in maze\n");
    if (visit(Si, Sj)==0)
        printf("exit was not found\n");
    pritnf("\n");
}
int visit(int i, int j)
{
    int k;
    m[i][j]=1;
    ri[sp]=i; rj[sp]=j; sp++;
    if (i==Ei && j==Ej)
    {
        for (k=0;k<sp;k++)
            printf("(%d, %d) ", ri[k], rj[k]);
        success=1;
    }
    if (success!=1 && m[i][j+1]==0) visit(i, j+1);
    if (success!=1 && m[i+1][j]==0) visit(i+1, j);
    if (success!=1 && m[i][j-1]==0) visit(i, j-1);
    if (success!=1 && m[i-1][j]==0) visit(i-1, j);
    sp--;
    return success;
}
