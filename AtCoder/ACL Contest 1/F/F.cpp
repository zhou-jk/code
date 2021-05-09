#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
const int N=35;
const int INF=1061109567;
int n;
int a[N*3],b[N*3];
int p[N][2];
vector<int>posa[N],posb[N];
vector<int>G[N*2];
int dfn[N*2],low[N*2],Index;
bool vis[N*2];
int bel[N*2],tot;
stack<int>s;
void dfs(int u)
{
    dfn[u]=low[u]=++Index;
    vis[u]=true;
    s.emplace(u);
    for(int v:G[u])
        if(!dfn[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    if(dfn[u]==low[u])
    {
        tot++;
        while(s.top()!=u)
        {
            bel[s.top()]=tot;
            vis[s.top()]=false;
            s.pop();
        }
        bel[u]=tot;
        vis[u]=false;
        s.pop();
    }
    return;
}
bool circle(int l,int r)
{
    static int type[N];
    vector<pair<int,int>>match;
    for(int i=1;i<=n;i++)
    {
        auto gettype=[=](int p)
        {
            if(p<=l) return "L";
            else if(p>=r) return "R";
            else return "M";
        };
        type[i]=0;
        string Type=(string)gettype(posb[i][0])+gettype(posb[i][1])+gettype(posb[i][2]);
        if(Type=="LLL"||Type=="RRR") return false;
        if(Type=="LLR") type[i]=1;
        if(Type=="LRR") type[i]=2;
        if(Type=="LMR") type[i]=3;
        if(Type=="MMR") match.emplace_back(posa[i][0],posb[i][0]),match.emplace_back(posa[i][2],posb[i][1]);
        if(Type=="LMM") match.emplace_back(posa[i][0],posb[i][1]),match.emplace_back(posa[i][2],posb[i][2]);
        if(Type=="MMM") match.emplace_back(posa[i][0],posb[i][0]),match.emplace_back(posa[i][1],posb[i][1]),match.emplace_back(posa[i][2],posb[i][2]);
        if(Type=="LLM") match.emplace_back(posa[i][2],posb[i][2]);
        if(Type=="MRR") match.emplace_back(posa[i][0],posb[i][0]);
    }
    auto circle=[=](int a,int b){return posb[a][0]<posb[b][0]||posb[a][2]<posb[b][2];};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(type[i]==1&&type[j]==2&&!circle(i,j)) return false;
    for(int i=1;i<=n*2;i++)
        dfn[i]=low[i]=bel[i]=0,vis[i]=false,G[i].clear();
    Index=tot=0;
    sort(match.begin(),match.end());
    for(size_t i=1;i<match.size();i++)
        if(match[i].second<match[i-1].second) return false;
    for(int i=1;i<=n;i++)
    {
        if(type[i]!=3) continue;
        bool f1=false,f2=false;
        auto cross=[=](int a,int b,int c,int d){return (a<c&&b>d)||(a>c&&b<d);};
        for(auto [a,b]:match)
        {
            if(cross(a,b,posa[i][0],posb[i][1])) f2=true;
            if(cross(a,b,posa[i][2],posb[i][1])) f1=true;
        }
        for(int j=1;j<=n;j++)
            if(type[j]==1)
            {
                if(!circle(j,i)) f1=true;
            }
            else if(type[j]==2)
            {
                if(!circle(i,j)) f2=true;
            }
            else if(i<j&&type[j]==3)
            {
                if(!circle(i,j)||cross(posa[i][0],posb[i][1],posa[j][2],posb[j][1])) G[p[i][1]].emplace_back(p[j][1]),G[p[j][0]].emplace_back(p[i][0]);
                if(!circle(j,i)||cross(posa[i][2],posb[i][1],posa[j][0],posb[j][1])) G[p[i][0]].emplace_back(p[j][0]),G[p[j][1]].emplace_back(p[i][1]);
                if(cross(posa[i][0],posb[i][1],posa[j][0],posb[j][1])) G[p[i][1]].emplace_back(p[j][0]),G[p[j][1]].emplace_back(p[i][0]);
                if(cross(posa[i][2],posb[i][1],posa[j][2],posb[j][1])) G[p[i][0]].emplace_back(p[j][1]),G[p[j][0]].emplace_back(p[i][1]);
            }
        if(f1&&f2) return false;
        if(f1) G[p[i][0]].emplace_back(p[i][1]);
        if(f2) G[p[i][1]].emplace_back(p[i][0]);
    }
    for(int i=1;i<=n*2;i++)
        if(!dfn[i]) dfs(i);
    for(int i=1;i<=n;i++)
        if(bel[i]==bel[i+n]) return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=3*n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=3*n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=3*n;i++)
        posa[a[i]].emplace_back(i),posb[b[i]].emplace_back(i);
    for(int i=1;i<=n;i++)
        p[i][0]=i,p[i][1]=i+n;
    int ans=INF;
    for(int i=0;i<=3*n;i++)
        for(int j=i+1;j<=3*n+1;j++)
            if(circle(i,j)) ans=min(ans,i+3*n-j+1);
    if(ans>=INF) printf("-1");
    else printf("%d",ans);
    return 0;
}