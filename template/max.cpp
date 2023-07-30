#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
const int N=1205,M=120005;
const int INF = 0x3f3f3f3f;
int n,m,s,t;
struct Edge
{
    int to,flow,next;
}edge[M*2];
int head[N],cnt=1;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].flow=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int h[N],e[N],gap[N];
stack<int> B[N];
int level=0;
int push(int u)
{
    bool init = u == s;    // 是否在初始化
    for (int i = head[u]; i; i = edge[i].next) {
        const int &flow = edge[i].to, &w = edge[i].flow;
        if (!w || init == false && h[u] != h[flow] + 1 ||
                h[u] == INF)    // 初始化时不考虑高度差为1
            continue;
        int k = init ? w : min(w, e[u]);
        // 取到剩余容量和超额流的最小值，初始化时可以使源的溢出量为负数。
        if (flow != s && flow != t && !e[flow]) B[h[flow]].push(flow), level = max(level, h[flow]);
        e[u] -= k, e[flow] += k, edge[i].flow -= k, edge[i ^ 1].flow += k;    // push
        if (!e[u]) return 0;    // 如果已经推送完就返回
    }
    return 1;
}

void relabel(int u)
{
    h[u]=INF;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(edge[i].flow==0) continue;
        h[u]=min(h[u],h[v]);
    }
    h[u]++;
    if(h[u]<n)
    {
        B[h[u]].emplace(u);
        level=max(level,h[u]);
        gap[h[u]]++;
    }
    return;
}
bool bfs()
{
    for(int i=1;i<=n;i++)
        h[i]=INF;
    queue<int>q;
    q.push(t);
    h[t]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i^1].flow==0) continue;
            if(h[v]>h[u]+1)
            {
                h[v]=h[u]+1;
                q.emplace(v);
            }
        }
    }
    return h[s]!=INF;
}

// 选出当前高度最大的节点之一, 如果已经没有溢出节点返回 0
int select()
{
    while (B[level].size()==0&&level > -1) level--;
    return level == -1 ? 0 : B[level].top();
}

int hlpp() {                                    // 返回最大流
    if (!bfs()) return 0;    // 图不连通
    memset(gap, 0, sizeof(gap));
    for (int i = 1; i <= n; i++)
        if (h[i] != INF) gap[h[i]]++;    // 初始化 gap
    h[s] = n;
    push(s);    // 初始化预流
    int u;
    while ((u = select())) {
        B[level].pop();
        if (push(u)) {    // 仍然溢出
            if (!--gap[h[u]])
                for (int i = 1; i <= n; i++)
                    if (i != s && i != t && h[i] > h[u] && h[i] < N)
                        h[i] = N;    // 这里重贴成 n+1 的节点都不是溢出节点
            relabel(u);
        }
    }
    return e[t];
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,0);
    }
    int ans=hlpp();
    printf("%d",ans);
    return 0;
}