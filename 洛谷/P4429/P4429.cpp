#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int N=10001;
struct Edge
{
    int to,next;
}edge[N<<1];
int T,n,m;
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int color[N];
bool dfs(int u)
{
    if(!color[u]) color[u]=2;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!color[v])
        {
            color[v]=color[u]^1;
            if(!dfs(v)) return false;
        }
        else if(color[v]==color[u]) return false;
    }
    return true;
}
int dfn[N],low[N],Index;
int Ecnt,num,Ncnt,tot;
int book[N],tims;
int in[N];
vector<int> block[N];
stack<int>s;
void tarjan(int u)
{
    dfn[u]=low[u]=++Index;
    s.push(u);
    Ncnt++;
    for(int i=head[u];i;i=edge[i].next)
    {
        Ecnt++;
        int v=edge[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u])
            {
                int sum=1;
                tot++;
                block[tot].clear();
                while(s.top()!=v)
                {
                    sum++;
                    block[tot].push_back(s.top());
                    s.pop();
                }
                s.pop();
                block[tot].push_back(v);
                block[tot].push_back(u);
                if(sum>=4) num++;
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
    return;
}
vector<int>path;
void dfs_path(int u,int father,int ed,int dep) 
{
    if(u==ed)
    {
        path.push_back(dep);
        return;
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(book[v]!=tims) continue;
        if(v==father) continue;
        dfs_path(v,u,ed,dep+1);
    }
    return;
}
void solve()
{
    memset(head,0,sizeof(head));
    memset(color,0,sizeof(color));
    memset(book,0,sizeof(book));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    cnt=tims=Index=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=n;i++)
        if(!color[i]&&!dfs(i))
        {
            printf("NO\n");
            return;
        }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
        {
            while(!s.empty()) s.pop();
            num=Ecnt=Ncnt=tot=0;
            tarjan(i);
            Ecnt/=2;
            if(Ecnt<=Ncnt) continue;
            if(Ecnt>=Ncnt+2||num>=2)
            {
                printf("NO\n");
                return;
            }
            tims++;
            int st,ed;
            for(int j=1;j<=tot;j++)
                if(block[j].size()>=4)
                {
                    for(auto u:block[j])
                        book[u]=tims,in[u]=0;
                    for(auto u:block[j])
                        for(int h=head[u];h;h=edge[h].next)
                        {
                            int v=edge[h].to;
                            if(book[v]==tims) in[u]++;
                        }
                    st=ed=0;
                    for(auto u:block[j])
                        if(in[u]==3)
                        {
                            if(!st) st=u;
                            else if(!ed) ed=u; 
                        }
                    break;
                }
            path.clear();
            dfs_path(st,0,ed,0);
            sort(path.begin(),path.end());
            if(path[0]!=2||path[1]!=2)
            {
                printf("NO\n");
                return;
            }
        }
    printf("YES\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}