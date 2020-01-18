#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
int n,m;
struct Edge
{
    int to,next;
}edge[10001];
int head[101],cnt;
int x[10001],y[10001];
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int dfn[101],low[101],Index;
int belong[101],tot;
bool book[101];
stack<int>s;
void tarjan(int u)
{
    dfn[u]=low[u]=++Index;
    book[u]=true;
    s.push(u);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(book[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        tot++;
        while(s.top()!=u)
        {
            belong[s.top()]=tot;
            book[s.top()]=false;
            s.pop();
        }
        belong[u]=tot;
        book[u]=false;
        s.pop();
    }
    return;
}
struct Node
{
    int u,v;
}e[10001];
int E;
bool cmp(Node x,Node y)
{
    if(x.u==y.u) return x.v<y.v;
    else return x.u<y.u;
}
int in[101],out[101];
int ans1,ans2;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t;
        while(1)
        {
            scanf("%d",&t);
            if(t==0) break;
            m++,x[m]=i,y[m]=t;
            add_edge(x[m],y[m]);
        }
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    for(int i=1;i<=m;i++)
        if(belong[x[i]]!=belong[y[i]]) E++,e[E].u=belong[x[i]],e[E].v=belong[y[i]];
    sort(e+1,e+E+1,cmp);
    for(int i=1;i<=E;i++)
        if(e[i].u!=e[i-1].u||e[i].v!=e[i-1].v) in[e[i].v]++,out[e[i].u]++;
    for(int i=1;i<=tot;i++)
    {
        if(in[i]==0) ans1++;
        if(out[i]==0) ans2++;
    }
    if(tot==1) printf("1\n0");
    else printf("%d\n%d",ans1,max(ans1,ans2));
    return 0;
}