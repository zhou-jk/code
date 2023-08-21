#include<iostream>
#include<cstdio>
using namespace std;
const int N=150005;
int n,m;
int a[N];
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
        long long sum,val;
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
        tree[v].val=tree[v].sum;
        dfs(v,v);
        tree[v].ls=0;
        return;
    }
    void modify(int x,int v)
    {
        int u=getf(x);
        splay(u);
        tree[u].sum+=v-a[x],tree[u].val+=v-a[x];
        return;
    }
    long long query(int u,int v)
    {
        u=getf(u),v=getf(v);
        split(u,v);
        return tree[v].sum;
    }
}T;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=n;i++)
        T.tree[i].sum=T.tree[i].val=a[i];
    cerr<<T.query(1,1)<<"\n";
    for(int i=1;i<=m;i++)
    {
        int op,u,v;
        scanf("%d%d%d",&op,&u,&v);
        if(op==1)
        {
            if(T.findroot(u)==T.findroot(v)) T.merge(u,v);
            else T.link(u,v);
        }
        else if(op==2) T.modify(u,v),a[u]=v;
        else if(op==3)
        {
            if(T.findroot(u)!=T.findroot(v)) printf("-1\n");
            else printf("%lld\n",T.query(u,v));
        }
    }
    return 0;
}