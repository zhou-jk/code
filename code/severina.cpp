#include <cstdio>
#include <cstring>

const char FIRST_CHAR='a',LAST_CHAR='z';
const int N=4000,LEN_STR=300000,LEN_PAT=100,
          N_CHAR=LAST_CHAR-FIRST_CHAR+1,D=1337377;
struct Node
{
	int k[N_CHAR],n_end;
} trie[N*LEN_PAT];
char a[LEN_STR+1],b[LEN_PAT+1];
int f[LEN_STR+1],n_node=1;

void insert(char s[])
{
	int k=0;
	for (int i=0; s[i]; ++i)
	{
		if (!trie[k].k[s[i]-FIRST_CHAR])
			trie[k].k[s[i]-FIRST_CHAR]=n_node++;
		k=trie[k].k[s[i]-FIRST_CHAR];
	}
	++trie[k].n_end;
}

int main()
{
	freopen("severina.in","r",stdin); freopen("severina.out","w",stdout);
	int n,len;
	scanf("%s%d",a,&n);
	for (int i=0; i<n; ++i)
	{
		scanf("%s",b);
		insert(b);
	}
	f[len=strlen(a)]=1;
	for (int i=len-1; ~i; --i)
	{
		int k=0;
		for (int j=i; a[j]&&trie[k].k[a[j]-FIRST_CHAR]; ++j)
		{
			k=trie[k].k[a[j]-FIRST_CHAR];
			f[i]=(f[i]+trie[k].n_end*f[j+1]%D)%D;
		}
	}
	printf("%d",f[0]);
	return 0;
}