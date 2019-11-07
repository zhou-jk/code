#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,m;
int f[101],val[101];
int getf(int v)
{
    if(v==f[v]) return v;
    int father=f[v];
    f[v]=getf(f[v]);
    val[v]+=val[father];
    return f[v];
}
bool merge(int u,int v,int w)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2)
    {
        f[f1]=f2;
        val[f1]=val[v]-val[u]-w;
        return true;
    }
    return false;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(val,0,sizeof(val));
        bool flag=true;
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++)
            f[i]=i;         
        for(int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(!merge(x-1,y,z)) if(val[y]-val[x-1]!=z) flag=false;
        }
        if(flag) printf("true\n");
        else printf("false\n");
    }
    return 0;
}