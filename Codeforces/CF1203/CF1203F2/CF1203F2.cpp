#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm> 
using namespace std;
int n,r;
vector<pair<int,int> >zheng,fu;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(b<0) fu.push_back(make_pair(a,b));
		else zheng.push_back(make_pair(a,b));
	}
	sort(zheng.begin(),zheng.end());
	for(auto &[a,b]:fu)
	{
		a+=b;
		a=max(a,0); 
	}
	sort(fu.begin(),fu.end(),greater<pair<int,int> >());
	int ans=0;
	for(auto [a,b]:zheng)
		if(r>=a) r+=b,ans++;
	for(auto [a,b]:fu)
	{
		r+=b;
		q.push(b);
		if(r<a) r-=q.top(),q.pop();
	}
	ans+=q.size();
	printf("%d",ans);
	return 0;
}
