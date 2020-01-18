#include <cstdio>

int f[501][252][52],s[52][53];

int ord(char c)
{
	if (c>='A'&&c<='Z') return c-'A';
	return c-'a'+26;
}

int main()
{
	freopen("word.in","r",stdin); freopen("word.out","w",stdout);
	int u,l,p,ans=0;
	char tmp[3];
	scanf("%d%d%d",&u,&l,&p);
	for (int i=0; i<p; i++)
	{
		scanf("%s",tmp);
		s[ord(tmp[0])][++s[ord(tmp[0])][0]]=ord(tmp[1]);
		//printf("%d %d\n",ord(tmp[0]),ord(tmp[1]));
	}
	for (int i=0; i<26; i++) f[1][1][i+26]=f[1][0][i]=1;
	for (int i=1; i<u+l; i++)
		for (int j=0; j<=l&&j<=i; j++)
			for (int k=0; k<52; k++)
				if (f[i][j][k])
					for (int p=1; p<=s[k][0]; p++) f[i+1][j+s[k][p]/26][s[k][p]]=(f[i+1][j+s[k][p]/26][s[k][p]]+f[i][j][k])%97654321;
	for (int i=0; i<52; i++) ans=(ans+f[u+l][l][i])%97654321;
	printf("%d",ans);
	return 0;
}