#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int n1,m1,n2,m2;
struct Union_Set
{
    int fa[N];
    void init(int n)
    {
        for(int i=0;i<=n;i++)
            fa[i]=i;
        return;
    }
    int getf(int v)
    {
        if(v==fa[v]) return v;
        else return fa[v]=getf(fa[v]);
    }
    bool merge(int u,int v)
    {
        int f1=getf(u),f2=getf(v);
        if(f1!=f2)
        {
            fa[f2]=f1;
            return true;
        }
        else return false;
    }
}f1,f2;
struct Edge
{
    int u,v,w,id;
};
vector<Edge>edge;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n1>>m1>>n2>>m2;
    for(int i=1;i<=m1;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u++,v++;
        edge.emplace_back((Edge){u,v,w,1});
    }
    for(int i=1;i<=m2;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u++,v++;
        edge.emplace_back((Edge){u,v,w,2});
    }
    sort(edge.begin(),edge.end(),[](const Edge &a,const Edge &b){return a.w<b.w;});
    f1.init(n1),f2.init(n2);
    int c1=n1,c2=n2;
    long long ans=0;
    for(auto [u,v,w,id]:edge)
    {
        if(id==1)
        {
            if(f1.merge(u,v)) ans+=(long long)w*c2,c1--;
        }
        else if(id==2)
        {
            if(f2.merge(u,v)) ans+=(long long)w*c1,c2--;
        }
    }
    cout<<ans;
    return 0;
}