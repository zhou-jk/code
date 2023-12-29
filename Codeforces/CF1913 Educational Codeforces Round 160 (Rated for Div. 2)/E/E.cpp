#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=55;
int n,m;
int a[N][N];
int r[N],c[N];
struct Min_Cost_Max_Flow
{
    static const int N=105,M=2605;
    static const long long INF=4557430888798830399;
    struct Edge
    {
        int to,next;
        int cost;
        long long flow;
    }edge[M*2];
    int cur[N],head[N],cnt;
    int tot;
    Min_Cost_Max_Flow():cnt(1),tot(0)
    {
        memset(head,0,sizeof(head));
    }
    void add_edge(int u,int v,int c,long long f)
    {
        cnt++;
        edge[cnt].to=v;
        edge[cnt].cost=c;
        edge[cnt].flow=f;
        edge[cnt].next=head[u];
        head[u]=cnt;
        return;
    }
    void add(int u,int v,int c,long long f)
    {
        add_edge(u,v,c,f);
        add_edge(v,u,-c,0);
        return;
    }
    long long dis[N];
    bool spfa(int s,int t)
    {
        static bool vis[N];
        for(int i=1;i<=tot;i++)
            vis[i]=false;
        for(int i=1;i<=tot;i++)
            dis[i]=INF;
        queue<int>q;
        vis[s]=true;
        dis[s]=0;
        q.push(s);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            vis[u]=false;
            for(int i=head[u];i;i=edge[i].next)
            {
                int v=edge[i].to;
                if(edge[i].flow<=0) continue;
                if(dis[v]>dis[u]+edge[i].cost)
                {
                    dis[v]=dis[u]+edge[i].cost;
                    if(!vis[v])
                    {
                        vis[v]=true;
                        q.push(v);
                    }
                }
            }
        }
        return dis[t]!=INF;
    }
    bool book[N];
    pair<long long,long long> dfs(int u,int t,long long flow)
    {
        if(u==t||flow==0) return make_pair(flow,0);
        book[u]=true;
        long long used=0,res=0;
        for(int &i=cur[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(book[v]||dis[v]!=dis[u]+edge[i].cost||edge[i].flow<=0) continue;
            pair<long long,long long>val=dfs(v,t,min(flow,edge[i].flow));
            long long now=val.first;
            res+=val.second+now*edge[i].cost;
            flow-=now;
            edge[i].flow-=now;
            edge[i^1].flow+=now;
            used+=now;
            if(flow==0) break;
        }
        book[u]=false;
        return make_pair(used,res);
    }
    pair<long long,long long> ssp(int s,int t)
    {
        long long ans=0,cost=0;
        for(int i=1;i<=tot;i++)
            book[i]=false;
        while(spfa(s,t))
        {
            for(int i=1;i<=tot;i++)
                cur[i]=head[i];
            pair<long long,long long> res=dfs(s,t,INF);
            ans+=res.first,cost+=res.second;
        }
        return make_pair(ans,cost);
    }
}min_cost_max_flow;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        cin>>r[i];
    for(int i=1;i<=m;i++)
        cin>>c[i];
    int sr=0,sc=0;
    for(int i=1;i<=n;i++)
        sr+=r[i];
    for(int i=1;i<=m;i++)
        sc+=c[i];
    if(sr!=sc)
    {
        cout<<-1;
        return 0;
    }
    min_cost_max_flow.tot=n+m;
    int s=++min_cost_max_flow.tot,t=++min_cost_max_flow.tot;
    for(int i=1;i<=n;i++)
        min_cost_max_flow.add(s,i,0,r[i]);
    for(int i=1;i<=m;i++)
        min_cost_max_flow.add(n+i,t,0,c[i]);
    int sa=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]==0) min_cost_max_flow.add(i,j+n,n*m+1,1);
            else sa++,min_cost_max_flow.add(i,j+n,n*m-1,1);
    auto [flow,cost]=min_cost_max_flow.ssp(s,t);
    if(flow!=sr)
    {
        cout<<-1;
        return 0;
    }
    cost+=sa;
    cost-=n*m*sr;
    cout<<cost;
    return 0;
}