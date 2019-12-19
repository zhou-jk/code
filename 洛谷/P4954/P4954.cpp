#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n;
int sum[N];
int dp[N],f[N];
int q[N],head,tail;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum[i]=sum[i-1]+x;
    }
    head=1,tail=0;
    q[++tail]=n+1;
    for(int i=n;i>0;i--)
    {
        while(head<tail&&sum[q[head+1]-1]-sum[i-1]>=dp[q[head+1]]) head++;
        dp[i]=sum[q[head]-1]-sum[i-1];
        f[i]=f[q[head]]+1;
        while(head<tail&&dp[i]-sum[i-1]<dp[q[tail]]-sum[q[tail]-1]) tail--;
        q[++tail]=i;
    }
    printf("%d",f[1]);
    return 0;
}