#include <cstdio>

const int N=500;
int flag[N],c[N],p[N],ans,sum;
bool vis[N];

int main()
{
	freopen("tselect.in","r",stdin); freopen("tselect.out","w",stdout);
	int n,x;
	scanf("%d %d",&n,&x);
	for (int i=0; i<n; i++)
	{
		scanf("%d %d",&c[i],&p[i]);
		p[i]--;
		if (c[i]>=0)
		{
			sum+=c[i];
			vis[i]=true;
			if (p[i]>=0)
			{
				if (vis[p[i]]) ans++;
				else flag[p[i]]++;
			}
		}
	}
	if (sum<x)
	{
		puts("-1");
		return 0;
	}
	while (true)
	{
		int k=-1;
		for (int i=0; i<n; i++)
			if (!vis[i]&&(flag[i]||(p[i]>=0&&vis[p[i]]))&&(k<0||c[i]>c[k])) k=i;
		if (k<0||sum+c[k]<x) break;
		//printf("%d\n",k);
		sum+=c[k];
		vis[k]=true;
		if (p[k]>=0&&vis[p[k]]) ans++;
		ans+=flag[k];
		//printf("$%d\n",flag[k]);
	}
	printf("%d",ans);
	return 0;
}