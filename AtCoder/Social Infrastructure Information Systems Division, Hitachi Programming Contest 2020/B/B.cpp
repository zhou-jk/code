#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int A,B,n;
int a[N],b[N];
int x[N],y[N],c[N];
int main()
{
	scanf("%d%d%d",&A,&B,&n);
	for(int i=1;i<=A;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=B;i++)
		scanf("%d",&b[i]);
	int ans=(*min_element(a+1,a+A+1))+(*min_element(b+1,b+B+1));
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&c[i]);
		ans=min(ans,a[x[i]]+b[y[i]]-c[i]);
	}
	printf("%d",ans);
	return 0;
}
