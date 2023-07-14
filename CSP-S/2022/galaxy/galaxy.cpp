#include<iostream>
#include<cstdio>
#include<random>
using namespace std;
const int N=500005;
int n,m,q;
int pre[N],nowpre[N];
unsigned long long a[N];
unsigned long long val[N],nowval[N];
int main()
{
    freopen("galaxy.in","r",stdin);
    freopen("galaxy.out","w",stdout);
    mt19937_64 rnd(time(NULL));
    scanf("%d%d",&n,&m);
    unsigned long long sum=0;
    for(int i=1;i<=n;i++)
        a[i]=rnd(),sum^=a[i];
    unsigned long long nowsum=0;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        val[v]^=a[u],nowval[v]^=a[u];
        pre[v]++,nowpre[v]++;
        nowsum^=a[u];
    }
    int nowm=m;
    scanf("%d",&q);
    while(q--)
    {
        int t,u,v;
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d%d",&u,&v);
            nowm--,nowpre[v]--;
            nowsum^=a[u],nowval[v]^=a[u];
        }
        else if(t==2)
        {
            scanf("%d",&u);
            nowm-=nowpre[u],nowpre[u]=0;
            nowsum^=nowval[u],nowval[u]=0;
        }
        else if(t==3)
        {
            scanf("%d%d",&u,&v);
            nowm++,nowpre[v]++;
            nowsum^=a[u],nowval[v]^=a[u];
        }
        else if(t==4)
        {
            scanf("%d",&u);
            nowm+=(pre[u]-nowpre[u]),nowpre[u]=pre[u];
            nowsum^=(val[u]^nowval[u]),nowval[u]=val[u];
        }
        if(nowm==n&&nowsum==sum) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}