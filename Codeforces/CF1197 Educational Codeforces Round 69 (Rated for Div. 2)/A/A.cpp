#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int T;
int n;
int a[N];
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	printf("%d\n",min(a[n-1]-1,n-2));
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
