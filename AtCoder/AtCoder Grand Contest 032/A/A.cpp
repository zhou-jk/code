#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n;
int b[N];
int pos[N];
int ans[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		pos[i]=i;
	for(int k=n;k>=1;k--)
	{
		for(int i=n;i>=1;i--)
			if(pos[i]==b[i])
			{
				ans[k]=i;
				break;
			}
		if(!ans[k])
		{
			printf("-1");
			return 0;
		}
		pos[ans[k]]=-1;
		for(int i=ans[k]+1;i<=n;i++)
			pos[i]--;
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",b[ans[i]]);
	return 0;
}
