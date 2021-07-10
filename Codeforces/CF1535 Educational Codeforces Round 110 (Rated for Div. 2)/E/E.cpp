#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=300005;
int q;
int p[N],a[N],c[N];
int fa[N][20];
int main()
{
    scanf("%d%d%d",&q,&a[0],&c[0]);
    for(int u=1;u<=q;u++)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d%d",&p[u],&a[u],&c[u]);
            fa[u][0]=p[u];
            for(int i=1;(1<<i)<=q;i++)
                fa[u][i]=fa[fa[u][i-1]][i-1];
        }
        else if(op==2)
        {
            int v,w;
            scanf("%d%d",&v,&w);
            long long sum=0;
            int ret=w;
            while(ret>0)
            {
                int now=v;
                for(int i=log2(q);i>=0;i--)
                    if(a[fa[now][i]]) now=fa[now][i];
                if(!a[now]) break;
                if(a[now]<ret) sum+=(long long)a[now]*c[now],ret-=a[now],a[now]=0;
                else sum+=(long long)ret*c[now],a[now]-=ret,ret=0;
            }
            printf("%d %lld\n",w-ret,sum);
            fflush(stdout);
        }
    }
    return 0;
}