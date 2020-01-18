//VOJ LA 3026
#include <cstdio>

const int LEN=1000000;
int next[LEN],cnt;
char s[LEN+1];

int main()
{
	int len;
	while (scanf("%d%s",&len,s)!=EOF&&len)
	{
		printf("Test case #%d\n",++cnt);
		for (int i=1,j=0; s[i]; i++)
		{
			//puts("12");
			while (j&&s[i]!=s[j]) j=next[j-1];
			//puts("11");
			if (s[i]==s[j]) j++;
			next[i]=j;
			if (next[i]&&!((i+1)%(i+1-next[i]))) printf("%d %d\n",i+1,(i+1)/(i+1-next[i]));
		}
		printf("\n");
	}
	return 0;
}