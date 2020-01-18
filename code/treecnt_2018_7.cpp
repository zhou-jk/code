//51nod-1677
#include <cstdio>
#include <cstring>

typedef long long ll;

const int N=1e5,D=1e9+7;
struct Edge
{
	int v,next;
} edge[(N-1)<<1];
int head[N],fact[N+1],inv[N+1],n,m,n_edge,ans;

inline void add_edge(const int u,const int v)
{
	edge[n_edge]= {v,head[u]};
	head[u]=n_edge++;
}

inline int pow(const int base,const int exp)
{
	int ret=1,tmp1=base,tmp2=exp;
	for (; tmp2; tmp1=(ll)tmp1*tmp1%D,tmp2>>=1)
		if (tmp2&1) ret=(ll)ret*tmp1%D;
	return ret;
}

inline int c(const int a,const int b)
{
	if (a<b) return 0;
	return (ll)fact[a]*inv[a-b]%D*inv[b]%D;
}

int dfs(const int k,const int fa)
{
	int ret=1;
	for (int i=head[k]; i!=-1; i=edge[i].next)
	{
		int v=edge[i].v;
		if (v!=fa)
		{
			int tmp=dfs(v,k);
			ans=((ans+c(n,m)-c(tmp,m)-c(n-tmp,m))%D+D)%D;
			ret+=tmp;
		}
	}
	return ret;
}

int main()
{
	scanf("%d%d",&n,&m);
	fact[0]=1;
	for (int i=1; i<=n; i++)
	{
		fact[i]=(ll)fact[i-1]*i%D;
		inv[i]=pow(fact[i],D-2);
	}
	inv[0]=inv[1];
	memset(head,-1,sizeof head);
	for (int i=1; i<n; i++)
	{
		int u,v;
		scanf("%d",&u); scanf("%d",&v);
		u--; v--;
		add_edge(u,v); add_edge(v,u);
	}
	dfs(0,-1);
	printf("%d",ans);
	return 0;
}