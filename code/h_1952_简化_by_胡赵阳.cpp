#include<cstdio>
#include<algorithm>
using namespace std;
struct ji
{
    long long x,y,z;
};
long long n,m,sum,ans,tot,k,bian[1000001],f[40001],p[40001];
ji e[100001];
void dfs(int k,int s,int t)
{
    if (!k)
    {
        tot++;
        return;
    }
    if (t-s+1<k)return;
    for (int i=s;i<=t;i++)
    {
        int x=e[i].x;
        int y=e[i].y;
        while (x!=p[x])x=p[x];
        while (y!=p[y])y=p[y];
        if (x!=y)
        {
            p[x]=y;
            dfs(k-1,i+1,t);
            p[x]=x;
        }
    }
}
int find1(int k)
{
    if (k!=f[k])f[k]=find1(f[k]);
    return f[k];
}
int find2(int k)
{
    if (k!=p[k])p[k]=find2(p[k]);
    return p[k];
}
bool cmp(ji x,ji y)
{
    return x.z<y.z;
}
int main()
{
    scanf("%lld%lld",&n,&m);
    for (int i=1;i<=m;i++)scanf("%lld%lld%lld",&e[i].x,&e[i].y,&e[i].z);
    sort(e+1,e+m+1,cmp);
    sum=1;
    for (int i=1;i<=n;i++)f[i]=p[i]=i;
    for (int i=1;i<=m;i++)
        if (find1(e[i].x)!=find1(e[i].y))
        {
            ans+=e[i].z;
            f[find1(e[i].x)]=find1(e[i].y);
            bian[e[i].z]++;
            if (++k==n-1)break;
        }
    k=1;
    for (int i=1;i<=m;i=++k)
    {
        while (e[k].z==e[k+1].z)k++;
        tot=0;
        dfs(bian[e[i].z],i,k);
        sum=(sum*tot)%1000000007;
        for (int j=i;j<=k;j++)
            if (find2(e[j].x)!=find2(e[j].y))p[find2(e[j].x)]=find2(e[j].y);
    }
    printf("%lld %lld",ans,sum);
}
