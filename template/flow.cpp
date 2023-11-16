#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct Max_Flow
{
    static const int N=105,M=5005;
    static const long long INF=4557430888798830399;
    struct Edge
    {
        int to,next;
        long long flow;
    }edge[M*2];
    int cur[N],head[N],cnt;
    int tot;
    Max_Flow():cnt(1),tot(0)
    {
        memset(head,0,sizeof(head));
    }
    void add_edge(int u,int v,long long f)
    {
        cnt++;
        edge[cnt].to=v;
        edge[cnt].flow=f;
        edge[cnt].next=head[u];
        head[u]=cnt;
        return;
    }
    void add(int u,int v,long long f)
    {
        add_edge(u,v,f);
        add_edge(v,u,0);
        return;
    }
    int dep[N];
    bool bfs(int s,int t)
    {
        for(int i=1;i<=tot;i++)
            dep[i]=-1;
        queue<int>q;
        q.push(s);
        dep[s]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=head[u];i;i=edge[i].next)
            {
                int v=edge[i].to;
                if(dep[v]!=-1||edge[i].flow<=0) continue;
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
        return dep[t]!=-1;
    }
    long long dfs(int u,int t,long long flow)
    {
        if(u==t||flow==0) return flow;
        long long used=0;
        for(int &i=cur[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dep[v]!=dep[u]+1||edge[i].flow<=0) continue;
            long long now=dfs(v,t,min(flow,(long long)edge[i].flow));
            flow-=now;
            edge[i].flow-=now;
            edge[i^1].flow+=now;
            used+=now;
            if(flow==0) break;
        }
        return used;
    }
    long long dinic(int s,int t)
    {
        long long res=0;
        while(bfs(s,t))
        {
            for(int i=1;i<=tot;i++)
                cur[i]=head[i];
            res+=dfs(s,t,INF);
        }
        return res;
    }
}max_flow;
struct Min_Cost_Max_Flow
{
    static const int N=405,M=15005;
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
struct Min_Cost_Feasible_Flow
{
    static const int N=405,M=15005;
    static const long long INF=4557430888798830399;
    struct Edge
    {
        int to,next;
        int cost;
        long long flow;
    }edge[M*2];
    int cur[N],head[N],cnt;
    int tot;
    Min_Cost_Feasible_Flow():cnt(1),tot(0)
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
    bool vis[N];
    bool spfa(int s,int t)
    {
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
            if(cost<0) break;
            ans+=res.first,cost+=res.second;
        }
        return make_pair(ans,cost);
    }
}min_cost_feasible_flow;
struct Bounded_Feasible_Flow_Without_Source_Sink
{
    static const int N=205,M=10205;
    static const long long INF=4557430888798830399;
    struct Edge
    {
        int to,next;
        long long flow;
    }edge[M*2+N*2];
    int cur[N],head[N],cnt;
    long long extra[N];
    vector<long long>flow;
    int tot;
    Bounded_Feasible_Flow_Without_Source_Sink():cnt(1),tot(0)
    {
        memset(head,0,sizeof(head));
        memset(extra,0,sizeof(extra));
    }
    void add_edge(int u,int v,long long f)
    {
        cnt++;
        edge[cnt].to=v;
        edge[cnt].flow=f;
        edge[cnt].next=head[u];
        head[u]=cnt;
        return;
    }
    void add(int u,int v,long long f)
    {
        add_edge(u,v,f);
        add_edge(v,u,0);
        return;
    }
    void add(int u,int v,long long lower,long long upper)
    {
        add(u,v,upper-lower);
        extra[v]+=lower,extra[u]-=lower;
        flow.emplace_back(lower);
        return;
    }
    int dep[N];
    bool bfs(int s,int t)
    {
        for(int i=1;i<=tot;i++)
            dep[i]=-1;
        queue<int>q;
        q.push(s);
        dep[s]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=head[u];i;i=edge[i].next)
            {
                int v=edge[i].to;
                if(dep[v]!=-1||edge[i].flow<=0) continue;
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
        return dep[t]!=-1;
    }
    long long dfs(int u,int t,long long flow)
    {
        if(u==t||flow==0) return flow;
        long long used=0;
        for(int &i=cur[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dep[v]!=dep[u]+1||edge[i].flow<=0) continue;
            long long now=dfs(v,t,min(flow,(long long)edge[i].flow));
            flow-=now;
            edge[i].flow-=now;
            edge[i^1].flow+=now;
            used+=now;
            if(flow==0) break;
        }
        return used;
    }
    long long dinic(int s,int t)
    {
        long long res=0;
        while(bfs(s,t))
        {
            for(int i=1;i<=tot;i++)
                cur[i]=head[i];
            res+=dfs(s,t,INF);
        }
        return res;
    }
    vector<long long> solve()
    {
        int s=++tot,t=++tot;
        long long sum=0;
        for(int i=1;i<=tot-2;i++)
            if(extra[i]>0)
            {
                sum+=extra[i];
                add(s,i,extra[i]);
            }
            else if(extra[i]<0)
            {
                add(i,t,-extra[i]);
            }
        if(dinic(s,t)!=sum) return {};
        for(int i=0;i<(int)flow.size();i++)
            flow[i]+=edge[i*2+3].flow;
        return flow;
    }
}bounded_feasible_flow_without_source_sink;
struct Bounded_Feasible_Flow_With_Source_Sink
{
    static const int N=205,M=10205;
    static const long long INF=4557430888798830399;
    struct Edge
    {
        int to,next;
        long long flow;
    }edge[M*2+N*2];
    int cur[N],head[N],cnt;
    long long extra[N];
    vector<long long>flow;
    int tot;
    Bounded_Feasible_Flow_With_Source_Sink():cnt(1),tot(0)
    {
        memset(head,0,sizeof(head));
        memset(extra,0,sizeof(extra));
    }
    void add_edge(int u,int v,long long f)
    {
        cnt++;
        edge[cnt].to=v;
        edge[cnt].flow=f;
        edge[cnt].next=head[u];
        head[u]=cnt;
        return;
    }
    void add(int u,int v,long long f)
    {
        add_edge(u,v,f);
        add_edge(v,u,0);
        return;
    }
    void add(int u,int v,long long lower,long long upper)
    {
        add(u,v,upper-lower);
        extra[v]+=lower,extra[u]-=lower;
        flow.emplace_back(lower);
        return;
    }
    int dep[N];
    bool bfs(int s,int t)
    {
        for(int i=1;i<=tot;i++)
            dep[i]=-1;
        queue<int>q;
        q.push(s);
        dep[s]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=head[u];i;i=edge[i].next)
            {
                int v=edge[i].to;
                if(dep[v]!=-1||edge[i].flow<=0) continue;
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
        return dep[t]!=-1;
    }
    long long dfs(int u,int t,long long flow)
    {
        if(u==t||flow==0) return flow;
        long long used=0;
        for(int &i=cur[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dep[v]!=dep[u]+1||edge[i].flow<=0) continue;
            long long now=dfs(v,t,min(flow,(long long)edge[i].flow));
            flow-=now;
            edge[i].flow-=now;
            edge[i^1].flow+=now;
            used+=now;
            if(flow==0) break;
        }
        return used;
    }
    long long dinic(int s,int t)
    {
        long long res=0;
        while(bfs(s,t))
        {
            for(int i=1;i<=tot;i++)
                cur[i]=head[i];
            res+=dfs(s,t,INF);
        }
        return res;
    }
    vector<long long> solve(int S,int T)
    {
        int s=++tot,t=++tot;
        long long sum=0;
        for(int i=1;i<=tot-2;i++)
            if(extra[i]>0)
            {
                sum+=extra[i];
                add(s,i,extra[i]);
            }
            else if(extra[i]<0)
            {
                add(i,t,-extra[i]);
            }
        add(T,S,INF);
        if(dinic(s,t)!=sum) return {};
        for(int i=0;i<(int)flow.size();i++)
            flow[i]+=edge[i*2+3].flow;
        return flow;
    }
}bounded_feasible_flow_with_source_sink;
struct Bounded_Max_Flow_With_Source_Sink
{
    static const int N=205,M=10005;
    static const long long INF=4557430888798830399;
    struct Edge
    {
        int to,next;
        long long flow;
    }edge[M*2+N*2];
    int cur[N],head[N],cnt;
    long long extra[N];
    int tot;
    Bounded_Max_Flow_With_Source_Sink():cnt(1),tot(0)
    {
        memset(head,0,sizeof(head));
        memset(extra,0,sizeof(extra));
    }
    void add_edge(int u,int v,long long f)
    {
        cnt++;
        edge[cnt].to=v;
        edge[cnt].flow=f;
        edge[cnt].next=head[u];
        head[u]=cnt;
        return;
    }
    void add(int u,int v,long long f)
    {
        add_edge(u,v,f);
        add_edge(v,u,0);
        return;
    }
    void add(int u,int v,long long lower,long long upper)
    {
        add(u,v,upper-lower);
        extra[v]+=lower,extra[u]-=lower;
        return;
    }
    int dep[N];
    bool bfs(int s,int t)
    {
        for(int i=1;i<=tot;i++)
            dep[i]=-1;
        queue<int>q;
        q.push(s);
        dep[s]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=head[u];i;i=edge[i].next)
            {
                int v=edge[i].to;
                if(dep[v]!=-1||edge[i].flow<=0) continue;
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
        return dep[t]!=-1;
    }
    long long dfs(int u,int t,long long flow)
    {
        if(u==t||flow==0) return flow;
        long long used=0;
        for(int &i=cur[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dep[v]!=dep[u]+1||edge[i].flow<=0) continue;
            long long now=dfs(v,t,min(flow,(long long)edge[i].flow));
            flow-=now;
            edge[i].flow-=now;
            edge[i^1].flow+=now;
            used+=now;
            if(flow==0) break;
        }
        return used;
    }
    long long dinic(int s,int t)
    {
        long long res=0;
        while(bfs(s,t))
        {
            for(int i=1;i<=tot;i++)
                cur[i]=head[i];
            res+=dfs(s,t,INF);
        }
        return res;
    }
    long long solve(int S,int T)
    {
        int s=++tot,t=++tot;
        long long sum=0;
        for(int i=1;i<=tot-2;i++)
            if(extra[i]>0)
            {
                sum+=extra[i];
                add(s,i,extra[i]);
            }
            else if(extra[i]<0)
            {
                add(i,t,-extra[i]);
            }
        add(T,S,INF);
        if(dinic(s,t)!=sum) return -1;
        return dinic(S,T);
    }
}bounded_max_flow_with_source_sink;
struct Bounded_Min_Flow_With_Source_Sink
{
    static const int N=50010,M=125010;
    static const long long INF=4557430888798830399;
    struct Edge
    {
        int to,next;
        long long flow;
    }edge[M*2+N*2];
    int cur[N],head[N],cnt;
    long long extra[N];
    int tot;
    Bounded_Min_Flow_With_Source_Sink():cnt(1),tot(0)
    {
        memset(head,0,sizeof(head));
        memset(extra,0,sizeof(extra));
    }
    void add_edge(int u,int v,long long f)
    {
        cnt++;
        edge[cnt].to=v;
        edge[cnt].flow=f;
        edge[cnt].next=head[u];
        head[u]=cnt;
        return;
    }
    void add(int u,int v,long long f)
    {
        add_edge(u,v,f);
        add_edge(v,u,0);
        return;
    }
    void add(int u,int v,long long lower,long long upper)
    {
        add(u,v,upper-lower);
        extra[v]+=lower,extra[u]-=lower;
        return;
    }
    int dep[N];
    bool bfs(int s,int t)
    {
        for(int i=1;i<=tot;i++)
            dep[i]=-1;
        queue<int>q;
        q.push(s);
        dep[s]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=head[u];i;i=edge[i].next)
            {
                int v=edge[i].to;
                if(dep[v]!=-1||edge[i].flow<=0) continue;
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
        return dep[t]!=-1;
    }
    long long dfs(int u,int t,long long flow)
    {
        if(u==t||flow==0) return flow;
        long long used=0;
        for(int &i=cur[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dep[v]!=dep[u]+1||edge[i].flow<=0) continue;
            long long now=dfs(v,t,min(flow,(long long)edge[i].flow));
            flow-=now;
            edge[i].flow-=now;
            edge[i^1].flow+=now;
            used+=now;
            if(flow==0) break;
        }
        return used;
    }
    long long dinic(int s,int t)
    {
        long long res=0;
        while(bfs(s,t))
        {
            for(int i=1;i<=tot;i++)
                cur[i]=head[i];
            res+=dfs(s,t,INF);
        }
        return res;
    }
    long long solve(int S,int T)
    {
        int s=++tot,t=++tot;
        long long sum=0;
        for(int i=1;i<=tot-2;i++)
            if(extra[i]>0)
            {
                sum+=extra[i];
                add(s,i,extra[i]);
            }
            else if(extra[i]<0)
            {
                add(i,t,-extra[i]);
            }
        add(T,S,INF);
        if(dinic(s,t)!=sum) return -1;
        long long res=edge[cnt].flow;
        edge[cnt].flow=edge[cnt^1].flow=0;
        return res-dinic(T,S);
    }
}bounded_min_flow_with_source_sink;
struct Bounded_Min_Cost_Feasible_Flow_With_Source_Sink
{
    static const int N=305,M=5305;
    static const long long INF=4557430888798830399;
    struct Edge
    {
        int to,next;
        int cost;
        long long flow;
    }edge[M*2+N*2];
    int cur[N],head[N],cnt;
    long long extra[N];
    int tot;
    long long totalcost;
    Bounded_Min_Cost_Feasible_Flow_With_Source_Sink():cnt(1),tot(0),totalcost(0)
    {
        memset(head,0,sizeof(head));
        memset(extra,0,sizeof(extra));
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
    void add(int u,int v,int c,long long lower,long long upper)
    {
        totalcost+=lower*c;
        add(u,v,c,upper-lower);
        extra[v]+=lower,extra[u]-=lower;
        return;
    }
    long long dis[N];
    bool vis[N];
    bool spfa(int s,int t)
    {
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
    pair<long long,long long> solve(int S,int T)
    {
        int s=++tot,t=++tot;
        long long sum=0;
        for(int i=1;i<=tot-2;i++)
            if(extra[i]>0)
            {
                sum+=extra[i];
                add(s,i,0,extra[i]);
            }
            else if(extra[i]<0)
            {
                add(i,t,0,-extra[i]);
            }
        add(T,S,0,INF);
        pair<long long,long long>res=ssp(s,t);
        if(res.first!=sum) return make_pair(-1,-1);
        totalcost+=res.second;
        return make_pair(res.first,totalcost);
    }
}bounded_min_cost_feasible_flow_with_source_sink;
const long long INF=Bounded_Min_Cost_Feasible_Flow_With_Source_Sink::INF;
int main()
{
    int n;
    scanf("%d",&n);
    bounded_min_cost_feasible_flow_with_source_sink.tot=n+1;
    int t=n+1;
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            int b,v;
            scanf("%d%d",&b,&v);
            bounded_min_cost_feasible_flow_with_source_sink.add(i,b,v,1,INF);
        }
        bounded_min_cost_feasible_flow_with_source_sink.add(i,t,0,0,INF);
    }
    long long ans=bounded_min_cost_feasible_flow_with_source_sink.solve(1,t).second;
    printf("%lld",ans);
    return 0;
}
