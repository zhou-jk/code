#include <cstdio>

const int N=30000;
int fa[N],dis[N],cnt[N];

void init()
{
	freopen("cubes.in","r",stdin); freopen("cubes.out","w",stdout);
	for (int i=0; i<N; ++i) fa[i]=i,cnt[i]=1;
}

int get_root(int k)
{
	if (fa[k]==k) return k;
	int root=get_root(fa[k]);
	dis[k]+=dis[fa[k]];
	fa[k]=root;
	return root;
}

void merge(int x,int y)
{
	int x1=get_root(x),y1=get_root(y);
	fa[y1]=x1;
	dis[y1]=cnt[x1];
	cnt[x1]+=cnt[y1];
}

int main()
{
	init();
	int q;
	scanf("%d",&q);
	getchar();
	//printf("%d\n",q);
	for (int i=0; i<q; ++i)
	{
		if (getchar()=='M')
		{
			int x,y;
			scanf("%d%d",&x,&y);
			getchar();
			merge(y-1,x-1);
		}
		else
		{
			int k;
			scanf("%d",&k);
			getchar();
			//printf("%d#\n",k);
			--k;
			get_root(k);
			printf("%d\n",dis[k]);
		}
	}
	return 0;
}