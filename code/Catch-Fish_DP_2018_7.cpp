//SPOJ-MFISH
#include <cstdio>
#include <algorithm>

using std::max;
using std::sort;

const int N=100001,M=100001;
int k[N],sum[N],f[N];

struct Node
{
	int pos,len;
} node[M];

bool cmp(Node a,Node b)
{
	return a.pos<b.pos;
}

int main()
{
	int n,m,num,ans=0;
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&num);
		sum[i]=sum[i-1]+num;
	}
	scanf("%d",&m);
	node[0].len=0; node[0].pos=-100000;
	for (int i=1; i<=m; i++) scanf("%d%d",&node[i].pos,&node[i].len);
	sort(node+1,node+m+1,cmp);
	for (int i=1; i<m; i++)
		for (int j=max(node[i].pos,node[i-1].pos+node[i].len); j<node[i].pos+node[i].len&&j<node[i+1].pos; j++) k[j]=i;
	for (int i=max(node[m].pos,node[m-1].pos+node[m].len); i<node[m].pos+node[m].len&&i<=n; i++) k[i]=m;
	for (int i=1; i<=n; i++)
	{
		f[i]=f[i-1];
		if (i-node[k[i]].len>=0) f[i]=max(f[i],f[i-node[k[i]].len]+sum[i]-sum[i-node[k[i]].len]);
		ans=max(ans,f[i]);
	}
	printf("%d",ans);
	return 0;
}