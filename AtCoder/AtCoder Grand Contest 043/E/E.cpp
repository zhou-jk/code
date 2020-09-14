#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1<<10;
int n;
char s[N];
int p[N];
vector<pair<int,int> > solve(int S,int now)
{
	vector<pair<int,int> >res;
	for(int i=now+1;i<n;i++)
		if(S&(1<<i))
		{
			vector<pair<int,int> > t=solve(S,i);
			for(int j=now;j<=i-1;j++)
				res.push_back(make_pair(j,1));
			for(auto [x,y]:t)
				res.push_back(make_pair(x,y));
			for(int j=i;j>=now;j--)
				res.push_back(make_pair(j,1));
			res.push_back(make_pair(now,0));
			res.push_back(make_pair(now+1,0));
			for(int j=now+1;j<=i;j++)
				res.push_back(make_pair(j,1));
			reverse(t.begin(),t.end());
			for(auto [x,y]:t)
				res.push_back(make_pair(x,y));
			for(int j=i-1;j>=now+1;j--)
				res.push_back(make_pair(j,1));
			res.push_back(make_pair(now+1,0));
			res.push_back(make_pair(now,0));
			return res;
		}
	res.push_back(make_pair(now,1));
	res.push_back(make_pair(now+1,1)); 
	res.push_back(make_pair(now+1,0));
	res.push_back(make_pair(now,0));
	return res;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<(1<<n);i++)
		p[i]=s[i]-'0';
	if(p[0]==0)
	{
		printf("Impossible");
		return 0;
	}
	for(int s=0;s<(1<<n);s++)
		if(p[s]==1)
			for(int i=s;i;i=(i-1)&s)
				if(p[i]==0)
				{
					printf("Impossible");
					return 0;
				}
	vector<pair<int,int> >ans;
	ans.push_back(make_pair(0,0));
	for(int s=1;s<(1<<n);s++)
		if(p[s]==0)
		{
			bool flag=true;
			for(int i=(s-1)&s;i;i=(i-1)&s)
				if(p[i]==0)
				{
					flag=false;
					break;
				}
			if(!flag) continue;
			vector<pair<int,int> >res;
			vector<pair<int,int> >t;
			int u=0;
			for(u=0;u<n;u++)
				if(s&(1<<u))
				{
					t=solve(s,u);
					break;
				}
			if(ans.back()!=make_pair(0,0)) res.push_back(make_pair(0,0));
			for(int i=0;i<=u-1;i++)
				res.push_back(make_pair(i,1));
			for(auto [x,y]:t)
				res.push_back(make_pair(x,y));
			for(int i=u;i>=0;i--)
				res.push_back(make_pair(i,1));
			res.push_back(make_pair(0,0));
			for(auto [x,y]:res)
				ans.push_back(make_pair(x,y));
		}
	printf("Possible\n");
	int len=ans.size()-1;
	printf("%d\n",len);
	for(auto [x,y]:ans)
		printf("%d %d\n",x,y);
	return 0;
}
