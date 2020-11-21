#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	int ans=0,pre=1;
	for(int i=2;i<=n;i++)
		if(a[pre]>a[i]) ans++,pre++;
	printf("%d",ans);
	return 0;
}
