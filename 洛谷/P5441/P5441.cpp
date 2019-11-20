#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100;
int n;
int a[N];
int main()
{
    scanf("%d",&n);
    if(n==1)
    {
        printf("0\n0");
        return 0;
    }
    int ans=n*(n-3)*(n*n+6*n-31)/48;
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
    {
        memset(a,0,sizeof(a));
        for (int j=1;j<=(n+1)/2;j++)
            a[(i+j-1)%n+1]=1;
        for(int j=1;j<=n;j++)
            printf("%d ",a[j]);
        printf("\n");
    }
    return 0;
}
