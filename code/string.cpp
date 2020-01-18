#include <cstdio>
#include <algorithm>

using std::max;
using std::sort;

const int LEN=50;
char str[LEN+1];
int f[LEN],s[LEN];

int main()
{
	freopen("string.in","r",stdin); freopen("string.out","w",stdout);
	int m,cnt,tmp,ans=1;
	scanf("%s%d",str,&m);
	for (int i=0; str[i]; i++)
	{
		cnt=tmp=0;
		for (int j=i-1; j>=0; j--)
		{
			if (str[j+1]==str[i]) f[j]=f[j+1];
			else f[j]=f[j+1]+1;
			if (str[j]==str[i]) s[cnt++]=f[j];
		}
		for (int j=i+1; str[j]; j++)
		{
			if (str[j-1]==str[i]) f[j]=f[j-1];
			else f[j]=f[j-1]+1;
			if (str[j]==str[i]) s[cnt++]=f[j];
		}
		sort(s,s+cnt);
		int j;
		for (j=0; j<cnt; j++)
		{
			tmp+=s[j];
			if (tmp>m) break;
		}
		ans=max(ans,j+1);
	}
	printf("%d",ans);
	return 0;
}