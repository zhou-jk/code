#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int T;
int ex_gcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	int d=ex_gcd(b,a%b,x,y);
	int tmp=x;
	x=y,y=tmp-a/b*y;
	return d;
}
int getinv(int A,int MOD)
{
	int x,y;
	int d=ex_gcd(A,MOD,x,y);
	if(d!=1) return -1;
	return (x+MOD)%MOD;
}
int a,x,b,y,c;
int d;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
vector<pair<int,int> >pos;
vector<int>cnt;
void getpos()
{
	pos.clear(),cnt.clear();
	int W=c,H=d;
	int now=0;
	while(true)
	{
		int r=W/H;
		pos.push_back(make_pair(1LL*now*getinv(d,c)%c,now%c==0?c:(c-now+c)%c)),cnt.push_back(r); 
		now+=r*H;
		W%=H;
		if(W==0) break;
		H%=W;
		if(H==0) H=W;
	}
	pos.push_back(make_pair(c,0));
	return;
}
void solve()
{
	scanf("%d%d%d%d%d",&a,&x,&b,&y,&c);
	int G;
	G=gcd(a,b),a/=G,b/=G,c/=gcd(G,c);
	G=gcd(a,c),a/=G,c/=G,y/=G;
	G=gcd(b,c),b/=G,c/=G,x/=G;
	a%=c,b%=c;
	if(c==1)
	{
		printf("%d\n",x+y);
		return;
	}
	d=1LL*a*getinv(b,c)%c;
	getpos();
	int ans=0;
	for(size_t i=0;i<cnt.size();i++)
	{
		int xl=pos[i].first,yl=pos[i].second,xr=pos[i+1].first,yr=pos[i+1].second;
		int dx=(xr-xl)/cnt[i],dy=(yl-yr)/cnt[i];
		int l=0,r=x+y,res=0;
		while(l<=r)
		{
			int mid=((long long)l+r)/2;
			auto check=[=](int mid)
			{
				long long p=(x-1LL*xl*mid)/dx,q=(y-1LL*yr*mid)/dy;
				return (x-1LL*xl*mid)>=0&&(y-1LL*yr*mid)>=0&&p+q>=1LL*cnt[i]*mid;
			};
			if(check(mid)) res=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,res);
	}
	printf("%d\n",ans);
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
