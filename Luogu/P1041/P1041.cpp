#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=301;
struct Edge
{
    int to,next;
}edge[N*N*2];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
vector<int>e[N];
int n,m,p,ans,deep;
int size[N],dep[N],fa[N];
bool book[N];
bool find(int v)
{
    if(v==1) return false;
    if(book[v]) return true;
    return find(fa[v]);
}
void init(int u,int father)
{
    fa[u]=father;
    dep[u]=dep[father]+1;
    e[dep[u]].push_back(u);
    deep=max(deep,dep[u]);
    size[u]=1;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        init(v,u);
        size[u]+=size[v];
    }
    return;
}
void dfs(int step,int tot)
{
    if(step==deep+1) return;
    for(int i=0;i<e[step].size();i++)
    {
        int v=e[step][i];
        if(find(v)) continue;
        book[v]=true;
        ans=max(ans,tot+size[v]);
        dfs(step+1,tot+size[v]);
        book[v]=false;
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&p);
    for(int i=1;i<=p;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    init(1,0);
    dfs(2,0);
    printf("%d",n-ans);
    return 0;
}