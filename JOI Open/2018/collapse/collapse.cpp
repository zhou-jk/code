#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<tuple>
#include<stack>
#include"collapse.h"
using namespace std;
const int N=100005;
int n,m,q;
int t[N],x[N],y[N],w[N],p[N];
map<pair<int,int>,int>pos;
struct LCT
{
    struct Node
    {
        int fa,ls,rs;
        int rev;
        pair<int,tuple<int,int,int>>mx,val;
        void clear()
        {
            fa=ls=rs=0;
            mx=val=make_pair(0,make_tuple(0,0,0));
            rev=0;
            return;
        }
    }tree[N+N];
    int tot;
    LCT():tot(0){}
    LCT(int _n)
    {
        tot=_n;
        for(int i=1;i<=tot;i++)
            tree[i].clear();
        return;
    }
    void clear()
    {
        tot=0;
        return;
    }
    void resize(int _n)
    {
        for(int i=tot+1;i<=_n;i++)
            tree[i].clear();
        tot=_n;
        return;
    }
    int new_node(pair<int,tuple<int,int,int>> val=make_pair(0,make_tuple(0,0,0)))
    {
        int now=++tot;
        tree[now].clear();
        tree[now].mx=tree[now].val=val;
        return now;
    }
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
    pair<int,tuple<int,int,int>>query(int x,int y)
    {
        split(x,y);
        return tree[y].mx;
    }
}lct;
struct BIT
{
    int C[N];
    void clear()
    {
        for(int i=1;i<=n;i++)
            C[i]=0;
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
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
}bit;
stack<tuple<int,int,int,int>>stk;
vector<pair<int,int>>query[N];
int ans[N];
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        vector<tuple<int,int,int>>add;
    }tree[N<<2];
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].add.clear();
        if(l==r) return;
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        return;
    }
    void add(int i,int l,int r,tuple<int,int,int> e)
    {
        if(l<=tree[i].l&&tree[i].r<=r)
        {
            tree[i].add.emplace_back(e);
            return;
        }
        if(l<=tree[ls].r) add(ls,l,r,e);
        if(r>=tree[rs].l) add(rs,l,r,e);
        return;
    }
    void solve(int i)
    {
        tuple<int,int,int,int> pre=make_tuple(-1,-1,-1,-1);
        if(!stk.empty()) pre=stk.top();
        for(auto [u,v,w]:tree[i].add)
        {
            if(lct.findroot(u)!=lct.findroot(v))
            {
                lct.link(u,w),lct.link(v,w);
                bit.add(max(u,v),1);
                stk.emplace(1,u,v,w);
            }
            else
            {
                auto [val,e]=lct.query(u,v);
                auto [uu,vv,ww]=e;
                if(max(u,v)<val)
                {
                    lct.cut(uu,ww),lct.cut(vv,ww);
                    bit.add(max(uu,vv),-1);
                    stk.emplace(-1,uu,vv,ww);
                    lct.link(u,w),lct.link(v,w);
                    bit.add(max(u,v),1);
                    stk.emplace(1,u,v,w);
                }
            }
        }
        if(tree[i].l==tree[i].r)
        {
            for(auto [p,id]:query[tree[i].l])
                ans[id]+=p-bit.getsum(p);
        }
        else
        {
            solve(ls);
            solve(rs);
        }
        while(!stk.empty()&&stk.top()!=pre)
        {
            auto [op,u,v,w]=stk.top();
            stk.pop();
            if(op==1) lct.cut(u,w),lct.cut(v,w),bit.add(max(u,v),-1);
            else if(op==-1) lct.link(u,w),lct.link(v,w),bit.add(max(u,v),1);
        }
        return;
    }
    #undef ls
    #undef rs
}st;
vector<int> simulateCollapse(int N,vector<int> T,vector<int> X,vector<int> Y,vector<int> W,vector<int> P)
{
    n=N,m=T.size(),q=W.size();
    for(int i=1;i<=m;i++)
        t[i]=T[i-1],x[i]=X[i-1]+1,y[i]=Y[i-1]+1;
    for(int i=1;i<=q;i++)
        w[i]=W[i-1]+1,p[i]=P[i-1]+1;
    for(int i=1;i<=m;i++)
        if(x[i]>y[i]) swap(x[i],y[i]);
    {
        lct.clear();
        lct.resize(n);
        for(int i=1;i<=n;i++)
            lct.tree[i].mx=lct.tree[i].val=make_pair(0,make_tuple(i,i,i));
        pos.clear();
        for(int i=1;i<=m;i++)
            if(!pos.count(make_pair(x[i],y[i])))
            {
                int now=lct.new_node();
                lct.tree[now].mx=lct.tree[now].val=make_pair(max(x[i],y[i]),make_tuple(x[i],y[i],now));
                pos[make_pair(x[i],y[i])]=now;
            }
        st.build(1,1,m);
        map<pair<int,int>,int>lst;
        for(int i=1;i<=m;i++)
            if(t[i]==0) lst[make_pair(x[i],y[i])]=i;
            else st.add(1,lst[make_pair(x[i],y[i])],i-1,make_tuple(x[i],y[i],pos[make_pair(x[i],y[i])])),lst.erase(make_pair(x[i],y[i]));
        for(auto [e,i]:lst)
            st.add(1,i,m,make_tuple(x[i],y[i],pos[make_pair(x[i],y[i])]));
        for(int i=1;i<=m;i++)
            query[i].clear();
        for(int i=1;i<=q;i++)
            query[w[i]].emplace_back(p[i],i);
        bit.clear();
        st.solve(1);
    }
    for(int i=1;i<=m;i++)
        x[i]=n-x[i]+1,y[i]=n-y[i]+1;
    for(int i=1;i<=q;i++)
        p[i]=n-(p[i]+1)+1;
    {
        lct.clear();
        lct.resize(n);
        for(int i=1;i<=n;i++)
            lct.tree[i].mx=lct.tree[i].val=make_pair(0,make_tuple(i,i,i));
        pos.clear();
        for(int i=1;i<=m;i++)
            if(!pos.count(make_pair(x[i],y[i])))
            {
                int now=lct.new_node();
                lct.tree[now].mx=lct.tree[now].val=make_pair(max(x[i],y[i]),make_tuple(x[i],y[i],now));
                pos[make_pair(x[i],y[i])]=now;
            }
        st.build(1,1,m);
        map<pair<int,int>,int>lst;
        for(int i=1;i<=m;i++)
            if(t[i]==0) lst[make_pair(x[i],y[i])]=i;
            else st.add(1,lst[make_pair(x[i],y[i])],i-1,make_tuple(x[i],y[i],pos[make_pair(x[i],y[i])])),lst.erase(make_pair(x[i],y[i]));
        for(auto [e,i]:lst)
            st.add(1,i,m,make_tuple(x[i],y[i],pos[make_pair(x[i],y[i])]));
        for(int i=1;i<=m;i++)
            query[i].clear();
        for(int i=1;i<=q;i++)
            query[w[i]].emplace_back(p[i],i);
        bit.clear();
        st.solve(1);
    }
    vector<int>D(q);
    for(int i=1;i<=q;i++)
        D[i-1]=ans[i];
    return D;
}