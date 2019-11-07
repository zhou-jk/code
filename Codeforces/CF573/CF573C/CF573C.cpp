#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n;
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
int num[N],sum[N][6];
inline int calc(int u)
{
	if(sum[u][5]||sum[u][4]||sum[u][3]>2) return 5;
	else if(sum[u][3]>1) return 4;
	else if(sum[u][3]||sum[u][2]||sum[u][1]>2) return 3;
	else if(sum[u][1]>1) return 2;
	else return 1;
}
void init(int u,int father)
{
	for (int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==father) continue;
		init(v,u);
		sum[u][num[v]]++;
	}
	num[u]=calc(u);
	return;
}
void dfs(int u,int father,int x)
{
	sum[u][x]++;
	if (calc(u)<5)
    {
        printf("Yes");
        exit(0);
		return;
	}
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==father) continue;
		sum[u][num[v]]--;
		dfs(v,u,calc(u));
		sum[u][num[v]]++;
	}
	sum[u][x]--;
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
    dfs(1,0,0);
    printf("No");
    return 0;
}