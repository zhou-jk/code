#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,m;
int p[N];
int a[N],b[N],c[N];
int s[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&p[i]);
    for(int i=1;i<n;i++)
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for(int i=2;i<=m;i++)
    {
        int l=p[i-1],r=p[i];
        if(l>r) swap(l,r);
        s[l]++,s[r]--;
    }
    for(int i=1;i<=n;i++)
        s[i]+=s[i-1];
    long long ans=0;
    for(int i=1;i<n;i++)
        ans+=min((long long)s[i]*a[i],(long long)s[i]*b[i]+c[i]);
    printf("%lld",ans);
    return 0;
}