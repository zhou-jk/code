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
    if(tree[u].val<tree[v].val) swap(u,v);
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
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        tree[0].dis=-1;
        for(int i=1;i<=n;i++)
            scanf("%d",&tree[i].val);
        for(int i=1;i<=n;i++)
            fa[i]=i,tree[i].lc=tree[i].rc=0;
        scanf("%d",&m);
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x=getf(x),y=getf(y);
            if(x==y)
            {
                printf("-1\n");
                continue;
            }
            int root,p,q;
            tree[x].val/=2;
            root=merge(tree[x].lc,tree[x].rc);
            tree[x].lc=tree[x].rc=0;
            p=merge(root,x);
            tree[y].val/=2;
            root=merge(tree[y].lc,tree[y].rc);
            tree[y].lc=tree[y].rc=0;
            q=merge(root,y);
            root=merge(p,q);
            fa[x]=fa[y]=fa[p]=fa[q]=root;
            printf("%d\n",tree[root].val);
        }
    }
    return 0;
}