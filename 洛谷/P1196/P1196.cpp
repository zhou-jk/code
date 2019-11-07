#include<bits/stdc++.h>
#define R register int
#define M 500500
using namespace std;
int T,f[M],d[M],size[M];
int getf(int v)
{
    if(v==f[v]) return v;
    int k=f[v];
    f[v]=getf(f[v]);
    d[v]+=d[k];
    size[v]=size[f[v]];
    return f[v];
}
void merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2)
    {
        f[f1]=f2;
        d[f1]=d[f2]+size[f2];
        size[f2]+=size[f1];
        size[f1]=size[f2];
    }
    return;
}
int main()
{
    scanf("%d",&T);
    for(int i=1;i<=30000;i++)
        f[i]=i,size[i]=1;
    while(T--)
    {
        int x,y;
        char ch;
        for(ch=getchar();ch!='M'&&ch!='C';ch=getchar());
        scanf("%d%d",&x,&y);
        if(ch=='M') merge(x,y);
        else if(ch=='C')
        {
            if(getf(x)!=getf(y)) printf("-1\n");
            else printf("%d\n",abs(d[x]-d[y])-1);
        }
    }
    return 0;
}