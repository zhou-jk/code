#include <cstdio>

const char L_CH='a',R_CH='z';
const int N=50,LEN=50,N_KIND_CH=R_CH-L_CH+1;
struct Node
{
	int k[N_KIND_CH];
	bool end;
} node[N*LEN];
int n_node=1;
char s[LEN];

void insert(char *s)
{
	int k1=0;
	for (int i=0; s[i]; i++)
	{
		int k2=s[i]-L_CH;
		if (!node[k1].k[k2]) node[k1].k[k2]=n_node++;
		k1=node[k1].k[k2];
	}
	node[k1].end=true;
}

long long dfs(int k)
{
	long long ret=1;
	for (int i=0; i<N_KIND_CH; i++)
		if (node[k].k[i]) ret*=dfs(node[k].k[i]);
	if (node[k].end) ret++;
	return ret;
}

int main()
{
	freopen("prefix.in","r",stdin); freopen("prefix.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; i++)
	{
		scanf("%s",s);
		insert(s);
	}
	printf("%lld",dfs(0));
	return 0;
}