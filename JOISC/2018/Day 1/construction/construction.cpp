#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m;
int c[N];
struct LCT
{
    struct Node
    {
        int fa,ls,rs;
        int col,cov,siz;
        int rev;
    }tree[N];
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            tree[i].ls=tree[i].rs=tree[i].fa=0,tree[i].col=tree[i].cov=tree[i].rev=0,tree[i].siz=1;
        return;
    }
    void push_up(int u)
    {
        tree[u].siz=tree[tree[u].ls].siz+tree[tree[u].rs].siz+1;
        return;
    }
    void reverse(int u)
    {
        swap(tree[u].ls,tree[u].rs);
        tree[u].rev^=1;
        return;
    }
    void cover(int u,int c)
    {
        tree[u].col=tree[u].cov=c;
        return;
    }
    void push_down(int u)
    {
        if(tree[u].rev)
        {
            if(tree[u].ls) reverse(tree[u].ls);
            if(tree[u].rs) reverse(tree[u].rs);
            tree[u].rev=0;
        }
        if(tree[u].cov)
        {
            if(tree[u].ls) cover(tree[u].ls,tree[u].cov);
            if(tree[u].rs) cover(tree[u].rs,tree[u].cov);
            tree[u].cov=0;
        }
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
    vector<pair<int,int>> access(int u)
    {
        int v;
        vector<pair<int,int>>pos;
        for(v=0;u;v=u,u=tree[u].fa)
        {
            splay(u);
            pos.emplace_back(tree[u].col,tree[u].siz-tree[tree[u].rs].siz);
            tree[u].rs=v;
            push_up(u);
        }
        std::reverse(pos.begin(),pos.end());
        return pos;
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
    void modify(int u,int v,int c)
    {
        split(u,v);
        tree[v].col=tree[v].cov=c;
        return;
    }
}T;
struct BIT
{
    int n;
    int C[N];
    int lowbit(int x)
    {
        return x&-x;
    }
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            C[i]=0;
        return;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]+=y;
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=C[i];
        return res;
    }
    int query(int l,int r)
    {
        return getsum(r)-getsum(l-1);
    }
}TT;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    static int v[N];
    for(int i=1;i<=n;i++)
        v[++m]=c[i];
    sort(v+1,v+m+1);
    m=unique(v+1,v+m+1)-v-1;
    for(int i=1;i<=n;i++)
        c[i]=lower_bound(v+1,v+m+1,c[i])-v;
    T.init(n);
    for(int i=1;i<=n;i++)
        T.tree[i].col=c[i];
    TT.init(m);
    for(int t=1;t<n;t++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        T.makeroot(1);
        vector<pair<int,int>>pos=T.access(u);
        long long res=0;
        for(auto [w,siz]:pos)
        {
            if(w+1<=m) res+=(long long)TT.query(w+1,m)*siz;
            TT.add(w,siz);
        }
        for(auto [w,siz]:pos)
            TT.add(w,-siz);
        T.modify(1,u,c[v]);
        T.link(u,v);
        printf("%lld\n",res);
    }
    return 0;
}