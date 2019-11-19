#include<iostream>
#include<cstdio>
using namespace std;
const int N=20001;
int T,n,m;
int f[N];
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
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n*2;i++)
            f[i]=i;
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            merge(x,y+n);
            merge(y,x+n);
        }
        if(m>=n+2)
        {
            printf("NO\n");
            continue;
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
            if(getf(i)==getf(i+n))
            {
                printf("NO\n");
                flag=false;
                break;
            }
        if(flag) printf("YES\n");
    }
    return 0;
}
