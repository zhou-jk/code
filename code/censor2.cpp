#include <cstdio>
#include <cstring>

const int N=2000,LEN=100000;
char t[N][LEN+1],s[LEN+1];
int k[N],p[LEN],len[N],*next[N];

void make_next(int k)
{
	next[k][0]=0;
	for (int i=1,p=0; t[k][i]; i++)
	{
		while (t[k][i]!=t[k][p]&&p) p=next[k][p-1];
		if (t[k][i]==t[k][p]) k++;
		next[k][i]=p;
	}
}

int main()
{
	//freopen("censor2.in","r",stdin); freopen("censor2.out","w",stdout);
	int n;
	scanf("%s",s);
	scanf("%d",&n);
	for (int i=0; i<n; i++)
	{
		puts("&&");
		scanf("%s",t[i]);
		len[i]=strlen(t[i]);
		next[i]=new int[len[i]];
		make_next(i);
	}
	for (int i=0; s[i]; i=p[i])
		for (int j=0; j<n; j++)
		{
			while (s[i]!=t[j][k[j]]&&k[j]) k[j]=next[j][k[j]-1];
			if (s[i]==t[j][k[j]]) k[j]++;
			if (k[j]==len[j]) p[i-k[j]]=i+1;
		}
	for (int i=0; s[i]; i=p[i]) printf("%c",s[i]);
	return 0;
}