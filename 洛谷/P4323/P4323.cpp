#include<iostream>
#include<cstdio>
#include<cstring>
#include<unordered_map>
using namespace std;
const int N=200001;
const long long MOD=1000000007;
unordered_map<long long,bool>book;
long long Hash[N];
int n;
int in[N],size[N];
int ans=1e9;
struct Edge
{
    int to,next;
}edge[N];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void init(int u,int father)
{
    size[u]=1;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        init(v,u);
        size[u]+=size[v];
        Hash[u]=Hash[u]^(Hash[v]+17);
    }
    Hash[u]+=size[u]*MOD+1;
    return;
}
void dfs1(int u,int father)
{
    book[Hash[u]]=true;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        long long tmp=(Hash[u]-size[u]*MOD-1)^(Hash[v]+17);
        tmp+=(n-size[v])*MOD+1;
        Hash[v]-=size[v]*MOD+1;
        Hash[v]^=tmp+17;
        Hash[v]+=n*MOD+1;
        size[v]=n;
        dfs1(v,u);
    }
    return;
}
void dfs2(int u,int father)
{
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        if(in[v]>1)
        {
            long long tmp=((Hash[u]-size[u]*MOD-1)^(Hash[v]+17))+(size[u]-size[v])*MOD+1;
            Hash[v]-=size[v]*MOD+1;
            Hash[v]^=tmp+17;
            Hash[v]+=size[u]*MOD+1;
            size[v]=size[u];
            dfs2(v,u);
        }
        else if(book.count(((Hash[u]-size[u]*MOD-1)^(Hash[v]+17))+(size[u]-size[v])*MOD+1)) ans=min(ans,v);
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    init(1,0);
    dfs1(1,0);
    cnt=0;
    memset(head,0,sizeof(head));
    memset(Hash,0,sizeof(Hash));
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        in[x]++,in[y]++;
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=n;i++)
        if(in[i]>1)
        {
            init(i,0);
            dfs2(i,0);
            printf("%d",ans);
            return 0;
        }
    return 0;
}