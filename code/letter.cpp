#include <cstdio>
#include <cstring>

const int N=10000,LEN=31,N_CHAR='z'-'a'+1;  //条件错误,数据LEN为31
char str[LEN+1],pre[LEN+1];
class Trie_Tr
{
public:
	Trie_Tr()
	{
		n_node=1; n_str=0;
		node[0].init();
	}
	void insert(const char *const str)
	{
		int k=0;
		for (int i=0; str[i]; i++)
		{
			if (!node[k].k[str[i]-'a'])
			{
				node[n_node].init();
				node[k].k[str[i]-'a']=n_node++;
			}
			k=node[k].k[str[i]-'a'];
		}
		if (!node[k].n_end)
		{
			node[k].k_end=n_str;
			strcpy(this->str[n_str++],str);
		}
		node[k].n_end++;
	}
	friend void solve();
	friend void dfs(const int k);
private:
	int n_node,n_str;
	struct Node
	{
		inline void init()
		{
			memset(k,0,sizeof k);
			n_end=k_end=0;
		}
		int k[N_CHAR],n_end,k_end;
	} node[N*LEN];
	char str[N][LEN+1];
} trie_tr;

void dfs(const int k)
{
	if (trie_tr.node[k].n_end)
		for (int i=0; i<trie_tr.node[k].n_end; i++) puts(trie_tr.str[trie_tr.node[k].k_end]);
	for (int i=0; i<N_CHAR; i++)
		if (trie_tr.node[k].k[i]) dfs(trie_tr.node[k].k[i]);
}

void solve()
{
	int k=0;
	for (int i=0; pre[i]; i++) k=trie_tr.node[k].k[pre[i]-'a'];
	dfs(k);
}

int main()
{
	freopen("letter.in","r",stdin); freopen("letter.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; i++)
	{
		scanf("%s",str);
		trie_tr.insert(str);
	}
	scanf("%s",pre);
	solve();
	return 0;
}