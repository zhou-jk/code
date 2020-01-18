#include <cstdio>
#include <cstring>

const int N_KIND_CH=26,LEN=10;
int g1[N_KIND_CH][N_KIND_CH],ind[N_KIND_CH],queue[N_KIND_CH];
bool g2[N_KIND_CH][N_KIND_CH],vis[N_KIND_CH];
char a[LEN+1],b[LEN+1];

int main()
{
	freopen("lng.in","r",stdin); freopen("lng.out","w",stdout);
	int n,l,r=0,cnt=0;
	bool flag=false;
	scanf("%d",&n);
	scanf("%s",a);
	for (int i=0; a[i]; ++i) vis[a[i]-'a']=true;
	for (int i=1; i<n; ++i)
	{
		int j;
		scanf("%s",b);
		for (j=0; b[j]; ++j) vis[b[j]-'a']=true;
		for (j=0; a[j]==b[j]; ++j);
		if ((a[j])&&!g2[a[j]-'a'][b[j]-'a'])
		{
			g2[a[j]-'a'][b[j]-'a']=true;
			g1[a[j]-'a'][++g1[a[j]-'a'][0]]=b[j]-'a';
			++ind[b[j]-'a'];
		}
		strcpy(a,b);
	}
	for (int i=0; i<N_KIND_CH; ++i)
		if (vis[i])
		{
			++cnt;
			if (!ind[i]) queue[r++]=i;
		}
	for (l=0; l<r; ++l)
	{
		if (r-l>1) flag=true;
		for (int i=1; i<=g1[queue[l]][0]; ++i)
		{
			--ind[g1[queue[l]][i]];
			if (!ind[g1[queue[l]][i]]) queue[r++]=g1[queue[l]][i];
		}
	}
	if (r<cnt) puts("!");
	else if (flag) puts("?");
	else for (int i=0; i<cnt; ++i) putchar(queue[i]+'a');
	return 0;
}