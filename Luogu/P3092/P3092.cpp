#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=1061109567;
const int N=100001,K=17;
int k,n;
int sum[N];
int f[1<<K],a[K];
int ans=-INF;
int main()
{
    scanf("%d%d",&k,&n);
    for (int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum[i]=sum[i-1]+x;
    }
    memset(f,-1,sizeof(f));
    f[0]=0;
    for(int i=0;i<(1<<k);i++)
    {
        if(f[i]==-1) continue;
        if(f[i]==n)
        {
            int res=0;
            for(int j=1;j<=k;j++)
                if(!(i&(1<<(j-1)))) res+=a[j];
            ans=max(ans,res);
        }
        for(int j=1;j<=k;j++)
            if(!(i&(1<<(j-1)))) f[i|(1<<(j-1))]=max(f[i|(1<<(j-1))],(int)(upper_bound(sum+f[i]+1,sum+n+1,a[j]+sum[f[i]])-sum-1));
    }
    if(ans<=-INF) printf("-1");
    else printf("%d",ans);
    return 0;
}