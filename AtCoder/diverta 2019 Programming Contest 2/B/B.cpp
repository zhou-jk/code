#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int N=55;
int n;
pair<int,int>a[N];
map<pair<int,int>,bool>book;
int calc(int p,int q)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=a[i].first,y=a[i].second;
		if(!book[make_pair(x-p,y-q)]) ans++;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i]=make_pair(x,y);
		book[a[i]]=true;
	}
	sort(a+1,a+n+1);
	int ans=n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			int x=a[i].first-a[j].first,y=a[i].second-a[j].second;
			ans=min(ans,calc(x,y));
		}
	printf("%d",ans);
	return 0;
}
