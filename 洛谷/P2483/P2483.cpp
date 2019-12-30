#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int M=51;
int n,m,k,S,T;
bool used[M];
int pre[M];
map<vector<int>,bool>Hash;
struct Node
{
    int vote,id;
    vector<int> rd,d;
    bool operator<(const Node &b)const
    {
        if(vote!=b.vote) return vote>b.vote;
        for(int j=0;j<min(rd.size(),b.rd.size());j++)
            if(rd[j]!=b.rd[j]) return rd[j]>b.rd[j];
        if(rd.size()!=b.rd.size()) return rd.size()<b.rd.size();
        else return id>b.id;
    }
}t;
bool operator <(vector<int> a,vector<int> b)
{
    for(int i=0;i<min(a.size(),b.size());i++)
        if(a[i]!=b[i]) return a[i]>b[i];
    return a.size()>=b.size();
}
priority_queue<Node> Q;
struct Edge
{
    int to,val,next;
}edge[M*M*2];
int head[M],cnt;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int dis[M];
void dijkstra(int S)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
    memset(dis,63,sizeof(dis));
    dis[S]=0;
    q.push(make_pair(0,S));
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(used[v]) continue;
            if(dis[v]>dis[u]+edge[i].val)
            {
                dis[v]=dis[u]+edge[i].val;
                pre[v]=u;
                q.push(make_pair(dis[v],v));
            }
            else if(dis[v]==dis[u]+edge[i].val&&pre[v]>u)
            {
                pre[v]=u;
                q.push(make_pair(dis[v],v));
            }
        }
    }
    return;
}
vector<int> res[M<<2];
vector<pair<int,int> >e[M];
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&k,&S,&T);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(y,x,z);
        e[x].push_back(make_pair(y,z));
    }
    dijkstra(T);
    int tot=0;
    t.id=0;
    t.vote=dis[S];
    t.rd.push_back(S);
    t.d.push_back(0);
    for(int p=S;p!=T;p=pre[p])
    {
        t.rd.push_back(pre[p]);
        tot+=dis[p]-dis[pre[p]];
        t.d.push_back(tot);
    }
    Q.push(t);
    for(int i=1;i<=k;i++)
    {
        if(Q.empty())
        {
            printf("No");
            return 0;
        }
        Node now=Q.top();
        Q.pop();
        res[i].clear();
        for(auto u:now.rd)
            res[i].push_back(u);
        if(Hash.count(res[i]))
        {
            i--;
            continue;
        }
        Hash[res[i]]=true;
        for(int j=now.id;j<now.rd.size()-1;j++)
        {
            memset(used,false,sizeof(used));
            for(int k=0;k<=j;k++)
                used[now.rd[k]]=true;
            dijkstra(T);
            int u=now.rd[j],V=now.rd[j+1];
            int p=0,Min=1e9,W;
            for(auto [v,w]:e[u])
            {
                int val=dis[v]+w+now.d[j];
                if(v==V) continue;
                if(dis[V]+now.d[j+1]<val)
                {
                    if(Min>val) p=v,Min=val,W=w;
                    else if(Min==val&&p>v) p=v,Min=val,W=w;
                }
                else if(dis[V]+now.d[j+1]==val&&V<v)
                {
                    if(Min>val) p=v,Min=val,W=w;
                    else if(Min==val&&p>v) p=v,Min=val,W=w;
                }
            }
            if(!p) continue;
            t.id=j,t.vote=Min,t.rd.clear(),t.d.clear();
            for(int k=0;k<=j;k++)
                t.rd.push_back(now.rd[k]),t.d.push_back(now.d[k]);
            tot=t.d[j]+W;
            t.rd.push_back(p),
            t.d.push_back(tot);
            for(;p!=T;p=pre[p])
            {
                t.rd.push_back(pre[p]);
                tot+=dis[p]-dis[pre[p]];
                t.d.push_back(tot);
            }
            Q.push(t);
        }
    }
    for(int i=0;i<res[k].size()-1;i++)
        printf("%d-",res[k][i]);
    printf("%d",res[k][res[k].size()-1]);
    return 0;
}