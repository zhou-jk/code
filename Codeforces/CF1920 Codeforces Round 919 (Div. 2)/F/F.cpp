#include<iostream>
#include<cstdio>
#include<queue>
#include<array>
#include<tuple>
#include<numeric>
#include<functional>
#include<algorithm>
using namespace std;
int n,m,q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>q;
    vector<string>s(n);
    for(int i=0;i<n;i++)
        cin>>s[i];
    queue<pair<int,int>>que;
    vector<vector<int>>dis(n,vector<int>(m,-1));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=='v') que.emplace(i,j),dis[i][j]=0;
    while(!que.empty())
    {
        auto [ux,uy]=que.front();
        que.pop();
        for(auto [dx,dy]:vector<pair<int,int>>{{1,0},{-1,0},{0,1},{0,-1}})
        {
            int tx=ux+dx,ty=uy+dy;
            if(tx<0||tx>=n||ty<0||ty>=m) continue;
            if(dis[tx][ty]!=-1) continue;
            dis[tx][ty]=dis[ux][uy]+1;
            que.emplace(tx,ty);
        }
    }
    int limx=n,limy=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=='#')
            {
                if(i<limx) limx=i,limy=j;
                else if(i==limx&&j>limy) limy=j;
            }
    vector<vector<array<int,2>>>id(n,vector<array<int,2>>(m));
    int tot=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            id[i][j][0]=tot++,id[i][j][1]=tot++;
    vector<tuple<int,int,int>>edge;
    for(int ux=0;ux<n;ux++)
        for(int uy=0;uy<m;uy++)
            if(s[ux][uy]!='#')
            {
                for(auto [tx,ty]:vector<pair<int,int>>{{ux,uy-1},{ux-1,uy}})
                {
                    if(tx<0||tx>=n||ty<0||ty>=m) continue;
                    if(s[tx][ty]=='#') continue;
                    int w=min(dis[ux][uy],dis[tx][ty]);
                    if(ux==limx&&uy>limy&&tx==ux-1&&ty>limy)
                    {
                        edge.emplace_back(id[ux][uy][0],id[tx][ty][1],w);
                        edge.emplace_back(id[ux][uy][1],id[tx][ty][0],w);
                    }
                    else
                    {
                        edge.emplace_back(id[ux][uy][0],id[tx][ty][0],w);
                        edge.emplace_back(id[ux][uy][1],id[tx][ty][1],w);
                    }
                }
            }
    sort(edge.begin(),edge.end(),[=](const tuple<int,int,int> &x,const tuple<int,int,int> &y){return get<2>(x)>get<2>(y);});
    int cnt=tot;
    vector<int>fa(tot+tot-1);
    iota(fa.begin(),fa.end(),0);
    function<int(int)>getf=[&](int v)->int
    {
        if(v==fa[v]) return v;
        else return fa[v]=getf(fa[v]);
    };
    vector<vector<int>>G(tot+tot-1);
    vector<int>a(tot+tot-1);
    for(auto [u,v,w]:edge)
    {
        int fu=getf(u),fv=getf(v);
        if(fu==fv) continue;
        fa[fu]=fa[fv]=fa[cnt]=cnt;
        a[cnt]=w;
        G[cnt].emplace_back(fu);
        G[cnt].emplace_back(fv);
        cnt++;
    }
    vector<vector<int>>mn(cnt,vector<int>(__lg(cnt)+1));
    vector<int>dfn(cnt,-1);
    int Index=0;
    function<void(int,int)>dfs=[&](int u,int father)
    {
        dfn[u]=Index++;
        mn[dfn[u]][0]=father;
        for(int v:G[u])
            dfs(v,u);
        return;
    };
    for(int i=cnt-1;i>=0;i--)
        if(dfn[i]==-1) dfs(i,-1);
    for(int j=1;(1<<j)<=cnt;j++)
        for(int i=0;i+(1<<j)-1<cnt;i++)
        {
            if(mn[i][j-1]==-1||(mn[i+(1<<(j-1))][j-1]!=-1&&dfn[mn[i][j-1]]<dfn[mn[i+(1<<(j-1))][j-1]])) mn[i][j]=mn[i][j - 1];
            else mn[i][j]=mn[i+(1<<(j-1))][j-1];
        }
    auto lca=[=](int u,int v)->int
    {
        if(u==v) return u;
        u=dfn[u],v=dfn[v];
        if(u>v) swap(u,v);
        u++;
        int d=__lg(v-u+1);
        if(mn[u][d]==-1||(mn[v-(1<<d)+1][d]!=-1&&dfn[mn[u][d]]<dfn[mn[v-(1<<d)+1][d]])) return mn[u][d];
        else return mn[v-(1<<d)+1][d];
    };
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        int ans=a[lca(id[x][y][0],id[x][y][1])];
        cout<<ans<<"\n";
    }
    return 0;
}