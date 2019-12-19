#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
const long double eps=1e-9;
const int N=55,M=5005;
int n,R;
long double dp[N][M];
int a[N],b[N],p[N];
bool check(long double x)
{
    for(int i=n;i>0;i--)
    {
        for(int j=R+1;j<M;j++)
            dp[i+1][j]=x;
        for(int j=0;j<=R;j++)
            dp[i][j]=min(x,(dp[i+1][j+a[i]]+a[i])*p[i]/100+(dp[i+1][j+b[i]]+b[i])*(100-p[i])/100);
    }
    return dp[1][0]<x;
}
int main()
{
    scanf("%d%d",&n,&R);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i],&b[i],&p[i]);
    long double l=0,r=1e10;
    int start=clock();
    while(r-l>=eps)
    {
        long double mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }
    printf("%.9Lf",l);
    return 0;
}