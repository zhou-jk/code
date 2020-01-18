#include <cstdio>
#include <cstring>

using std::scanf;
using std::memset;

const int LEN=11;
char l[LEN+1],r[LEN+1];
long long f[LEN][2][2][2][2];

long long solve(char *r,int k,bool lim,bool b4,bool b8,bool lx,int l1,int l2)
{
	//printf("%d %d %d %d %d %d %d\n",k,lim,b4,b8,lx,l1,l2);
	if (k==LEN&&lx) return 1;
	if (~f[k][lim][b4][b8][lx]) return f[k][lim][b4][b8][lx];
	f[k][lim][b4][b8][lx]=0;
	if (lim)
		for (int i=!k;i<=r[k]-'0';++i)
			if ((!b4||i!=8)&&(!b8||i!=4))
				f[k][lim][b4][b8][lx]+=solve(r,k+1,i==r[k]-'0',b4||i==4,b8||i==8,lx||(i==l1&&l1==l2),l2,i);
	else
		for (int i=0;i<10;++i)
			if ((!b4||i!=8)&&(!b8||i!=4))
				f[k][lim][b4][b8][lx]+=solve(r,k+1,0,b4||i==4,b8||i==8,lx||(i==l1&&l1==l2),l2,i);
	return f[k][lim][b4][b8][lx];
}

bool check(char *s)
{
	bool b1=false,b2=false,b3=false;
	int l1=-1,l2=-1;
	for (int i=0;s[i];++i)
	{
		int tmp=s[i]-'0';
		if (tmp==4) b1=true;
		if (tmp==8) b2=true;
		if (b1&&b2) return false;
		if (tmp==l1&&l1==l2) b3=true;
		l1=l2;
		l2=tmp;
	}
	return b3;
}

int main()
{
	freopen("evelynn.in","r",stdin);
	freopen("evelynn.out","w",stdout);
	long long ans2,ans1;
	scanf("%s%s",l,r);
	memset(f,-1,sizeof f);
	ans1=solve(l,0,1,0,0,0,-1,-1);
	memset(f,-1,sizeof f);
	ans2=solve(r,0,1,0,0,0,-1,-1);
	printf("%lld",ans2-ans1+check(l));
	return 0;
}

