#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int N=1005,M=100005,Q=100005;
struct LCT
{
    struct Node
    {
        int fa,ls,rs;
        int rev;
        pair<int,int>mx,val;
        Node()
        {
            fa=ls=rs=0;
            mx=val=make_pair(0,0);
            rev=0;
            return;
        }
    }tree[N+M];
    void push_up(int u)
    {
        tree[u].mx=max(max(tree[tree[u].ls].mx,tree[tree[u].rs].mx),tree[u].val);
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
        if(tree[tree[u].fa].ls==u) return 0;
        if(tree[tree[u].fa].rs==u) return 1;
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
        int f=tree[u].fa,gf=tree[f].fa,r=get(u),gr=get(f);
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
        if(!isroot(u)) pushall(tree[u].fa);
        push_down(u);
        return;
    }
    void splay(int u)
    {
        pushall(u);
        while(!isroot(u))
        {
            int f=tree[u].fa;
            if(!isroot(f)) rotate(get(u)==get(f)?f:u);
            rotate(u);
        }
        return;
    }
    int access(int u)
    {
        int v;
        for(v=0;u;v=u,u=tree[u].fa)
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
        makeroot(x);
        if(findroot(y)==x) return false;
        tree[x].fa=y;
        return true;
    }
    bool cut(int x,int y)
    {
        if(findroot(x)!=findroot(y)) return false;
        split(x,y);
        if(tree[x].fa!=y||tree[x].rs) return false;
        tree[x].fa=tree[y].ls=0;
        push_up(y);
        return true;
    }
    pair<int,int>query(int x,int y)
    {
        split(x,y);
        return tree[y].mx;
    }
}T;
int n,m,q;
struct Operation
{
    int op,u,v;
}p[Q];
int ans[Q];
struct Edge
{
    int u,v,w;
}edge[M];
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    sort(edge+1,edge+m+1,[](const Edge &a,const Edge &b){return a.w<b.w;});
    map<pair<int,int>,int>book;
    for(int i=1;i<=m;i++)
        book[make_pair(edge[i].u,edge[i].v)]=book[make_pair(edge[i].v,edge[i].u)]=i;
    for(int i=1;i<=n;i++)
        T.tree[i].mx=T.tree[i].val=make_pair(0,i);
    for(int i=1;i<=m;i++)
        T.tree[i+n].mx=T.tree[i+n].val=make_pair(edge[i].w,i+n);
    map<pair<int,int>,bool>vis;
    for(int i=1;i<=q;i++)
    {
        int op,u,v;
        scanf("%d%d%d",&op,&u,&v);
        p[i]=(Operation){op,u,v};
        if(op==2) vis[make_pair(u,v)]=vis[make_pair(v,u)]=true;
    }
    for(int i=1;i<=m;i++)
        if(!vis[make_pair(edge[i].u,edge[i].v)])
        {
            if(T.findroot(edge[i].u)==T.findroot(edge[i].v))
            {
                auto [val,w]=T.query(edge[i].u,edge[i].v);
                w-=n;
                if(edge[i].w<val)
                {
                    T.cut(edge[w].u,w+n),T.cut(edge[w].v,w+n);
                    T.link(edge[i].u,i+n),T.link(edge[i].v,i+n);
                }
            }
            else T.link(edge[i].u,i+n),T.link(edge[i].v,i+n);
        }
    for(int i=q;i>=1;i--)
    {
        if(p[i].op==1) ans[i]=T.query(p[i].u,p[i].v).first;
        else if(p[i].op==2)
        {
            int pos=book[make_pair(p[i].u,p[i].v)];
            if(T.findroot(p[i].u)==T.findroot(p[i].v))
            {
                auto [val,w]=T.query(p[i].u,p[i].v);
                w-=n;
                if(edge[pos].w<val)
                {
                    T.cut(edge[w].u,w+n),T.cut(edge[w].v,w+n);
                    T.link(p[i].u,pos+n),T.link(p[i].v,pos+n);
                }
            }
            else T.link(p[i].u,pos+n),T.link(p[i].v,pos+n);
        }
    }
    for(int i=1;i<=q;i++)
        if(p[i].op==1) printf("%d\n",ans[i]);
    return 0;
}