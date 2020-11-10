#include<iostream>
#include<cstdio>
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
		if(a[i]&1)
		{
			printf("first");
			return 0;
		}
	printf("second");
	return 0;
}
