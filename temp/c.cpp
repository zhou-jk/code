#include<bits/stdc++.h>
using namespace std;
constexpr int N=2000005;
int n,m;
int out[N],in[N];
vector<int>G[N],E[N];
vector<int>posin,posout,posinout;
bool vis[N];
vector<pair<int,int>>edge;
int cnt;
void dfs(int u)
{
//    cerr<<"now"<<u<<"\n";
    for(int v:G[u])
    {
//        cerr<<"find"<<u<<" "<<v<<" "<<vis[v]<<"\n";
        if(!vis[v])
        {
            int ret=cnt;
            vector<int>pos;
            for(int w:E[v])
            {
                if(!vis[w])
                {
                    ret--;
                }
            }
            if(ret==0) return;
            for(int w:E[v])
            {
                if(!vis[w])
                {
                    vis[w]=true;
//                    cerr<<"flag"<<w<<"\n";
                    cnt--;
                }
            }
            vis[v]=true;
            while(!posin.empty()&&vis[posin.back()]) posin.pop_back();
            assert(!posin.empty());
            int w=posin.back();
//            cerr<<"to"<<v<<" "<<w<<"\n";
            vis[w]=true;
            cnt--;
            edge.emplace_back(v,w);
            in[w]++,out[v]++;
            dfs(w);
        }
    }
    return;
}
bool book[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n*2;i++)
        out[i]=in[i]=0,G[i].clear(),E[i].clear(),vis[i]=false;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].emplace_back(v);
        E[v].emplace_back(u);
        out[u]++,in[v]++;
    }
    int p=0,q=0;
    posin.clear(),posout.clear(),posinout.clear();
    for(int i=1;i<=n*2;i++)
    {
        if(in[i]==0&&out[i]==0) p++,q++,posinout.emplace_back(i); 
        else if(in[i]==0) posin.emplace_back(i),p++;
        else if(out[i]==0) posout.emplace_back(i),q++;
    }
    cnt=posin.size();
    edge.clear();
    for(int u=1;u<=n;u++)
        if(!vis[u]&&in[u]==0&&out[u]>0)
        {
//            cerr<<"Try"<<u<<"\n";
            dfs(u);
        }
    posin.clear(),posout.clear(),posinout.clear();
    for(int i=1;i<=n*2;i++)
    {
        if(in[i]==0&&out[i]==0) posinout.emplace_back(i); 
        else if(in[i]==0) posin.emplace_back(i);
        else if(out[i]==0) posout.emplace_back(i);
    }
    while(!posin.empty()&&!posinout.empty())
    {
        while(!posinout.empty()&&(in[posinout.back()]||out[posinout.back()])) posinout.pop_back();
        if(posinout.empty()) break;
        while(!posin.empty()&&in[posin.back()]) posin.pop_back();
        if(posin.empty()) break;
        int u=posinout.back(),v=posin.back();
        posinout.pop_back();
        posin.pop_back();
        edge.emplace_back(u,v);
        out[u]++,in[v]++;
        posin.push_back(u);
    }
    while(!posinout.empty()&&!posout.empty())
    {
        while(!posinout.empty()&&(in[posinout.back()]||out[posinout.back()])) posinout.pop_back();
        if(posinout.empty()) break;
        while(!posout.empty()&&out[posout.back()]) posout.pop_back();
        if(posout.empty()) break;
        int u=posout.back(),v=posinout.back();
        posout.pop_back();
        posinout.pop_back();
        edge.emplace_back(u,v);
        out[u]++,in[v]++;
        posout.push_back(u);
    }
//    cerr<<"ed"<<edge.size()<<"\n";
//    cerr<<"out"<<in[3]<<" "<<posin.size()<<"\n";
    while(!posin.empty()&&!posout.empty())
    {
        while(!posin.empty()&&in[posin.back()]) posin.pop_back();
        if(posin.empty()) break;
        while(!posout.empty()&&out[posout.back()]) posout.pop_back();
        if(posout.empty()) break;
        int u=posout.back(),v=posin.back();
        posout.pop_back();
        posin.pop_back();
        edge.emplace_back(u,v);
        out[u]++,in[v]++;
    }
    while(!posin.empty())
    {
        while(!posin.empty()&&in[posin.back()]) posin.pop_back();
        if(posin.empty()) break;
        int u=1,v=posin.back();
        posin.pop_back();
        edge.emplace_back(u,v);
        out[u]++,in[v]++;
//        cerr<<"Add"<<u<<" "<<v<<'\n';
    }
    while(!posout.empty())
    {
        while(!posout.empty()&&out[posout.back()]) posout.pop_back();
        if(posout.empty()) break;
        int u=posout.back(),v=1;
        posout.pop_back();
        edge.emplace_back(u,v);
        out[u]++,in[v]++;
    }
//    cerr<<"sss"<<posin.size()<<" "<<posout.size()<<"\n";
    vector<int>pos;
    fill(book+1,book+n*2+1,false);
    for(int u:posinout)
        if(in[u]==0&&out[u]==0) pos.emplace_back(u),book[u]=true;
    if(!pos.empty())
    {
        int ppp=0;
        for(int i=1;i<=n*2;i++)
            if(!book[i]) ppp=i;
        if(ppp) pos.emplace_back(ppp);
        for(int i=0;i<(int)pos.size();i++)
        {
            int u=pos[i],v=pos[(i+1)%(int)pos.size()];
            edge.emplace_back(u,v);
            out[u]++,in[v]++;
        }
    }
    int k=edge.size();
    assert(k==max(p,q));
//    cerr<<"ans"<<max(p,q)<<"\n"; 
    cout<<k<<"\n";
    for(auto [u,v]:edge)
        cout<<u<<" "<<v<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}

/*
5
4 4
1 5
2 5
3 5
4 5
4 4
1 5
2 6
3 7
4 8
4 0
4 4
1 6
2 5
3 8
4 7

4 2
1 5
2 5

1
5 4
1 7
1 10
3 6
1 8

1
3 4
3 4
1 5
2 5
3 5

3
1 0
1 1
1 2
2 3
1 3
1 4
2 3
*/