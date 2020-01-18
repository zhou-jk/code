#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int f[2001],ans;
bool book[2001];
int getf(int v)
{
    if(v==f[v]) return v;
    f[v]=getf(f[v]);
    return f[v];
}
void merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2) f[f2]=f1;
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*2;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
    {
        char ch;
        int x,y;
        for(ch=getchar();ch!='E'&&ch!='F';ch=getchar());
        scanf("%d%d",&x,&y);
        if(ch=='E') merge(x,y+n),merge(x+n,y);
        else if(ch=='F') merge(x,y);
    }
    for(int i=1;i<=n;i++)
        book[getf(i)]=true;
    for(int i=1;i<=n*2;i++)
        if(book[i]) ans++;
    printf("%d",ans);
    return 0;
}