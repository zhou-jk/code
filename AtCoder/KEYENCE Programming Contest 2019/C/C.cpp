#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
long long a[N],b[N];
int id[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)
		id[i]=i;
	sort(id+1,id+n+1,[=](const int &x,const int &y){return a[x]-b[x]>a[y]-b[y];});
	int ans=0;
	for(int i=1;i<=n;i++)
		if(a[id[i]]-b[id[i]]<0) ans++;
	int j=n;
	for(int i=1;i<j;i++)
	{
		if(a[id[j]]-b[id[j]]>=0) break;
		long long t=a[id[i]]-b[id[i]];
		ans++;
		while(j>i&&t>0)
		{
			long long tmp=min(t,b[id[j]]-a[id[j]]);
			a[id[j]]+=tmp;
			t-=tmp,a[id[i]]-=tmp;
			if(a[id[j]]-b[id[j]]<0) break;
			j--;
		}
	}
	if(a[id[j]]-b[id[j]]<0) printf("-1");
	else printf("%d",ans);
	return 0;
}
