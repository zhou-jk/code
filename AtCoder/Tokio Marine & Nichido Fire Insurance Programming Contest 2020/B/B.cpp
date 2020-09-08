#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a,b,v,w;
int t;
int main()
{
	scanf("%d%d",&a,&v);
	scanf("%d%d",&b,&w);
	scanf("%d",&t);
	if(v<=w) printf("NO");
	else if(ceil((double)abs(a-b)/(v-w))>t) printf("NO");
	else printf("YES");
	return 0;
}
