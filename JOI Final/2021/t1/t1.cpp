#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const long long INF=4557430888798830399;
int n;
int a[N];
int b[N];
long long pre[N],suf[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        b[i]=a[i+1]-a[i];
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if(b[i]<=0) pre[i]+=-b[i]+1;
    }
    for(int i=n;i>=1;i--)
    {
        suf[i]=suf[i+1];
        if(b[i]>=0) suf[i]+=b[i]+1;
    }
    long long ans=INF;
    for(int i=1;i<=n;i++)
        ans=min(ans,max(pre[i-1],suf[i]));
    printf("%lld",ans);
    return 0;
}