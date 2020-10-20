#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10;
int a[N];
int main()
{
	for(int i=1;i<=4;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+4+1);
	if(a[1]==1&&a[2]==4&&a[3]==7&&a[4]==9) printf("YES");
	else printf("NO");
	return 0;
}
