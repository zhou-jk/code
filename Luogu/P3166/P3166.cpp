#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int n,m;
long long c[1002001][4];
long long ans,tmp;
int main()
{
    scanf("%d%d",&n,&m);
    n++;m++;
    c[0][0]=1;
    for(int i=1;i<=n*m;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=3;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    ans=c[n*m][3]-n*c[m][3]-m*c[n][3];
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
        {
            tmp=gcd(i,j)+1;
            if(tmp>2) ans-=(tmp-2)*2*(n-i)*(m-j);
        }
    printf("%lld",ans);
    return 0;
}