#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
    char ch;
    int ret=0;
    bool flag=true;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') flag=false;
    while(ch>='0'&&ch<='9')
        ret=(ret<<1)+(ret<<3)+(ch^48),ch=getchar();
    return flag?ret:-ret;
}
const int N=100001;
int n,m;
bool vis[N];
long long dis[N];
struct Edge
{
    int to,val,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void dfs(int u)
{
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!vis[v]) 
        {
            dis[v]=dis[u]^edge[i].val;
            vis[v]=true;
            dfs(v);
        }
        // else S.insert(dis[v]^dis[u]^edge[i].val);
    }
}
int main()
{
    n=read();m=read();
    for (int i=1;i<=m;++i)
    {
        int x=read(),y=read(),z=read();
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    dfs(1);
    printf("%lld\n",dis[n]);
    return 0;
}