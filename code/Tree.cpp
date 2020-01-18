#include <cstdio>

const char FIRST_CH='A',LAST_CH='Z',N_KIND_CHAR=LAST_CH-FIRST_CH+1;
const int LEN=63,IN_SIZE=32*1024;
char str[LEN+1];
int trie[IN_SIZE+1][N_KIND_CHAR],cnt=1;

void insert(const char *const str)
{
	int k;
	for (int i=0,p=0; str[i]; i++)
	{
		k=str[i]-FIRST_CH;
		if (!trie[p][k]) trie[p][k]=cnt++;
		p=trie[p][k];
	}
}

int main()
{
	freopen("Tree.in","r",stdin); freopen("Tree.out","w",stdout);
	while (scanf("%s",str)!=EOF) insert(str);
	printf("%d",cnt);
	return 0;
}