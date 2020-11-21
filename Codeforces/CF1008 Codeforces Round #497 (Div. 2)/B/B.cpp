#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n;
int w[N],h[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&w[i],&h[i]);
	int pre=1e9;
	for(int i=1;i<=n;i++)
	{
		if(w[i]<h[i]) swap(w[i],h[i]);
		if(w[i]<=pre) pre=w[i];
		else if(h[i]<=pre) pre=h[i];
		else
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}
