#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n,m;
struct Node
{
    int lc,rc;
    int dis,val;
}tree[N];
int fa[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    fa[v]=getf(fa[v]);
    return fa[v];
}
int merge(int u,int v)
{
    if(!u) return v;
    if(!v) return u;
    if(tree[u].val>tree[v].val||(tree[u].val==tree[v].val&&u>v)) swap(u,v);
    tree[u].rc=merge(tree[u].rc,v);
    if(tree[tree[u].lc].dis<tree[tree[u].rc].dis) swap(tree[u].lc,tree[u].rc);
    fa[u]=fa[tree[u].lc]=fa[tree[u].rc]=u;
    tree[u].dis=tree[tree[u].rc].dis+1;
    return u;
}
void unity(int x,int y)
{
	x=getf(x),y=getf(y);
	if(x!=y) fa[x]=fa[y]=merge(x,y);
    return;
}
void pop(int u)
{
    tree[u].val=-1;
    fa[tree[u].lc]=tree[u].lc,fa[tree[u].rc]=tree[u].rc;
    fa[u]=merge(tree[u].lc,tree[u].rc);
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    tree[0].dis=-1;
    for(int i=1;i<=n;i++)
        scanf("%d",&tree[i].val);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int op,x,y;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d",&x,&y);
            if(tree[x].val==-1||tree[y].val==-1) continue;
            unity(x,y);
        }
        else if(op==2)
        {
        	scanf("%d",&x);
            if(tree[x].val==-1) printf("-1\n");
            else
            {
                x=getf(x);
                printf("%d\n",tree[x].val);
                pop(x);
            }
        }
    }
    return 0;
}