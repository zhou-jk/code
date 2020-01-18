#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200001;
const int MOD=1000000009;
int n,m;
long long dp[N];
int a[N];
long long sum[N];
struct Binary_Indexed_Tree
{
    long long C[N];
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,long long y)
    {
        for(int i=x;i<=m;i+=lowbit(i))
            C[i]=(C[i]+y)%MOD;
        return;
    }
    long long getsum(int x)
    {
        long long res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res=(res+C[i])%MOD;
        return res;
    }
}tree;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[i]=sum[i]=sum[i-1]+x;
    }
    for(int i=1;i<=n;i++)
        if(sum[i]>=0) dp[i]++;
    sort(a+1,a+n+1);
    m=unique(a+1,a+1+n)-a-1;
    for(int i=1;i<=n;i++)
        sum[i]=lower_bound(a+1,a+m+1,sum[i])-a;
    for(int i=1;i<=n;i++)
    {
        dp[i]+=tree.getsum(sum[i]);
        tree.add(sum[i],dp[i]);
    }
    printf("%lld",dp[n]);
    return 0;
}