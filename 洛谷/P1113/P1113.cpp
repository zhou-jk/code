#include<iostream>
#include<cstdio>
using namespace std;
int f[10001];
int n,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int k,len,t;
        scanf("%d%d",&k,&len);
        while(scanf("%d",&t)&&t)
            f[i]=max(f[i],f[t]);
        f[i]+=len;
        ans=max(ans,f[i]);
    }
    printf("%d",ans);
    return 0;
} 