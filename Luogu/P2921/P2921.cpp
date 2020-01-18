#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int n,tot;
int to[100005];
struct Edge
{
    int to,next;
}edge[100005];
int head[100005],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
int dfn[100005],low[100005],Index;
bool book[100005];
int num[100005],belong[100005],ans[100005];
stack<int>s;
void tarjan(int u)
{
	dfn[u]=low[u]=++Index;
    book[u]=true;
    s.push(u);
    int v=to[u];
	if(!dfn[v])
    {
        tarjan(v);
        low[u]=min(low[u],low[v]);
    }
	else if(book[v]) low[u]=min(low[u],dfn[v]);
	if(low[u]==dfn[u])
	{
		tot++;
        while(s.top()!=u)
        {
            belong[s.top()]=tot;
            num[tot]++;
            book[s.top()]=false;
            s.pop();
        }
        belong[u]=tot;
        num[tot]++;
        book[u]=false;
        s.pop();
	}
    return;
}
int dfs(int u)
{
	if(ans[u]) return ans[u];
	ans[u]=num[u];
	if(num[u]==1)
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            ans[u]+=dfs(v);
        }
    return ans[u];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	    scanf("%d",&to[i]);
	for(int i=1;i<=n;i++)
	    if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++)
    	if(belong[i]!=belong[to[i]]) add_edge(belong[i],belong[to[i]]); 
	for(int i=1;i<=n;i++)
	    printf("%d\n",dfs(belong[i]));
	return 0;
}
