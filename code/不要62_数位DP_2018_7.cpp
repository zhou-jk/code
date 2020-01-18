//HDU-2089
#include <cstdio>

const int N=7;
int f[N][10],s[N+1];

int calc(int num)
{
	int ret=0,len=0;
	while (num)
	{
		s[len++]=num%10;
		num/=10;
	}
	s[len]=0;
	for (int i=len-1; i>=0; --i)
	{
		for (int j=0; j<s[i]; ++j)
			if (s[i+1]!=6||j!=2) ret+=f[i][j];
		if (s[i]==4||(s[i+1]==6&&s[i]==2)) return ret;
	}
	ret+=f[0][s[0]];
	return ret;
}

int main()
{
	int l,r;
	for (int i=0; i<10; ++i)
		if (i!=4) f[0][i]=1;
	for (int i=1; i<N; ++i)
		for (int j=0; j<10; ++j)
			for (int k=0; k<10; ++k)
				if (j!=4&&(j!=6||k!=2)) f[i][j]+=f[i-1][k];
	while (scanf("%d%d",&l,&r)!=EOF&&l+r)
		printf("%d\n",calc(r)-calc(l-1));
	return 0;
}


