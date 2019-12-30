#include<iostream>
#include<cstdio>
using namespace std;
const int N=50005;
int f[N*3];
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
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=3*n;i++)
        f[i]=i;
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        int op,u,v;
        scanf("%d%d%d",&op,&u,&v);
        if(u>n||v>n)
        {
            ans++;
            continue;
        }
        if(op==1)
        {
            if(getf(u)==getf(v+n)||getf(u+n)==getf(v)) ans++;
            else
            {
                merge(u,v);
                merge(u+n,v+n);
                merge(u+n+n,v+n+n);
            }
        }
        else if(op==2)
        {
            if(getf(u)==getf(v)||getf(u)==getf(v+n)) ans++;
            else
            {
                merge(u,v+n+n);
                merge(u+n,v);
                merge(u+n+n,v+n);
            }
        }
    }
    printf("%d",ans);
    return 0;
}