#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n,m,Q;
int f[N],id[N],rt[N],root;
struct Node
{
    int ls,rs,sum;
}tree[N<<5];
int getf(int v)
{
    if(f[v]==v) return v;
    f[v]=getf(f[v]);
    return f[v];
}
void update(int &i,int l,int r,int u)
{
    i=++root;
    tree[i].sum++;
    if(l==r) return;
    int mid=(l+r)/2;
    if(u<=mid) update(tree[i].ls,l,mid,u);
    else update(tree[i].rs,mid+1,r,u);
    return;
}
int merge(int i,int u,int l,int r)
{
    if(!i) return u;
    if(!u) return i;
    tree[i].sum+=tree[u].sum;
    if(l==r) return i;
    int mid=(l+r)/2;
    tree[i].ls=merge(tree[i].ls,tree[u].ls,l,mid),
    tree[i].rs=merge(tree[i].rs,tree[u].rs,mid+1,r);
    return i;
}
int query(int i,int l,int r,int u)
{
    if(l==r) return l;
    int mid=(l+r)/2;
    if(u<=tree[tree[i].ls].sum) return query(tree[i].ls,l,mid,u);
    else return query(tree[i].rs,mid+1,r,u-tree[tree[i].ls].sum);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        id[x]=i;
        update(rt[i],1,n,x);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x=getf(x),y=getf(y);
        if(x!=y) f[y]=x,rt[x]=merge(rt[x],rt[y],1,n);
    }
    scanf("%d",&Q);
    while(Q--)
    {
        char ch;
        int x,y;
        for(ch=getchar();ch!='Q'&&ch!='B';ch=getchar());
        scanf("%d%d",&x,&y);
        if(ch=='B')
        {
            x=getf(x),y=getf(y);
            if(x!=y) f[y]=x,merge(rt[x],rt[y],1,n);
        }
        else
        {
            x=getf(x);
            if(y>tree[rt[x]].sum) printf("-1\n");
            else printf("%d\n",id[query(rt[x],1,n,y)]);
        }     
    }
    return 0;
}