#include"make.h"
#include<fstream>
using namespace std;
vector<int> get_fa(int n,const vector<vector<int>> &G,int rt)
{
    vector<int>fa(n+1,0);
    function<void(int,int)>dfs=[&](int u,int father)
    {
        fa[u]=father;
        for(int v:G[u])
        {
            if(v==father) continue;
            dfs(v,u);
        }
    };
    dfs(rt,0);
    return fa;
}
vector<int> gen_tree(int n)
{
    auto edge=DataMaker::rand_tree(n);
    vector<vector<int>>G(n+1,vector<int>{});
    for(auto [u,v]:edge)
        G[u].emplace_back(v),G[v].emplace_back(u);
    return get_fa(n,G,1);
}
vector<int> gen_chain(int n)
{
    auto edge=DataMaker::rand_chain_tree(n,1);
    vector<int>deg(n+1,0);
    for(auto [u,v]:edge)
        deg[u]++,deg[v]++;
    assert(deg[1]==1);
    vector<vector<int>>G(n+1,vector<int>{});
    for(auto [u,v]:edge)
        G[u].emplace_back(v),G[v].emplace_back(u);
    return get_fa(n,G,1);
}
vector<int> gen_chrysanthemum(int n)
{
    auto edge=DataMaker::rand_chrysanthemum_tree(n,1);
    vector<int>deg(n+1,0);
    for(auto [u,v]:edge)
        deg[u]++,deg[v]++;
    assert(deg[1]==n-1);
    vector<vector<int>>G(n+1,vector<int>{});
    for(auto [u,v]:edge)
        G[u].emplace_back(v),G[v].emplace_back(u);
    return get_fa(n,G,1);
}
vector<int> gen_complete(int n)
{
    auto edge=DataMaker::rand_complete_binary_tree(n,1);
    vector<vector<int>>G(n+1,vector<int>{});
    for(auto [u,v]:edge)
        G[u].emplace_back(v),G[v].emplace_back(u);
    return get_fa(n,G,1);
}
vector<int> gen_strong(int n)
{
    int n1=n/2,n2=n-n1+1;
    auto edge1=DataMaker::rand_chain_tree(n1,1);
    vector<int>deg(n+1,0);
    for(auto [u,v]:edge1)
        deg[u]++,deg[v]++;
    assert(deg[1]==1);
    int p=0;
    for(int i=2;i<=n;i++)
        if(deg[i]==1)
        {
            p=i;
            break;
        }
    auto edge2=DataMaker::rand_chrysanthemum_tree(n2,p);
    for(auto &[u,v]:edge2)
    {
        if(u!=p) u+=n1-(u>p);
        if(v!=p) v+=n1-(v>p);
    }
    vector<vector<int>>G(n+1,vector<int>{});
    for(auto [u,v]:edge1)
    {
        assert(1<=u&&u<=n);
        assert(1<=v&&v<=n);
        assert(u!=v);
        G[u].emplace_back(v),G[v].emplace_back(u);
    }
    for(auto [u,v]:edge2)
    {
        assert(1<=u&&u<=n);
        assert(1<=v&&v<=n);
        assert(u!=v);
        G[u].emplace_back(v),G[v].emplace_back(u);
    }
    return get_fa(n,G,1);
}
void gen(string file,int n,const vector<vector<int>> &p)
{
    static ofstream ouf;
    ouf.open(file+".in");
    ouf<<p.size()<<"\n";
    for(int k=0;k<(int)p.size();k++)
    {
        ouf<<n<<"\n";
        for(int i=2;i<=n;i++)
        {
            int u=i,v=p[k][i];
            if(DataMaker::rand(0,1)) swap(u,v);
            ouf<<u<<" "<<v<<"\n";
        }
    }
    ouf.close();
    system(("std < "+file+".in > "+file+".out").c_str());
    system(("wfr "+file+".in -r:\"\\r\\n\" -t:\"\\n\"").c_str());
    system(("wfr "+file+".out -r:\"\\r\\n\" -t:\"\\n\"").c_str());
    return;
}
int main()
{
    string pre="tree";
    {
        int n;

        for(char id='1';id<='2';id++)
        {
            string t=pre;
            t+=id;
            n=DataMaker::rand(7,10);
            gen(t,n,{gen_tree(n),gen_strong(n),gen_chain(n),gen_chrysanthemum(n),gen_complete(n)});
        }
    }
    {
        int n;

        for(char id='3';id<='6';id++)
        {
            string t=pre;
            t+=id;
            n=DataMaker::rand(2000-100,2000);
            gen(t,n,{gen_tree(n),gen_strong(n),gen_chain(n),gen_chrysanthemum(n),gen_complete(n)});
        }
    }
    {
        int n;

        for(char id='7';id<='9';id++)
        {
            string t=pre;
            t+=id;
            n=DataMaker::rand(100000-5000,100000);
            gen(t,n,{gen_chain(n),gen_chain(n),gen_chain(n),gen_chain(n),gen_chain(n)});
        }
        for(string id:{"10"})
        {
            string t=pre;
            t+=id;
            n=DataMaker::rand(100000-5000,100000);
            gen(t,n,{gen_chain(n),gen_chain(n),gen_chain(n),gen_chain(n),gen_chain(n)});
        }
    }
    {
        int n;

        for(string id:{"11","12"})
        {
            string t=pre;
            t+=id;
            n=DataMaker::rand(100000-5000,100000);
            gen(t,n,{gen_chrysanthemum(n),gen_chrysanthemum(n),gen_chrysanthemum(n),gen_chrysanthemum(n),gen_chrysanthemum(n)});
        }
    }
    {
        int n;

        for(string id:{"13","14"})
        {
            string t=pre;
            t+=id;
            n=DataMaker::rand(100000-5000,100000);
            gen(t,n,{gen_complete(n),gen_complete(n),gen_complete(n),gen_complete(n),gen_complete(n)});
        }
    }
    {
        int n;

        for(string id:{"15","16","17","18","19","20"})
        {
            string t=pre;
            t+=id;
            n=DataMaker::rand(100000-5000,100000);
            gen(t,n,{gen_tree(n),gen_strong(n),gen_chain(n),gen_chrysanthemum(n),gen_complete(n)});
        }
    }
    return 0;
}
