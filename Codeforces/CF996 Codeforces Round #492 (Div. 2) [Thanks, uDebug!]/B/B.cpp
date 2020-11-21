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
	for(int i=1;i<=n;i++)
		a[i]=(a[i]-i+n)/n;
	int p=min_element(a+1,a+n+1)-a;
	printf("%d",p);
	return 0;
}
