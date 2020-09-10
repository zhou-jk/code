#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=20;
const int INF=1061109567;
int n;
int a[N],b[N];
int f[1<<N][N];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	memset(f,63,sizeof(f));
	f[0][0]=0;
	for(int s=1;s<(1<<n);s++)
	{
		int t=__builtin_popcount(s);
		for(int i=0;i<n;i++)
			if(s&(1<<i))
			{
				int v=(abs(t-(i+1))&1)?b[i]:a[i];
				int num=0;
				for(int j=i+1;j<n;j++)
					if(s&(1<<j)) num++;
				for(int j=0;j<n;j++)
					if((s^(1<<i))==0) f[s][i]=min(f[s][i],f[s^(1<<i)][j]+num);
					else if((s^(1<<i))&(1<<j))
					{
						int vt=(abs(t-1-(j+1))&1)?b[j]:a[j];
						if(vt<=v) f[s][i]=min(f[s][i],f[s^(1<<i)][j]+num);
					}
			}
	}
	int ans=INF;
	for(int i=0;i<n;i++)
		ans=min(ans,f[(1<<n)-1][i]);
	if(ans>=INF) printf("-1");
	else printf("%d",ans);
	return 0;
}
