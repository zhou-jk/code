#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=105;
int n,k;
int a[N];
int c[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		c[a[i]]++;
	int m=0;
	int cnt=0;
	for(int i=1;i<=100;i++)
	{
		m=max(m,c[i]);
		if(c[i]>0) cnt++;
	}
	m=(m+k-1)/k*k;
	printf("%d",m*cnt-n);
	return 0;
}
