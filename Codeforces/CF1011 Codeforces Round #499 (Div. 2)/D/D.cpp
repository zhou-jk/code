#include<iostream>
#include<cstdio>
using namespace std;
const int N=35;
int n,m;
int p[N];
int ask(int y)
{
	printf("%d\n",y);
	fflush(stdout);
	int t;
	scanf("%d",&t);
	if(t==0) exit(0);
	return t;
}
int tot;
int query(int y)
{
	tot++;
	if(tot>n) tot-=n;
	int t=ask(y);
	if(p[tot]) return t;
	else return -t;
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
		p[i]=ask(1)<=0;
	int l=1,r=m;
	while(l<=r)
	{
		int mid=(l+r)/2;
		int t=query(mid);
		if(t==-1) l=mid+1;
		else if(t==1) r=mid-1;
	}
	return 0;
}
