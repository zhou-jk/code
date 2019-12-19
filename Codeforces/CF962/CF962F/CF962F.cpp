#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100001;
int n,m;
struct Edge
{
    int to,next;
}edge[N<<1];
int head[N],cnt=1;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int low[N],dfn[N],Index;
int st[N*3],top;
int block[N],tot;
vector<int>e[N],ans,node[N];
void tarjan(int u,int father)
{
	dfn[u]=low[u]=++Index;
	for(int i=head[u];i;i=edge[i].next)
    {
		int v=edge[i].to;
        if(v==father) continue;
		if(!dfn[v])
        {
			st[++top]=i>>1,st[++top]=u,st[++top]=v;
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])
            { 
				tot++;
				while(1)
                {
					int t1=st[top--],t2=st[top--];
					if(block[t1]!=tot)
                    {
						node[tot].push_back(t1);
						block[t1]=tot;
					}
					if(block[t2]!=tot)
                    {
						node[tot].push_back(t2); 
						block[t2]=tot;
					}
					e[tot].push_back(st[top--]);
					if(t1==v&&t2==u) break;
				}
			}	
		}
		else if(dfn[v]<dfn[u])
        { 
			st[++top]=i>>1,st[++top]=u,st[++top]=v;
			low[u]=min(low[u],dfn[v]);
		}
	}
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
    {
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
        add_edge(y,x);
	}
	for(int i=1;i<=n;i++) 
		if(!dfn[i]) tarjan(i,0);
	for(int i=1;i<=tot;i++)
    	if(e[i].size()==node[i].size())
            for(auto u:e[i])
                ans.push_back(u);
	sort(ans.begin(),ans.end());
  	printf("%u\n",ans.size());
    for(auto u:ans)
        printf("%d ",u);
    return 0;
}