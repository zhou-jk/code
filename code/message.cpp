#include <cstdio>

const int N=100000,M=25000;
int n,m,a[N],b[M],fail[M],s[M],ans[N],t;
bool vis[M],c[M];

void make_fail()
{
	for (int i=1,k=0; i<m; i++)
	{
		while (k&&b[k]!=b[i]) k=fail[k-1];
		if (b[k]==b[i]) k++;
		fail[i]=k;
		//printf("%d ",fail[i]);
	}
	//puts("");
}

void solve()
{
	for (int i=0,k=0; i<n; i++)
	{
		if (c[k]) s[b[k]]=a[i];
		while (k&&s[b[k]]!=a[i]) k=fail[k-1];
		if (s[b[k]]==a[i]) k++;
		if (k==m) ans[t++]=i-k+1;
	}
}

int main()
{
	//freopen("message.in","r",stdin); freopen("message.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) scanf("%d",&a[i]);
	for (int i=0; i<m; i++)
	{
		scanf("%d",&b[i]);
		b[i]--;
		if (!vis[b[i]]) vis[b[i]]=c[i]=true;
	}
	make_fail();
	solve();
	printf("%d\n",t);
	for (int i=0; i<t; i++) printf("%d\n",ans[i]+1);
	return 0;
}