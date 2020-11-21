#include<iostream>
#include<cstdio>
using namespace std;
const int N=205;
int n;
int a[N];
int v[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*2;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n*2;i++)
		v[i]=1;
	int ans=0;
	for(int i=1;i<=n*2;i++)
	{
		int cnt=0;
		for(int j=i+1;j<=n*2;j++)
			if(a[i]==a[j])
			{
				ans+=cnt;
				v[j]=0;
			}
			else cnt+=v[j];
	}
	printf("%d",ans);
	return 0;
}
