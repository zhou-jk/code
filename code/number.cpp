#include <cstdio>

const int N=100,M=10;
int a[M+1][N],ans[N],tmp[N],n,m;

void calc(int num)
{
	if (!num)
	{
		for (int i=0; i<n; i++) ans[i]=a[0][i];
		return;
	}
	calc(num>>1);
	for (int i=0; i<n; i++) tmp[i]=ans[i];
	for (int i=0; i<n; i++) ans[i]=tmp[ans[i]];
	if (num&1)
	{
		for (int i=0; i<n; i++) tmp[i]=ans[i];
		for (int i=0; i<n; i++) ans[i]=tmp[a[m][i]];
	}
}

int main()
{
	freopen("number.in","r",stdin); freopen("number.out","w",stdout);
	int k,tmp;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0; i<n; i++) a[0][i]=i;
	for (int i=1; i<=m; i++)
		for (int j=0; j<n; j++) scanf("%d",&a[i][j]),a[i][j]=a[i-1][a[i][j]-1];
	/*for (int i=0; i<n; i++) printf("%d ",a[m][i]);
	puts("");*/
	calc(k/m);
	/*for (int i=0; i<n; i++) printf("%d ",ans[i]);
	puts("");*/
	tmp=k%m;
	for (int i=0; i<n; i++) printf("%d ",ans[a[tmp][i]]+1);
	return 0;
}