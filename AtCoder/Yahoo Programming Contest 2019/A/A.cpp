#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	if((n+1)/2>=k) printf("YES");
	else printf("NO");
	return 0;
}
