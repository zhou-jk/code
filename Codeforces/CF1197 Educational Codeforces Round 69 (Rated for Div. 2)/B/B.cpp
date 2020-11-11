#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n;
int a[N];
int pos[N];
int Min[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		pos[a[i]]=i;
	int u=pos[n];
	Min[u]=a[u];
	for(int i=u-1;i>=1;i--)
		Min[i]=min(Min[i+1],a[i]);
	for(int i=u+1;i<=n;i++)
		Min[i]=min(Min[i-1],a[i]);
	for(int i=1;i<=n;i++)
		if(Min[i]<a[i])
		{
			printf("NO");
			return 0;
		}
	printf("YES");
	return 0;
}
