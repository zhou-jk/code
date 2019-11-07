#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=201;
int T,n,m;
struct Edge
{
    int to,next;
}edge[N*N];
int head[N],cnt=1,in[N];
bool book[N*N];
vector<pair<int,int> > res;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void dfs(int u)
{
    for(int i=head[u];i;i=edge[i].next)
    {
        if(book[i]) continue;
        int v=edge[i].to;
        book[i]=book[i^1]=true;
        res.push_back({u,v});
        dfs(v);
    }
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(head,0,sizeof(head));
        memset(in,0,sizeof(in));
        memset(book,false,sizeof(book));
        cnt=1;
        res.clear();
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add_edge(x,y);
            add_edge(y,x);
            in[x]++,in[y]++;
        }
        int ans=n;
        for(int i=1;i<=n;i++)
            if(in[i]&1) add_edge(0,i),add_edge(i,0),ans--;
        for(int i=1;i<=n;i++)
            if(head[i]) dfs(i);
        printf("%d\n",ans);
        for(int i=0;i<res.size();i++)
            if(res[i].first&&res[i].second) printf("%d %d\n",res[i].first,res[i].second);
    }
    return 0;
}