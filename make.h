#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstdlib>
#include<ctime>
#include<map>
#include<tuple>
#include<algorithm>
#include<random>
#include<chrono>
#include<numeric>
#include<functional>
using namespace std;
namespace DataMaker
{
    static mt19937_64 myrand(chrono::system_clock::now().time_since_epoch().count());
    unsigned long long rand()
    {
        return myrand();
    }
    template<typename T>
    T rand(T l,T r)
    {
        return myrand()%(r-l+1)+l;
    }
    template<typename T>
    pair<T,T> rand_seg(T l,T r)
    {
        T L=rand(l,r),R=rand(l,r);
        if(L>R) swap(L,R);
        return make_pair(L,R);
    }
    template<typename T>
    void rand_shuffle(T _begin,T _end)
    {
        for(int i=1;i<=10;i++)
            shuffle(_begin,_end,myrand);
        return;
    }
    vector<pair<int,int>>rand_tree(int n)
    {
        vector<int>fa(n+1);
        iota(fa.begin(),fa.end(),0);
        function<int(int v)>getf=[&](int v)->int
        {
            if(v==fa[v]) return v;
            fa[v]=getf(fa[v]);
            return fa[v];
        };
        function<void(int u,int v)>merge=[&](int u,int v)->void
        {
            int f1=getf(u),f2=getf(v);
            if(f1!=f2) fa[f2]=f1;
            return;
        };
        vector<pair<int,int>>edge;
        for(int i=1;i<=n-1;i++)
        {
            int u=rand(1,n),v=rand(1,n);
            while(getf(u)==getf(v)) u=rand(1,n),v=rand(1,n);
            merge(u,v);
            edge.emplace_back(u,v);
        }
        rand_shuffle(edge.begin(),edge.end());
        return edge;
    }
    vector<tuple<int,int,int>>rand_value_tree(int n,int c)
    {
        vector<pair<int,int>>edge=rand_tree(n);
        vector<tuple<int,int,int>>G;
        for(auto [u,v]:edge)
            G.emplace_back(u,v,rand(1,c));
        rand_shuffle(G.begin(),G.end());
        return G;
    }
    vector<pair<int,int>>rand_chain_tree(int n,int rt=0)
    {
        vector<int>p(n);
        iota(p.begin(),p.end(),1);
        if(rt>0)
        {
            assert(rt>=1&&rt<=n);
            swap(p[0],p[rt-1]);
            rand_shuffle(p.begin()+1,p.end());
            assert(p[0]==rt);
        }
        else rand_shuffle(p.begin(),p.end());
        vector<pair<int,int>>edge;
        for(int i=1;i<n;i++)
            edge.emplace_back(p[i-1],p[i]);
        rand_shuffle(edge.begin(),edge.end());
        return edge;
    }
    vector<tuple<int,int,int>>rand_value_chain_tree(int n,int c,int rt=0)
    {
        vector<pair<int,int>>edge=rand_chain_tree(n,rt);
        vector<tuple<int,int,int>>G;
        for(auto [u,v]:edge)
            G.emplace_back(u,v,rand(1,c));
        rand_shuffle(G.begin(),G.end());
        return G;
    }
    vector<pair<int,int>>rand_chrysanthemum_tree(int n,int rt=0)
    {
        vector<int>p(n);
        iota(p.begin(),p.end(),1);
        if(rt>0)
        {
            assert(rt>=1&&rt<=n);
            swap(p[0],p[rt-1]);
            rand_shuffle(p.begin()+1,p.end());
            assert(p[0]==rt);
        }
        else rand_shuffle(p.begin(),p.end());
        int u=p[0];
        vector<pair<int,int>>edge;
        for(int v:p)
            if(v!=u)
            {
                if(rand(0,1)) edge.emplace_back(u,v);
                else edge.emplace_back(v,u);
            }
        rand_shuffle(edge.begin(),edge.end());
        return edge;
    }
    vector<tuple<int,int,int>>rand_value_chrysanthemum_tree(int n,int c,int rt=0)
    {
        vector<pair<int,int>>edge=rand_chrysanthemum_tree(n,rt);
        vector<tuple<int,int,int>>G;
        for(auto [u,v]:edge)
            G.emplace_back(u,v,rand(1,c));
        rand_shuffle(G.begin(),G.end());
        return G;
    }
    vector<pair<int,int>>rand_complete_binary_tree(int n,int rt=0)
    {
        vector<int>p(n);
        iota(p.begin(),p.end(),1);
        if(rt>0)
        {
            assert(rt>=1&&rt<=n);
            swap(p[0],p[rt-1]);
            rand_shuffle(p.begin()+1,p.end());
            assert(p[0]==rt);
        }
        else rand_shuffle(p.begin(),p.end());
        int cnt=0;
        vector<int>pre={p[0]};
        vector<pair<int,int>>G;
        while(cnt+1<(int)p.size())
        {
            vector<int>now;
            for(int u:pre)
            {
                if(cnt+1==(int)p.size()) break;
                int ls=p[++cnt];
                now.emplace_back(ls);
                if(rand(0,1)) G.emplace_back(u,ls);
                else G.emplace_back(ls,u);
                if(cnt+1==(int)p.size()) break;
                int rs=p[++cnt];
                now.emplace_back(rs);
                if(rand(0,1)) G.emplace_back(u,rs);
                else G.emplace_back(rs,u);
            }
            pre=now;
        }
        rand_shuffle(G.begin(),G.end());
        return G;
    }
    vector<pair<int,int>>rand_circle_tree(int n)
    {
        vector<pair<int,int>>edge=rand_tree(n);
        map<pair<int,int>,bool>book;
        for(auto [u,v]:edge)
            book[{u,v}]=book[{v,u}]=true;
        int u=rand(1,n),v=rand(1,n);
        while(u==v||book[{u,v}]) u=rand(1,n),v=rand(1,n);
        edge.emplace_back(u,v);
        book[{u,v}]=book[{v,u}]=true;
        rand_shuffle(edge.begin(),edge.end());
        return edge;
    }
    vector<tuple<int,int,int>>rand_value_circle_tree(int n,int c)
    {
        vector<pair<int,int>>edge=rand_circle_tree(n);
        vector<tuple<int,int,int>>G;
        for(auto [u,v]:edge)
            G.emplace_back(u,v,rand(1,c));
        rand_shuffle(G.begin(),G.end());
        return G;
    }
    vector<pair<int,int>>rand_graph(int n,int m)
    {
        vector<pair<int,int>>edge;
        map<pair<int,int>,bool>book;
        for(int i=1;i<=m;i++)
        {
            int u=rand(1,n),v=rand(1,n);
            while(u==v||book[{u,v}]) u=rand(1,n),v=rand(1,n);
            edge.emplace_back(u,v);
            book[{u,v}]=true;
        }
        rand_shuffle(edge.begin(),edge.end());
        return edge;
    }
    vector<tuple<int,int,int>>rand_value_graph(int n,int m,int c)
    {
        vector<pair<int,int>>edge=rand_graph(n,m);
        vector<tuple<int,int,int>>G;
        for(auto [u,v]:edge)
            G.emplace_back(u,v,rand(1,c));
        rand_shuffle(G.begin(),G.end());
        return G;
    }
    vector<pair<int,int>>rand_connected_graph(int n,int m)
    {
        assert(m>=n-1);
        vector<pair<int,int>>edge=rand_tree(n);
        map<pair<int,int>,bool>book;
        for(auto [u,v]:edge)
            book[{u,v}]=book[{v,u}]=true;
        for(int i=1;i<=m-(n-1);i++)
        {
            int u=rand(1,n),v=rand(1,n);
            while(u==v||book[{u,v}]) u=rand(1,n),v=rand(1,n);
            edge.emplace_back(u,v);
            book[{u,v}]=book[{v,u}]=true;
        }
        rand_shuffle(edge.begin(),edge.end());
        return edge;
    }
    vector<tuple<int,int,int>>rand_connected_value_graph(int n,int m,int c)
    {
        vector<pair<int,int>>edge=rand_connected_graph(n,m);
        vector<tuple<int,int,int>>G;
        for(auto [u,v]:edge)
            G.emplace_back(u,v,rand(1,c));
        rand_shuffle(G.begin(),G.end());
        return G;
    }
}
