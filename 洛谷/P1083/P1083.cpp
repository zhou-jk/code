#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
long long R[1000001],d[1000001],s[1000001],t[1000001];
long long b[1000001],sum[1000001];
bool check(int x)
{
    memset(b,0,sizeof(b));
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=x;i++)
        b[s[i]]+=d[i],b[t[i]+1]-=d[i];
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+b[i];
    for(int i=1;i<=n;i++)
        if(sum[i]>R[i]) return false;
    return true;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&R[i]);
    for(int i=1;i<=m;i++)
        scanf("%lld%lld%lld",&d[i],&s[i],&t[i]);
    int l=0,r=m;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    if(l==m) printf("0");
    else printf("-1\n%d",l+1);
    return 0;
}