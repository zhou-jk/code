#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int fa[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    else return fa[v]=getf(fa[v]);
}
struct LCT
{
    struct Node
    {
        int fa,ls,rs;
        int siz,siz2;
        int rev;
    }tree[N];
    void push_up(int u)
    {
        tree[u].siz=tree[tree[u].ls].siz+tree[tree[u].rs].siz+tree[u].siz2+1;
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
            tree[u].siz2+=tree[tree[u].rs].siz-tree[v].siz;
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
        if(findroot(x)==findroot(y)) return false;
        makeroot(x);
        makeroot(y);
        tree[x].fa=y;
        tree[y].siz2+=tree[x].siz;
        return true;
    }
    int query(int u)
    {
        int s=tree[u].siz/2;
        int lsum=0,rsum=0;
        int p=0;
        while(u)
        {
            push_down(u);
            int nowl=lsum+tree[tree[u].ls].siz,nowr=rsum+tree[tree[u].rs].siz;
            if(nowl<=s&&nowr<=s)
            {
                if(p==0||p>u) p=u;
            }
            if(nowl<nowr) lsum+=tree[tree[u].ls].siz+tree[u].siz2+1,u=tree[u].rs;
            else rsum+=tree[tree[u].rs].siz+tree[u].siz2+1,u=tree[u].ls;
        }
        splay(p);
        return p;
    }
}T;
int n,q;
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        T.tree[i].siz=1,T.tree[i].siz2=0;
    int sum=0;
    for(int i=1;i<=n;i++)
        fa[i]=i,sum^=i;
    while(q--)
    {
        string op;
        cin>>op;
        if(op=="A")
        {
            int u,v;
            cin>>u>>v;
            int x=getf(u),y=getf(v);
            sum^=x^y;
            T.link(u,v);
            T.split(x,y);
            int p=T.query(y);
            fa[x]=fa[y]=fa[p]=p;
            sum^=p;
        }
        else if(op=="Q")
        {
            int x;
            cin>>x;
            cout<<getf(x)<<"\n";
        }
        else if(op=="Xor") cout<<sum<<"\n";
    }
    return 0;
}