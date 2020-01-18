#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=100005;
int n,D;
struct Node
{
	int x,y;
}a[N];
bool cmp(Node a,Node b)
{
	return a.x<b.x;
}
bool check(int x)
{
	deque<int>qmax,qmin;
	for(int i=1;i<=n;i++)
	{
		while(!qmax.empty()&&a[i].y>a[qmax.back()].y) qmax.pop_back();
		qmax.push_back(i);
		while(!qmin.empty()&&a[i].y<a[qmin.back()].y) qmin.pop_back();
		qmin.push_back(i);
		while(!qmax.empty()&&a[i].x-a[qmax.front()].x>x) qmax.pop_front();
		while(!qmin.empty()&&a[i].x-a[qmin.front()].x>x) qmin.pop_front();
		if(a[qmax.front()].y-a[qmin.front()].y>=D) return true;
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&D);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	int l=1,r=1000000,mid,ans=-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}
