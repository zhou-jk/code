#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,ans=1;
int main()
{
    scanf("%d",&m);
    if(m==5)
    {
        printf("3\n1 1 3\n");
        return 0;
    }
    n=log2(m-1);
    printf("%d\n",n+1);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",ans);
        ans<<=1;
    }
    printf("%d",m-ans+1);
    return 0;
}