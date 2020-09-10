#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
int n,k,s;
int main()
{
	scanf("%d%d%d",&n,&k,&s);
	for(int i=1;i<=k;i++)
		printf("%d ",s);
	for(int i=1;i<=n-k;i++)
		printf("%d ",s==1000000000?1000000000-1:1000000000); 
	return 0;
}
