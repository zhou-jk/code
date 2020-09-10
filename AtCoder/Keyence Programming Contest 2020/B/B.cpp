#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
const int INF=1061109567;
int n;
struct Node
{
	int l,r;
}a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,l;
		scanf("%d%d",&x,&l);
		a[i].l=x-l,a[i].r=x+l;
	}
	sort(a+1,a+n+1,[=](const Node &a,const Node &b){return a.l==b.l?a.r<b.r:a.l>b.l;});
	int ans=0,now=INF+INF;
	for(int i=1;i<=n;i++)
		if(a[i].r<=now) ans++,now=min(now,a[i].l);
	printf("%d",ans);
	return 0;
}
