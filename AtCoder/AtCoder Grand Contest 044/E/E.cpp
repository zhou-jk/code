#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
long long A[N];
int b[N];
long long c[N];
long long a[N];
struct Point
{
	int x;
	long long y;
};
double slope(Point a,Point b)
{
	return (double)(b.y-a.y)/(b.x-a.x);
}
Point p[N];
Point s[N];
int top;
int pos[N];
bool book[N];
long long ans[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&A[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	int Max=max_element(A+1,A+n+1)-A;
	rotate(A+1,A+Max,A+n+1);
	rotate(b+1,b+Max,b+n+1);
	n++;
	A[n]=A[1],b[n]=b[1];
	c[1]=c[2]=0;
	for(int i=2;i<=n;i++)
		c[i+1]=2*b[i]+2*c[i]-c[i-1];
	for(int i=1;i<=n;i++)
		a[i]=A[i]-c[i];
	for(int i=1;i<=n;i++)
	{
		p[i]=(Point){i,a[i]};
		while(top>=2&&slope(s[top-1],s[top])<=slope(s[top-1],p[i])) top--;
		s[++top]=p[i];
	}
	for(int i=1;i<=top;i++)
		pos[i]=s[i].x,book[pos[i]]=true;
	long double ans=0;
	for(int i=2;i<=n;i++)
		ans+=c[i];
	for(int i=2;i<=n;i++)
		if(book[i]) ans+=p[i].y;
		else
		{
			int a=lower_bound(pos+1,pos+top+1,i)-pos-1,b=upper_bound(pos+1,pos+top+1,i)-pos;
			a=pos[a],b=pos[b];
			ans+=(long double)(p[a].y*(b-i)+p[b].y*(i-a))/(b-a);
		}
	printf("%.12Lf",ans/(n-1));
	return 0;
}
