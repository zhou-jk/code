//POJ-2418 FZU-1353
#include <cstdio>
#include <cstring>

const char FIRST_CH=1,LAST_CH=127;
const int LEN=30,N_KIND_STR=10000,N_KIND_CH=LAST_CH-FIRST_CH+1;
char str[LEN+1],list_str[N_KIND_STR][LEN+1];
int list_n_str[N_KIND_STR],n_kind_str,n_str;

class Node
{
public:
	Node()
	{
		k_end=-1;
		for (int i=0; i<N_KIND_CH; i++) p[i]=NULL;
	}
	~Node()
	{
		for (int i=0; i<N_KIND_CH; i++)
			if (p[i]!=NULL) delete p[i];
	}
	friend inline void insert(const char *const str);
	friend void dfs(Node *p);
private:
	int k_end;
	Node *p[N_KIND_CH];
} trie;

inline void insert(const char *const str)
{
	Node *p=&trie;
	int k;
	for (int i=0; str[i]; i++)
	{
		k=str[i]-FIRST_CH;
		if (p->p[k]==NULL) p->p[k]=new Node;
		p=p->p[k];
	}
	if (p->k_end==-1) strcpy(list_str[p->k_end=n_kind_str++],str);
	list_n_str[p->k_end]++;
}

void dfs(Node *p)
{
	if (p->k_end>-1) printf("%s %.4f\n",list_str[p->k_end],list_n_str[p->k_end]*100.0/n_str);
	for (int i=0; i<N_KIND_CH; i++)
		if (p->p[i]!=NULL) dfs(p->p[i]);
}

int main()
{
	while (gets(str)!=NULL) insert(str),n_str++;
	dfs(&trie);
	return 0;
}