#include<iostream>
#include<cstdio>
#include<vector>
#include<chrono>
#include<random>
#include<numeric>
#include<algorithm>
#include"bubblesort2.h"
using namespace std;
const int N=500005;
int n,m,q;
int a[N],b[N];
int x[N],v[N];
int res[N];
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
struct FHQ_Treap
{
    struct Node
    {
        int ls,rs;
        pair<int,int> val;
        int v,mx;
        int tag;
        unsigned long long rd;
        int siz;
        void clear()
        {
            ls=rs=0;
            val=make_pair(0,0);
            v=mx=0;
            tag=0;
            rd=0;
            siz=0;
            return;
        }
    }tree[N+N];
    int rt,tot;
    FHQ_Treap():rt(0),tot(0){}
    void clear()
    {
        rt=tot=0;
        return;
    }
    int new_node(pair<int,int> val,int v)
    {
        int now=++tot;
        tree[now].clear();
        tree[now].val=val,tree[now].mx=tree[now].v=v;
        tree[now].rd=rnd();
        tree[now].tag=0;
        tree[now].siz=1;
        return now;
    }
    void push_up(int u)
    {
        tree[u].siz=tree[tree[u].ls].siz+tree[tree[u].rs].siz+1;
        tree[u].mx=max(max(tree[tree[u].ls].mx,tree[tree[u].rs].mx),tree[u].v);
        return;
    }
    void add(int u,int v)
    {
        if(!u) return;
        tree[u].mx+=v;
        tree[u].v+=v;
        tree[u].tag+=v;
        return;
    }
    void push_down(int u)
    {
        if(!u) return;
        if(!tree[u].tag) return;
        add(tree[u].ls,tree[u].tag);
        add(tree[u].rs,tree[u].tag);
        tree[u].tag=0;
        return;
    }
    int merge(int u,int v)
    {
        if(!u) return v;
        if(!v) return u;
        push_down(u),push_down(v);
        if(tree[u].rd<tree[v].rd)
        {
            tree[u].rs=merge(tree[u].rs,v);
            push_up(u); 
            return u;
        }
        else
        {
            tree[v].ls=merge(u,tree[v].ls);
            push_up(v);
            return v;
        }
    }
    void split(int now,pair<int,int> k,int &x,int &y)
    {
        if(!now)
        {
            x=y=0;
            return;
        }
        push_down(now);
        if(tree[now].val<=k)
        {
            x=now;
            split(tree[now].rs,k,tree[x].rs,y);
        }
        else
        {
            y=now;
            split(tree[now].ls,k,x,tree[y].ls);
        }
        push_up(now);
        return;
    }
    void insert(pair<int,int> val,int v)
    {
        int x,y;
        split(rt,val,x,y);
        rt=merge(merge(x,new_node(val,v)),y);
        return;
    }
    void erase(pair<int,int> val)
    {
        int x,y,z;
        split(rt,val,x,z);
        split(x,make_pair(val.first,val.second-1),x,y);
        y=merge(tree[y].ls,tree[y].rs);
        rt=merge(merge(x,y),z);
        return;
    }
    void add(int l,int r,int v)
    {
        int x,y,z;
        split(rt,make_pair(r,n),x,z);
        split(x,make_pair(l-1,n),x,y);
        add(y,v);
        rt=merge(merge(x,y),z);
        return;
    }
    int query_size(int l,int r)
    {
        int x,y,z;
        split(rt,make_pair(r,n),x,z);
        split(x,make_pair(l-1,n),x,y);
        int res=tree[y].siz;
        rt=merge(merge(x,y),z);
        return res;
    }
    int query_max(int l,int r)
    {
        int x,y,z;
        split(rt,make_pair(r,n),x,z);
        split(x,make_pair(l-1,n),x,y);
        int res=tree[y].mx;
        rt=merge(merge(x,y),z);
        return res;
    }
}T;
vector<int> countScans(vector<int> A,vector<int> X,vector<int> V)
{
    n=A.size(),q=X.size();
    for(int i=1;i<=n;i++)
        a[i]=A[i-1];
    for(int i=1;i<=q;i++)
        x[i]=X[i-1]+1,v[i]=V[i-1];
    m=1000000000;
    T.clear();
    static int id[N];
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &x,const int &y){return a[x]<a[y];});
    for(int i=1,j=1;i<=n;i=j)
    {
        while(j<=n&&a[id[i]]==a[id[j]]) j++;
        for(int k=i;k<j;k++)
            b[id[k]]=id[k]-(j-1);
    }
    for(int i=1;i<=n;i++)
        T.insert(make_pair(a[i],i),b[i]);
    for(int i=1;i<=q;i++)
    {
        T.erase(make_pair(a[x[i]],x[i]));
        T.add(a[x[i]],m,1);
        a[x[i]]=v[i];
        T.add(a[x[i]],m,-1);
        b[x[i]]=x[i]-(T.query_size(1,a[x[i]])+1);
        T.insert(make_pair(a[x[i]],x[i]),b[x[i]]);
        res[i]=T.query_max(1,m);
    }
    vector<int>s(q);
    for(int i=1;i<=q;i++)
        s[i-1]=res[i];
    return s;
}