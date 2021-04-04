#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m;
int v[N];
int c[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	m=*max_element(v+1,v+n+1);
	for(int i=1;i<=n;i+=2)
		c[v[i]]++;
	pair<int,int>fmx={0,0},fsmx={0,0};
	for(int i=1;i<=m;i++)
		if(make_pair(c[i],i)>fmx) fsmx=fmx,fmx={c[i],i};
		else if(make_pair(c[i],i)>fsmx) fsmx={c[i],i};
	for(int i=1;i<=n;i+=2)
		c[v[i]]=0;
	for(int i=2;i<=n;i+=2)
		c[v[i]]++;
	pair<int,int>smx={0,0},ssmx={0,0};
	for(int i=1;i<=m;i++)
		if(make_pair(c[i],i)>smx) ssmx=smx,smx={c[i],i};
		else if(make_pair(c[i],i)>ssmx) ssmx={c[i],i};
	for(int i=2;i<=n;i+=2)
		c[v[i]]=0;
	if(fmx.second!=smx.second) printf("%d\n",n-fmx.first-smx.first);
	else printf("%d\n",n-max(fsmx.first+smx.first,fmx.first+ssmx.first));
	return 0;
}
