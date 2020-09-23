#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=200005;
int n,l;
int a[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int pre[N],nxt[N];
long long lf[N],rf[N];
vector<int>now;
long long solve(int x)
{
	long long res=0,sum=0;
	int len=now.size();
	int ppre=pre[now.front()],nnxt=nxt[now.back()];
	for(int i=0;i<len;i++)
	{
		if(i-l+1>=0) sum+=lf[now[i-l+1]];
		res+=sum*rf[now[i]];
	}
	static long long tlf[N],trf[N];
	for(int i=0;i<len;i++)
		tlf[now[i]]=lf[now[i]],trf[now[i]]=rf[now[i]],lf[now[i]]=rf[now[i]]=0;
	if(len<l)
	{
		nxt[ppre]=n+1,pre[nnxt]=0;
		return res;
	}
	int num=len/l;
	for(int i=l-1;i<len;i++)
	{
		int p=(i+1)/l-1;
		rf[now[p]]+=trf[now[i]];
	}
	for(int i=len-l;i>=0;i--)
	{
		int p=num-(len-i)/l;
		lf[now[p]]+=tlf[now[i]];
	}
	now.resize(num);
	for(int i=1;i<num;i++)
		pre[now[i]]=now[i-1],nxt[now[i-1]]=now[i];
	pre[now.front()]=ppre,nxt[ppre]=now.front();
	pre[nnxt]=now.back(),nxt[now.back()]=nnxt;
	for(int p:now)
		q.push(make_pair(x+1,p));
	sum=0;
	for(int i=0;i<num;i++)
	{
		if(i-l+1>=0) sum+=lf[now[i-l+1]];
		res-=sum*rf[now[i]];
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		q.push(make_pair(a[i],i));
		pre[i]=i-1,nxt[i]=i+1;
		lf[i]=rf[i]=1;
	}
	vector<int>pos;
	long long ans=0;
	while(!q.empty())
	{
		int x=q.top().first;
		pos.push_back(q.top().second);
		q.pop();
		while(!q.empty()&&q.top().first==x) pos.push_back(q.top().second),q.pop();
		now.push_back(pos.front());
		for(int i=1;i<pos.size();i++)
		{
			if(nxt[pos[i-1]]!=pos[i]) ans+=solve(x),now.clear();
			now.push_back(pos[i]);
		}
		ans+=solve(x);
		now.clear();
		pos.clear();
	}
	printf("%lld",ans+n);
	return 0;
}
