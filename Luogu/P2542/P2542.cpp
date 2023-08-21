#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=30005,M=100005,Q=40005;
int n,m,q;
int x[M],y[M];
struct Operation
{
    int op,u,v;
}p[Q];
int ans[Q];
int fa[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    else return fa[v]=getf(fa[v]);
}
void merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2) fa[f1]=f2;
    return;
}
struct LCT
{
    struct Node
    {
        int fa,ls,rs;
        int sum,val;
        int rev;
        Node()
        {
            fa=ls=rs=0;
            sum=val=0;
            rev=0;
        }
    }tree[N];
    void push_up(int u)
    {
        tree[u].sum=tree[tree[u].ls].sum+tree[tree[u].rs].sum+tree[u].val;
        return;
    }
    void reverse(int u)
    {
        swap(tree[u].ls,tree[u].rs);
        tree[u].rev^=1;
        return;
    }
    void push_down(int u)
    {
        if(!tree[u].rev) return;
        if(tree[u].ls) reverse(tree[u].ls);
        if(tree[u].rs) reverse(tree[u].rs);
        tree[u].rev=0;
        return;
    }
    int get(int u)
    {
        if(tree[getf(tree[u].fa)].ls==u) return 0;
        if(tree[getf(tree[u].fa)].rs==u) return 1;
        return -1;
    }
    bool isroot(int u)
    {
        return get(u)==-1;
    }
    void connect(int u,int v,int op)
    {
        if(u) tree[u].fa=v;
        if(v)
        {
            if(op==0) tree[v].ls=u;
            if(op==1) tree[v].rs=u;
        }
        return;
    }
    void rotate(int u)
    {
        int f=getf(tree[u].fa),gf=getf(tree[f].fa),r=get(u),gr=get(f);
        int v=0;
        if(r==1) v=tree[u].ls;
        if(r==0) v=tree[u].rs;
        connect(u,gf,gr);
        connect(v,f,r);
        connect(f,u,r^1);
        push_up(f);
        push_up(u);
        return;
    }
    void pushall(int u)
    {
        if(!isroot(u)) pushall(getf(tree[u].fa));
        push_down(u);
        return;
    }
    void splay(int u)
    {
        pushall(u);
        while(!isroot(u))
        {
            int f=getf(tree[u].fa);
            if(!isroot(f)) rotate(get(u)==get(f)?f:u);
            rotate(u);
        }
        return;
    }
    int access(int u)
    {
        int v;
        for(v=0;u;v=u,u=getf(tree[u].fa))
        {
            splay(u);
            tree[u].rs=v;
            push_up(u);
        }
        return v;
    }
    void makeroot(int u)
    {
        access(u);
        splay(u);
        reverse(u);
        return;
    }
    int findroot(int u)
    {
        u=getf(u);
        access(u);
        splay(u);
        push_down(u);
        while(tree[u].ls) u=tree[u].ls,push_down(u);
        splay(u);
        return u;
    }
    void split(int x,int y)
    {
        makeroot(x);
        access(y);
        splay(y);
        return;
    }
    bool link(int x,int y)
    {
        x=getf(x),y=getf(y);
        if(findroot(x)==findroot(y)) return false;
        makeroot(x);
        tree[x].fa=getf(y);
        return true;
    }
    void dfs(int u,int v)
    {
        ::merge(u,v);
        push_down(u);
        if(tree[u].ls) dfs(tree[u].ls,v);
        if(tree[u].rs) dfs(tree[u].rs,v);
        return;
    };
    void merge(int u,int v)
    {
        u=getf(u),v=getf(v);
        split(u,v);
        tree[v].val=1;
        dfs(v,v);
        tree[v].ls=0;
        return;
    }
    int query(int u,int v)
    {
        u=getf(u),v=getf(v);
        split(u,v);
        return tree[v].sum;
    }
}T;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        fa[i]=i,T.tree[i].sum=T.tree[i].val=1;
    map<pair<int,int>,bool>vis;
    while(true)
    {
        int op,u,v;
        scanf("%d",&op);
        if(op==-1) break;
        scanf("%d%d",&u,&v);
        p[++q]=(Operation){op,u,v};
        if(op==0) vis[make_pair(u,v)]=vis[make_pair(v,u)]=true;
    }
    for(int i=1;i<=m;i++)
        if(!vis[make_pair(x[i],y[i])])
        {
            if(T.findroot(x[i])==T.findroot(y[i])) T.merge(x[i],y[i]);
            else T.link(x[i],y[i]);
        }
    for(int i=q;i>=1;i--)
    {
        if(p[i].op==0)
        {
            if(T.findroot(p[i].u)==T.findroot(p[i].v)) T.merge(p[i].u,p[i].v);
            else T.link(p[i].u,p[i].v);
        }
        else if(p[i].op==1) ans[i]=T.query(p[i].u,p[i].v)-1;
    }
    for(int i=1;i<=q;i++)
        if(p[i].op==1) printf("%d\n",ans[i]);
    return 0;
}