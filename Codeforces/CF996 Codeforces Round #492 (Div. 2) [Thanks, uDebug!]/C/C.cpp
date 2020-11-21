#include<iostream>
#include<cstdio>
#include<tuple>
#include<vector>
using namespace std;
const int N=55;
int n,k;
int s[5][N];
vector<tuple<int,int,int>>res;
bool check()
{
	for(int i=1;i<=n;i++)
		if(s[2][i]||s[3][i]) return false;
	return true;
}
int m;
void moveupdown()
{
	for(int i=1;i<=n;i++)
	{
		if(s[2][i]&&s[2][i]==s[1][i]) res.emplace_back(s[2][i],1,i),m++,s[2][i]=0;
		if(s[3][i]&&s[3][i]==s[4][i]) res.emplace_back(s[3][i],4,i),m++,s[3][i]=0;
	}
	return;
}
void moveleftright()
{
	auto check=[=]()
	{
		for(int i=1;i<=n;i++)
			if(!s[2][i]||!s[3][i]) return false;
		return true;
	};
	if(check())
	{
		printf("-1");
		exit(0);
	}
	int flag=false;
	if(!s[2][1]&&s[3][1]) flag=true,s[2][1]=s[3][1],res.emplace_back(s[3][1],2,1),m++,s[3][1]=0;
	for(int i=2;i<=n;i++)
		if(!s[3][i-1]&&s[3][i]) s[3][i-1]=s[3][i],res.emplace_back(s[3][i],3,i-1),m++,s[3][i]=0;
	if(!s[3][n]&&s[2][n]) s[3][n]=s[2][n],res.emplace_back(s[2][n],3,n),m++,s[2][n]=0;
	for(int i=n-1;i>=2;i--)
		if(!s[2][i+1]&&s[2][i]) s[2][i+1]=s[2][i],res.emplace_back(s[2][i],2,i+1),m++,s[2][i]=0;
	if(!flag)
	{
		if(!s[2][2]&&s[2][1]) s[2][2]=s[2][1],res.emplace_back(s[2][1],2,2),m++,s[2][1]=0;
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=4;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&s[i][j]);
	while(!check())
	{
		moveupdown();
		if(m>20000)
		{
			printf("-1");
			return 0;
		}
		moveleftright();
	}
	printf("%d\n",m);
	for(auto [i,r,c]:res)
		printf("%d %d %d\n",i,r,c);
	return 0;
}
