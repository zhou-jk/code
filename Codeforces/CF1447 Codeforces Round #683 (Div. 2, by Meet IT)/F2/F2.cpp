#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<random>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int mx;
int a[N];
int cnt[N];
int b[N];
int pre[N*2];
unsigned rand(unsigned l,unsigned r)
{
	static mt19937 myrand(time(NULL));
	return myrand()%(r-l+1)+l;
}
bool book[N];
int solve(int x)
{
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=n;i++)
		if(a[i]==mx) b[i]=1;
		else if(a[i]==x) b[i]=-1;
		else b[i]=0;
	for(int i=1;i<=n;i++)
		b[i]+=b[i-1];
	int res=0;
	pre[n]=0;
	for(int i=1;i<=n;i++)
		if(pre[b[i]+n]==-1) pre[b[i]+n]=i;
		else res=max(res,i-pre[b[i]+n]);
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		cnt[a[i]]++;
	mx=max_element(cnt+1,cnt+n+1)-cnt;
	vector<int>pos;
	for(int i=1;i<=n;i++)
		if(cnt[i]) pos.emplace_back(i);
	sort(pos.begin(),pos.end(),[=](const int &x,const int &y){return cnt[x]>cnt[y];});
	int k=pos.size();
	int ans=0;
	int cnt=0;
	for(int j=0;j<min(200,k);j++)
	{
		int x=pos[j];
		book[j]=true;
		cnt++;
		if(x==mx) continue;
		ans=max(ans,solve(x));
	}
	for(int j=1;j<=min(2000,k)-cnt;j++)
	{
		int y=rand(0,k-1);
		while(book[y]) y=rand(0,k-1);
		int x=pos[y];
		book[y]=true;
		if(x==mx) continue;
		ans=max(ans,solve(x));
	}
	printf("%d",ans);
	return 0;
}
