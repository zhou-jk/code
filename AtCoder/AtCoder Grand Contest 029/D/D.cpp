#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int h,w,n;
pair<int,int>a[N];
pair<int,int>c[N];
int cnt;
int main()
{
	scanf("%d%d%d",&h,&w,&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].first,&a[i].second);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(a[i].first!=1&&a[i].first!=c[cnt].first) c[++cnt]=a[i];
	int x=1,y=1;
	for(int i=1;i<=cnt;i++)
	{
		auto [dx,dy]=c[i];
		if(dy<y+(dx-x))
		{
			printf("%d",dx-1);
			return 0;
		}
		else if(dy==y+(dx-x)) y=dy-1;
		else y+=(dx-x);
		x=dx;
	}
	printf("%d",h);
	return 0;
}