#include<iostream>
#include<cstdio>
using namespace std;
const int N=150005;
struct LCT
{
    struct Node
    {
        int fa,ls,rs;
        int val,sum;
        int rev;
    }tree[N];
    void push_up(int u)
    {
        tree[u].sum=tree[tree[u].ls].sum^tree[tree[u].rs].sum^tree[u].val;
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
    int query(int x,int y)
    {
        makeroot(x);
        if(findroot(y)!=x) return -1;
        split(x,y);
        return tree[y].sum; 
    }
    void modify(int u,int v)
    {
        splay(u);
        tree[u].val=v;
        return;
    }
}T;
int n,m;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        T.tree[i].sum=T.tree[i].val=a[i];
    for(int i=1;i<=m;i++)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==0) cout<<T.query(x,y)<<"\n";
        else if(op==1) T.link(x,y);
        else if(op==2) T.cut(x,y);
        else if(op==3) T.modify(x,y);
    }
    return 0;
}