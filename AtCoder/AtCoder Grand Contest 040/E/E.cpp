#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=200005;
int n;
int a[N];
map<int,int>f[N];
void update(map<int,int>&f,int j,int v)
{
	if(!f.count(j)) f[j]=v;
	else f[j]=min(f[j],v);
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[1][0]=a[1],f[1][1]=0;
	for(int i=2;i<=n;i++)
	{
		int vl=min(0,a[i]-a[i-1]),vr=max(0,a[i]-a[i-1]);
		for(auto [v,j]:f[i-1])
		{
			if(f[i-1].begin()->first<v-2) break;
			if(j+vl>0) update(f[i],v+2,0);
  	  		if(j+vl<=a[i]) update(f[i],v+1,max(j+vl,0));
  	  		if(j+vr<=a[i]) update(f[i],v,max(j+vr,0));
		}
	}
	int ans=1e9;
	for(auto [v,j]:f[n])
		ans=min(ans,v+(j>0));
	printf("%d",ans);
	return 0;
}
