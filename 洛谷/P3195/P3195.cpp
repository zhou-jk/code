#include<iostream>
#include<cstdio>
using namespace std;
const int N=50001;
int n,L;
long long dp[N],sum[N];
long long a[N],b[N];
int q[N],head=1,tail=1;
long long X(int i)
{
    return sum[i]+i+L+1;
}
long long Y(int i)
{
    return dp[i]+b[i]*b[i];
}
double slope(int i,int j)
{
    return (double)(Y(i)-Y(j))/(X(i)-X(j));
}
int main()
{
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum[i]=sum[i-1]+x;
    }
    for(int i=0;i<=n;i++)
        a[i]=sum[i]+i,b[i]=sum[i]+i+L+1;
    for(int i=1;i<=n;i++)
    {
        while(head<tail&&slope(q[head],q[head+1])<2*a[i]) head++;
        dp[i]=dp[q[head]]+(a[i]-b[q[head]])*(a[i]-b[q[head]]);
        while(head<tail&&slope(q[tail-1],q[tail])>slope(i,q[tail])) tail--;
        q[++tail]=i;
    }
    printf("%lld",dp[n]);
    return 0;
}
