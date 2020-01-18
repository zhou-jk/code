#define lc (k<<1)
#define rc ((k<<1)|1)

#include <cstdio>
#include <cstring>

const int N=2048,M=500;
/*struct Num
{
	int num[M];
	Num()
	{
		memset(num,0,sizeof num);
	}
	Num operator+(const Num &b)
	{
		int t=0;
		Num ret;
		for (int i=0; i<M; i++)
		{
			ret.num[i]=num[i]+b.num[i]+t;
			t=ret.num[i]/10;
			ret.num[i]%=10;
		}
		return ret;
	}
	Num operator*(const Num &b)
	{
		int t=0;
		Num ret;
		for (int i=0; i<M; i++)
			if (num[i])
				for (int j=0; j<M; j++)
					if (b.num[j])
						ret.num[i+j]+=num[i]*b.num[j];
		for (int i=0; i<M; i++)
		{
			ret.num[i]+=t;
			t=ret.num[i]/10;
			ret.num[i]%=10;
		}
		return ret;
	}
};*/
int n;
long long f[2][N+1];

/*void output(const Num &num)
{
	int i;
	for (i=M-1; !num.num[i]; i--);
	for (; i>=0; i--) printf("%d",num.num[i]);
}*/

void dfs(int k,int num)
{
	//printf("%d %d\n",k,num);
	f[0][k]=f[1][k]=1;
	if (num*4<=n)
	{
		dfs(lc,num*4);
		f[0][k]=f[0][k]*(f[0][lc]+f[1][lc])%100000000;
		f[1][k]=f[1][k]*f[0][lc]%100000000;
	}
	if (num*5<=n)
	{
		dfs(rc,num*5);
		f[0][k]=f[0][k]*(f[0][rc]+f[1][rc])%100000000;
		f[1][k]=f[1][k]*f[0][rc]%100000000;
	}
}

int main()
{
	freopen("lastvs.in","r",stdin); freopen("lastvs.out","w",stdout);
	scanf("%d",&n);
	dfs(1,1);
	//output(f[0][1]+f[1][1]);
	printf("%lld",(f[0][1]+f[1][1])%100000000);
	return 0;
}