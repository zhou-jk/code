#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N],b[N];
int id[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++)
		id[i]=i;
	sort(id+1,id+n+1,[=](const int &x,const int &y){return a[x]+b[x]>a[y]+b[y];});
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans-=b[i];
	for(int i=1;i<=n;i+=2)
		ans+=a[id[i]]+b[id[i]];
	printf("%lld",ans);
	return 0;
}
