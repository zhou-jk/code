#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n,Q;
char s[N];
char t[N],d[N];
bool checkl(int x)
{
	int p=x;
	for(int i=1;i<=Q;i++)
	{
		if(t[i]==s[p])
		{
			if(d[i]=='L') p--;
			else if(d[i]=='R') p++;
		}
		if(p<1) return false;
		if(p>n) return true;
	}
	return true;
}
bool checkr(int x)
{
	int p=x;
	for(int i=1;i<=Q;i++)
	{
		if(t[i]==s[p])
		{
			if(d[i]=='L') p--;
			else if(d[i]=='R') p++;
		}
		if(p<1) return true;
		if(p>n) return false;
	}
	return true;
}
int main()
{
	cin>>n>>Q;
	cin>>s+1;
	for(int i=1;i<=Q;i++)
		cin>>t[i]>>d[i];
	int L=n+1,R=0;
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(checkl(mid)) L=mid,r=mid-1;
		else l=mid+1;
	}
	l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(checkr(mid)) R=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<max(R-L+1,0);
	return 0;
}
