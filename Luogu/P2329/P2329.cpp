#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2001;
int a[N],b[N],c[N];
int sum[N],s;
int n,m,res;
bool dfs(int dep,int last)
{
    if(dep<=0) return true;
    if(res+sum[dep]>s) return false;
    for(int i=last;i<=n;i++)
        if(c[i]>=b[dep])
        {
            c[i]-=b[dep];
            if(c[i]<b[1]) res+=c[i];
            if(dfs(dep-1,b[dep]==b[dep-1]?i:1)) return true;
            if(c[i]<b[1]) res-=c[i];
            c[i]+=b[dep];
        }
    return false;
}
bool check(int x)
{
    memcpy(c,a,sizeof(a));
    res=0;
    return dfs(x,1);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s+=a[i];
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for(int i=1;i<=m;i++)
        sum[i]=sum[i-1]+b[i];
    while(sum[m]>s) m--;
    int l=0,r=m,ans;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
    return 0;
}