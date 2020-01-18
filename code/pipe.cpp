#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N=100000,M=200000,LEN=100000;
vector<pair<int,int> > edge1[LEN];
struct Edge
{
	int v,next;
} edge2[M*2];
int head[N],dfn[N],fa[N],node[N],n_edge,cnt,n_node;
bool vis[N];

inline void add_edge(int u,int v)
{
	edge2[n_edge]=Edge{v,head[u]};
	head[u]=n_edge++;
}

inline bool dfs(int k,int fa)
{
	dfn[k]=++cnt;
	for (int i=head[k]; i>-1; i=edge2[i].next)
		if (fa!=(i^1))
		{
			if (!dfn[edge2[i].v])
			{
				if (dfs(edge2[i].v,i)) return true;
			}
			else return true;
		}
	return false;
}

inline int get_fa(int k)
{
	return fa[k]==k?k:fa[k]=get_fa(fa[k]);
}

inline int read()
{
	int x=0; int w=0; char ch=0;
	while (ch<'0'||ch>'9') w|=ch=='-',ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return w? -x:x;
}

inline void init(int k)
{
	if (!vis[k])
	{
		node[n_node++]=k; vis[k]=true; head[k]=-1; dfn[k]=0;
	}
}

int main()
{
	freopen("pipe.in","r",stdin); freopen("pipe.out","w",stdout);
	int t,n,m,u,v,len,ans;
	bool b;
	t=read();
	for (int i=0; i<t; i++)
	{
		n=read(); m=read();
		for (int j=0; j<n; j++) fa[j]=j;
		for (int j=0; j<LEN; j++) edge1[j].clear();
		for (int j=0; j<m; j++)
		{
			u=read(); v=read(); len=read();
			edge1[len-1].push_back(make_pair(u-1,v-1));
		}
		ans=0;
		b=true;
		for (int j=0; j<LEN; j++)
		{
			if (!edge1[j].size()) continue;
			if (b)
			{
				for (int k=0; k<n_node; k++) vis[node[k]]=false;
				n_node=n_edge=cnt=0;
				for (int k=0; k<edge1[j].size(); k++)
				{
					int x=get_fa(edge1[j][k].first),y=get_fa(edge1[j][k].second);
					if (x!=y)
					{
						init(x); init(y);
						add_edge(x,y); add_edge(y,x);
					}
				}
				for (int k=0; k<n_node; k++)
					if (!dfn[node[k]])
						if (dfs(node[k],-1))
						{
							b=false;
							break;
						}
			}
			for (int k=0; k<edge1[j].size(); k++)
			{
				int x=get_fa(edge1[j][k].first),y=get_fa(edge1[j][k].second);
				if (x!=y) ans+=j+1,fa[x]=y;
			}
		}
		printf("%d\n",ans);
		if (b) puts("Yes");
		else puts("No");
	}
	return 0;
}