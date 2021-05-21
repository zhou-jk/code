#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("data.in","w",stdout);
    int n=1e6,m=1e6,k=1e6;
    printf("%d %d %d\n",n,m,k);
    for(int i=1;i<=n;i++)
        printf("1");
    printf("\n");
    for(int i=1;i<=m;i++)
        printf("1");
    printf("\n");
    return 0;
}