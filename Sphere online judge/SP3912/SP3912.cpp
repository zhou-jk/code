#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1001;
double b[N];
int Next[N],f[N],a[N],cnt[N],fa[N];
bool book[N];
int child(int r)
{
    while(Next[r]!=r)
        r=Next[r];
    return r;
}
int getf(int v)
{
    if(fa[v]==v) return v;
    fa[v]=getf(fa[v]);
    return fa[v];
}
int n,r;
int main()
{
    while(1)
    {
        scanf("%d%d",&n,&r);
        if(n==0&&r==0) return 0;
        memset(book,false,sizeof(book));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
            fa[i]=f[i]=Next[i]=i;
            cnt[i]=1;
        }
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            f[v]=u;
        }
        book[r]=true;
        for(int j=1;j<n;j++)
        {
            double Max=0;
            int v;
            for(int i=1;i<=n;i++)
                if(!book[i]&&Max<b[i]/cnt[i]) Max=b[i]/cnt[i],v=i;
            int u=child(f[v]);
            Next[u]=v;
            fa[v]=u;
            u=getf(v);
            cnt[u]=cnt[u]+cnt[v];
            b[u]=b[u]+b[v];
            book[v]=true;
        }
        int ans=0,k=1;
        while(r!=Next[r])
        {
            ans+=k*a[r],k++;
            r=Next[r];
        }
        ans+=k*a[r];
        printf("%d\n",ans);
    }
    return 0;
}