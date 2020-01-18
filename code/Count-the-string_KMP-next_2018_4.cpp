//VOJ HDU 3336
#include <cstdio>

const int LEN=200000,D=10007;
char s[LEN+1];
int f[LEN+1],next[LEN+1];

void make_next()
{
	for (int i=1,k=0; s[i]; i++)
	{
		while (k&&s[i]!=s[k]) k=next[k];
		if (s[i]==s[k]) k++;
		next[i+1]=k;
	}
}

int main()
{
	int t,len,ans;
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%d%s",&len,s);
		make_next();
		ans=0;
		for (int j=1; j<=len; j++) ans=(ans+(f[j]=(f[next[j]]+1)%D))%D;
		printf("%d\n",ans);
	}
	return 0;
}