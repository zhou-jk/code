#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,s;
int x[N];
long long p[N];
long long solve(int l,int r,int t)
{
    if(s<=x[l]) return (long long)x[r]-s+abs((long long)x[t]-x[r]);
    if(s>=x[r]) return (long long)s-x[l]+abs((long long)x[t]-x[l]);
    if(p[l]>=p[r])
    {
        p[l]+=p[r];
        return solve(l,r-1,l)+(t==r?x[r]-x[l]:0);
    }
    else
    {
        p[r]+=p[l];
        return solve(l+1,r,r)+(t==l?x[r]-x[l]:0);
    }
}
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)
        scanf("%d%lld",&x[i],&p[i]);
    if(s<=x[1]) printf("%lld",(long long)x[n]-s);
    else if(s>=x[n]) printf("%lld",(long long)s-x[1]);
    else if(p[1]<p[n]) printf("%lld",solve(1,n,1));
    else printf("%lld",solve(1,n,n));
    return 0;
}