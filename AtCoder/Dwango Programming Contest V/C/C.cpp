#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1000005;
int n,Q;
char s[N];
void solve()
{
	int k;
	scanf("%d",&k);
	deque<pair<int,int>>q;
	int add=0;
	long long sum=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		while(!q.empty()&&i-q.front().first>=k) sum-=q.front().second,q.pop_front();
		if(s[i]=='D')
		{
			q.emplace_back(i,-add);
			sum+=-add;
		}
		else if(s[i]=='M') add++;
		else if(s[i]=='C') ans+=1LL*add*q.size()+sum;
	}
	printf("%lld\n",ans);
	return;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%d",&Q);
	while(Q--)
		solve();
	return 0;
}
