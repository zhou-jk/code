#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
int n;
int a[N];
int query(int i)
{
	if(a[i]!=-1) return a[i];
	printf("? %d\n",i);
	fflush(stdout);
	scanf("%d",&a[i]);
	return a[i];
}
void submit(int ans)
{
	printf("! %d",ans);
	fflush(stdout);
	exit(0);
	return;
}
int nxt(int i)
{
	if(i>n/2) return i-n/2;
	else return i+n/2;
}
int calc(int i)
{
	return query(i)-query(nxt(i));
}
int check(int a,int b)
{
	return (a>=0&&b>=0)||(a<0&&b<0);
}
int main()
{
	scanf("%d",&n);
	memset(a,-1,sizeof(a));
	int l=1,r=nxt(1);
	if(calc(l)==0) submit(l);
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(calc(mid)==0) submit(mid);
		if(!check(calc(l),calc(mid))) r=mid-1;
		else l=mid+1;
	}
	submit(-1);
	return 0;
}
