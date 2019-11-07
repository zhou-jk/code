#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int N=100001,Log=35;
const int INF=4557430888798830399;
int n, f[N][Log];
long long k;
long long sum[N][Log],Min[N][Log];
pair<long long,long long> query(int x)
{
    long long ans1=0,ans2=INF;
    for(int i=log2(k);i>=0;i--)
        if((k>>i)&1)
        {
            ans1+=sum[x][i];
            ans2=min(ans2,Min[x][i]);
            x=f[x][i];
        }
    return make_pair(ans1,ans2);
}

int main()
{
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&f[i][0]);
        f[i][0]++;
    }
    memset(Min,63,sizeof(Min));
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum[i][0]=Min[i][0]=x;
    }
    for(int j=1;(1ll<<j)<=k;j++)
        for(int i=1;i<=n;i++)
        {
            f[i][j]=f[f[i][j-1]][j-1];
            Min[i][j]=min(Min[i][j-1],Min[f[i][j-1]][j-1]);
            sum[i][j]=sum[i][j-1]+sum[f[i][j-1]][j-1];
        }
    for(int i=1;i<=n;i++)
    {
        pair<long long,long long>res=query(i);
        printf("%lld %lld\n",res.first,res.second);
    }
    return 0;
}