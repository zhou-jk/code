#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=100005;
int n;
int a[N];
map<int,int>cnt;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]!=0) cnt[a[i]]++;
	int k=cnt.size();
	printf("%d",k);
	return 0;
}
