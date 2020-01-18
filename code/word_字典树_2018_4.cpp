#include <cstdio>
#include <cstring>

const char FIRST_CH='a',LAST_CH='z';
const int LEN_S=300000,LEN_PAT=100,N=4000,N_KIND_CHAR=LAST_CH-FIRST_CH+1,D=1337377;
char str[LEN_S+1],pat[LEN_PAT+1];
int f[LEN_S+1];

class Node
{
public:
	Node()
	{
		for (int i=0; i<N_KIND_CHAR; i++) k[i]=NULL;
		n_end=0;
	}
	friend void insert(const char *const str);
	friend void find(const int begin);
private:
	Node *k[N_KIND_CHAR];
	int n_end;
} trie;

void insert(const char *const str)
{
	Node *p=&trie;
	int k;
	for (int i=0; str[i]; i++)
	{
		k=str[i]-FIRST_CH;
		if (p->k[k]==NULL) p->k[k]=new Node;
		p=p->k[k];
	}
	p->n_end++;
}

void find(const int begin)
{
	Node *p=&trie;
	int k;
	for (int i=begin; str[i]; i++)
	{
		k=str[i]-FIRST_CH;
		if (p->k[k]==NULL) break;
		p=p->k[k];
		if (p->n_end) f[begin]=(f[begin]+f[i+1])%D;
	}
}

int main()
{
	freopen("word.in","r",stdin); freopen("word.out","w",stdout);
	int n,len_s;
	scanf("%s%d",str,&n);
	for (int i=0; i<n; i++)
	{
		scanf("%s",pat);
		insert(pat);
	}
	len_s=strlen(str);
	f[len_s]=1;
	for (int i=len_s-1; i>=0; i--) find(i);
	printf("%d\n",f[0]);
	return 0;
}