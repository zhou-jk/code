#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=55;
int n;
int a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int m=*min_element(a+1,a+n+1);
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(a[i]==m) cnt++;
	if(cnt>n/2) printf("Bob");
	else printf("Alice");
	return 0;
}
