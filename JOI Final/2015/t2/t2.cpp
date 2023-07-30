#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2005;
int n;
int a[N+N];
long long f[N+N][N+N];
long long getf(int l,int r)
{
    if(f[l][r]!=-1) return f[l][r];
    if(l==r) return f[l][r]=a[l];
    if(l+1==r) return f[l][r]=max(a[l],a[r]);
    long long res=0;
    if(a[l+1]<a[r]) res=max(res,a[l]+getf(l+1,r-1));
    else res=max(res,a[l]+getf(l+2,r));
    if(a[l]<a[r-1]) res=max(res,a[r]+getf(l,r-2));
    else res=max(res,a[r]+getf(l+1,r-1));
    return f[l][r]=res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        a[i+n]=a[i];
    memset(f,-1,sizeof(f));
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,getf(i,i+n-1));
    printf("%lld",ans);
    return 0;
}