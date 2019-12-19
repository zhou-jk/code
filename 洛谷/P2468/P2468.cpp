#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=201,maxm=1000;
const int N=500001,M=7000001;
int n,m,q;
int a[maxn][maxn],f[maxn][maxn][maxm+1],g[maxn][maxn][maxm+1];
void solve1()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=maxm;k++)
                f[i][j][k]=f[i][j-1][k]+f[i-1][j][k]-f[i-1][j-1][k],g[i][j][k]=g[i][j-1][k]+g[i-1][j][k]-g[i-1][j-1][k];
            f[i][j][a[i][j]]+=a[i][j],g[i][j][a[i][j]]++;
        }
    for(int k=maxm-1;k>=1;k--)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                f[i][j][k]+=f[i][j][k+1],g[i][j][k]+=g[i][j][k+1];
    for(int i=1,x1,y1,x2,y2,h;i<=q;i++)
    {
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&h);
        int l=1,r=maxm,ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(f[x2][y2][mid]-f[x1-1][y2][mid]-f[x2][y1-1][mid]+f[x1-1][y1-1][mid]>=h) ans=mid,l=mid+1;
            else r=mid-1;
        }
        if(ans==-1)
        {
            printf("Poor QLW\n");
            continue;
        }
        int cnt=g[x2][y2][ans]-g[x1-1][y2][ans]-g[x2][y1-1][ans]+g[x1-1][y1-1][ans];
        int tmp=(g[x2][y2][ans]-g[x2][y2][ans+1])-(g[x1-1][y2][ans]-g[x1-1][y2][ans+1])-(g[x2][y1-1][ans]-g[x2][y1-1][ans+1])+(g[x1-1][y1-1][ans]-g[x1-1][y1-1][ans+1]);
        int res=f[x2][y2][ans]-f[x1-1][y2][ans]-f[x2][y1-1][ans]+f[x1-1][y1-1][ans];
        cnt-=tmp;
        while(tmp&&res-ans>=h) tmp--,res-=ans;
        printf("%d\n",cnt+tmp);
    }
    return;
}
int s[N];
struct Node
{
    int lc,rc;
    int sum,num;
}tree[M];
int rt[N],tot;
void push_up(int i)
{
    tree[i].sum=tree[tree[i].lc].sum+tree[tree[i].rc].sum;
    tree[i].num=tree[tree[i].lc].num+tree[tree[i].rc].num;
    return;
}
void build(int &i,int l,int r)
{
    i=++tot;
    if(l==r) return;
    int mid=(l+r)/2;
    build(tree[i].lc,l,mid);
    build(tree[i].rc,mid+1,r);
    return;
}
int update(int i,int l,int r,int u)
{
    int now=++tot;
    tree[now].lc=tree[i].lc,tree[now].rc=tree[i].rc;
    tree[now].sum=tree[i].sum,tree[now].num=tree[i].num;
    if(l==r)
    {
        tree[now].sum+=u;
        tree[now].num++;
        return now;
    }
    int mid=(l+r)/2;
    if(u<=mid) tree[now].lc=update(tree[i].lc,l,mid,u);
    else tree[now].rc=update(tree[i].rc,mid+1,r,u);
    push_up(now);
    return now;
}
int query(int u,int v,int l,int r,int k)
{
    if(l==r) return (k+l-1)/l;
    int mid=(l+r)/2;
    if(tree[tree[v].rc].sum-tree[tree[u].rc].sum>=k)
        return query(tree[u].rc,tree[v].rc,mid+1,r,k);
    else
        return query(tree[u].lc,tree[v].lc,l,mid,k-tree[tree[v].rc].sum+tree[tree[u].rc].sum)+tree[tree[v].rc].num-tree[tree[u].rc].num;
}
void solve2()
{
    build(rt[0],1,maxm);
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        s[i]=s[i-1]+x;
        rt[i]=update(rt[i-1],1,maxm,x);
    }
    for(int i=1;i<=q;i++)
    {
        int x1,y1,x2,y2,h;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&h);
        if(s[y2]-s[y1-1]<h) printf("Poor QLW\n");
        else printf("%d\n",query(rt[y1-1],rt[y2],1,maxm,h));
    }
    return;
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    if(n!=1) solve1();
    else solve2();
    return 0;
}