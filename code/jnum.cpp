#include <cstdio>
#include <cmath>

using std::abs;

const int LEN=10,S=10,M=2;
int f[LEN][S],g[LEN],num[LEN];

void init()
{
	for (int i=0; i<S; i++) f[0][i]=1;
	for (int i=1; i<LEN; i++)
		for (int j=0; j<S; j++)
			for (int k=0; k<S; k++)
				if (abs(j-k)>=M) f[i][j]+=f[i-1][k];
	g[0]=1;
}

int calc(int r)
{
	int len=0,ret=0;
	while (r) num[len++]=r%10,r/=10;
	for (int i=1; i<len; i++)
	{
		g[i]=0;
		for (int j=0; j<num[i-1]; j++)
			if (abs(j-num[i])>=M) g[i]+=f[i-1][j];
		if (abs(num[i]-num[i-1])>=M) g[i]+=g[i-1];
	}
	for (int i=1; i<num[len-1]; i++) ret+=f[len-1][i];
	ret+=g[len-1];
	for (int i=0; i<len-1; i++)
		for (int j=1; j<S; j++) ret+=f[i][j];
	return ret+1;
}

int main()
{
	freopen("jnum.in","r",stdin); freopen("jnum.out","w",stdout);
	int l,r;
	scanf("%d%d",&l,&r);
	init();
	printf("%d",calc(r)-calc(l-1));
	return 0;
}