#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=105;
int n;
int a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	double avg=(double)sum/n;
	double Min=1e9;
	int t=0;
	for(int i=1;i<=n;i++)
		if(abs(a[i]-avg)<Min) Min=abs(a[i]-avg),t=i;
	printf("%d",t-1);
	return 0;
}
