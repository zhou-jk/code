#include<iostream>
#include<cstdio>
using namespace std;
int q[50001],tail=1,head=1;
int n,l;
double A[50001],B[50001];
double dp[50001];
double a[50001],sum[50001];
double X(int x)
{
    return B[x];
}
double Y(int x)
{
    return dp[x]+B[x]*B[x];
}
double calc(int a,int b)
{
    return (Y(a)-Y(b))/(X(a)-X(b));
}
int main()
{
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&a[i]);
        sum[i]=sum[i-1]+a[i];
        A[i]=sum[i]+i;B[i]=sum[i]+i+l+1;
    }
    B[0]=l+1;
    for(int i=1;i<=n;i++)
    {
        while(head<tail&&calc(q[head],q[head+1])<2*A[i])
            head++;
        dp[i]=dp[q[head]]+(A[i]-B[q[head]])*(A[i]-B[q[head]]);
        while(head<tail&&calc(i,q[tail-1])<calc(q[tail-1],q[tail]))
            tail--;
        q[++tail]=i;
    }
    printf("%lld",(long long)dp[n]);
    return 0;
}