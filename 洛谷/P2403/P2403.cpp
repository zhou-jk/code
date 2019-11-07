#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
const int N=1000001;
int n,r,c;
int ans;
struct Node
{
    int x,y,id,op;
}a[N];
struct Edge
{
    int to,next;
}edge[N<<2],e[N];
bool cmp1(Node a,Node b)
{
    return a.x<b.x;
}
bool cmp2(Node a,Node b)
{
    return a.y<b.y;
}
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int Head[N],Cnt;
void Add_edge(int u,int v)
{
	Cnt++;
	e[Cnt].to=v;
	e[Cnt].next=Head[u];
	Head[u]=Cnt;
	return;
}
map<pair<int,int>,int>Hash;
stack<int>s;
int dfn[N],low[N],Index;
bool book[N];
int size[N],belong[N],tot;
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
			size[tot]++;
			book[s.top()]=false;
			s.pop();
		}
		belong[u]=tot;
		size[tot]++;
		book[u]=false;
		s.pop();
	}
	return;
}
bool vis[N];
void dfs(int u)
{
	vis[u]=true;
	int res=0;
	for(int i=Head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(!vis[v]) dfs(v);
		res=max(res,size[v]);
	}
	size[u]+=res;
	ans=max(ans,size[u]);
	return;
}
int main()
{
    scanf("%d%d%d",&n,&r,&c);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].op);
        Hash[make_pair(a[i].x,a[i].y)]=i;
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp1);
    for(int i=1;i<=n;i++)
        if(a[i].op==1)
        {
            for(int j=i-1;j>=1;j--)
                if(a[i].x==a[j].x) add_edge(a[i].id,a[j].id);
                else break;
            for(int j=i+1;j<=n;j++)
                if(a[i].x==a[j].x) add_edge(a[i].id,a[j].id);
                else break;
        }
    sort(a+1,a+n+1,cmp2);
    for(int i=1;i<=n;i++)
        if(a[i].op==2)
        {
            for(int j=i-1;j>=1;j--)
                if(a[i].y==a[j].y) add_edge(a[i].id,a[j].id);
                    else break;
            for(int j=i+1;j<=n;j++)
                if(a[i].y==a[j].y) add_edge(a[i].id,a[j].id);
                    else break;
        }
    for(int i=1;i<=n;i++)
        if(a[i].op==3)
        {
            for(int j=a[i].x-1;j<=a[i].x+1;j++)
                for(int k=a[i].y-1;k<=a[i].y+1;k++)
                    if(j!=a[i].x||k!=a[i].y)
						if(Hash[make_pair(j,k)]) add_edge(a[i].id,Hash[make_pair(j,k)]);
        }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    for(int u=1;u<=n;u++)
    	for(int i=head[u];i;i=edge[i].next)
    	{
    		int v=edge[i].to;
    		if(belong[u]!=belong[v]) Add_edge(belong[u],belong[v]);
		}
    for(int i=1;i<=tot;i++)
        if(!vis[i]) dfs(i);
    printf("%d",ans);
    return 0;
}