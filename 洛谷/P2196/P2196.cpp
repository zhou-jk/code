#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=21;
int n;
int a[N],f[N],e[N][N],sum[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            scanf("%d",&e[i][j]);
	memset(f,-1,sizeof(f));
	for(int i=n;i>=1;i--)
	{
		sum[i]=a[i];
        for(int j=i+1;j<=n;j++)
			if(e[i][j]&&sum[i]<sum[j]+a[i]) sum[i]=sum[j]+a[i],f[i]=j;
	}
    int k=max_element(sum,sum+n+1)-sum,ans=sum[k];
    while(k!=-1)
    {
        printf("%d ",k);
        k=f[k];
    }
    printf("\n%d",ans);
	return 0;
}