#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n;
int t[N];
int a[N],b[N];
bool f[N][4];
void print(int u,int j)
{
	if(u==n)
	{
		printf("%d ",j);
		return;
	}
	printf("%d ",j);
	for(int k=0;k<=3;k++)
		if((j|k)==a[u]&&(j&k)==b[u]&&f[u+1][k]) print(u+1,k);
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++)
		scanf("%d",&b[i]);
	f[n][0]=f[n][1]=f[n][2]=f[n][3]=true;
	for(int i=n-1;i>=1;i--)
		for(int j=0;j<=3;j++)
			if(f[i+1][j])
			{
				for(int k=0;k<=3;k++)
					if((j|k)==a[i]&&(j&k)==b[i]) f[i][k]=true;
			}
	for(int j=0;j<=3;j++)
		if(f[1][j])
		{
			printf("YES\n");
			print(1,j);
			return 0;
		}
	printf("NO");
	return 0;
}
