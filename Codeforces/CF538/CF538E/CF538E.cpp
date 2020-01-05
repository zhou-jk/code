#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
struct Edge
{
	int to,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
	return;
}
int n;
int dpmin[N],dpmax[N];
int size[N],tot;
void dfs(int u,int father)
{
    dpmax[u]=N,dpmin[u]=0;
    int child=0;
    for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==father) continue;
		child++;
        dfs(v,u);
        size[u]+=size[v];
        dpmax[u]=min(dpmax[u],dpmin[v]);
        dpmin[u]+=dpmax[v];
    }
    if(child==0)
    {
    	tot++;
        size[u]=1;
        dpmin[u]=dpmax[u]=1;
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
    dfs(1,0);
    printf("%d %d",tot-dpmax[1]+1,dpmin[1]);
    return 0;
}
