#include<iostream>
#include<cstdio>
#include<vector>
#include"matrix.h"
using namespace std;
int main()
{
    int n,P;
    scanf("%d%d",&n,&P);
    set_mod(P);
    Matrix M(n,n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int x;
            scanf("%d",&x);
            M[i][j]=x;
        }
    printf("%d",M.det().val());
    return 0;
}