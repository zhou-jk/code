#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005;
int T;
int n;
int b[N];
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(b+1,b+n+1);
	for(int i=2;i<=n;i++)
		if(b[i]==b[i-1])
		{
			printf("YES\n");
			return;
		}
	printf("NO\n");
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
