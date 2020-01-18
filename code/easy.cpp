#define ls (k<<1)
#define rs ((k<<1)|1)
#define mid ((l[k]+r[k])>>1)

#include <cstdio>
#include <algorithm>

using std::max;

const int N=100001;
int l[N<<2],r[N<<2];
bool tr[N<<2],lazy[N<<2];

void push_down(int k)
{
	lazy[ls]^=lazy[k]; lazy[rs]^=lazy[k];
	lazy[k]=false;
}

void build(int k,int _l,int _r)
{
	l[k]=_l; r[k]=_r;
	if (l[k]==r[k]) return;
	build(ls,l[k],mid); build(rs,mid+1,r[k]);
	push_down(k);
}

void update(int k,int l_,int r_)
{
	if (l[k]==l_&&r[k]==r_)
	{
		lazy[k]=!lazy[k];
		return;
	}
	push_down(k);
	if (r_<=mid) update(ls,l_,r_);
	else if (l_>mid) update(rs,l_,r_);
	else update(ls,l_,mid),update(rs,mid+1,r_);
}

int query(int k,int p)
{
	if (l[k]==r[k]) return tr[k]^lazy[k];
	push_down(k);
	if (p<=mid) return query(ls,p);
	else return query(rs,p);
}

int main()
{
	freopen("easy.in","r",stdin); freopen("easy.out","w",stdout);
	int n,m,t,x,y,k;
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for (int i=0; i<m; i++)
	{
		scanf("%d",&t);
		if (t==1)
		{
			scanf("%d%d",&x,&y);
			update(1,x,y);
		}
		else
		{
			scanf("%d",&k);
			printf("%d\n",query(1,k));
		}
	}
	return 0;
}