#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200005;
int n,m;
int dis[N],fa[N];
int getf(int v)
{
    if(fa[v]==v) return v;
    int f=fa[v];
    fa[v]=getf(fa[v]);
    dis[v]+=dis[f];
    return fa[v];
}
bool merge(int u,int v,int w)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2)
    {
        fa[f2]=f1;
        dis[f2]=dis[u]+w-dis[v];
        return true;
    }
    else return false;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(dis,0,sizeof(dis));
        for(int i=1;i<=n+1;i++)
            fa[i]=i;
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            v++;
            if(!merge(u,v,w)&&w!=dis[v]-dis[u]) ans++;
        }
        printf("%d\n",ans);
    }    
    return 0;
}