#define ls (k<<1)
#define rs ((k<<1)|1)
#define mid ((l[k]+r[k])>>1)

#include <cstdio>
#include <algorithm>

using std::max;

const int N = 100001;
int tr[N << 2], l[N << 2], r[N << 2];

void push_up(int k)
{
	tr[k] = max(tr[ls], tr[rs]);
}

void build(int k, int _l, int _r)
{
	l[k] = _l; r[k] = _r;
	if (l[k] == r[k])
	{
		scanf("%d", &tr[k]);
		return;
	}
	build(ls, l[k], mid); build(rs, mid + 1, r[k]);
	push_up(k);
}

int query(int k, int l_, int r_)
{
	if (l[k] == l_ && r[k] == r_) return tr[k];
	if (r_ <= mid) return query(ls, l_, r_);
	else if (l_ > mid) return query(rs, l_, r_);
	return max(query(ls, l_, mid), query(rs, mid + 1, r_));
}

int main()
{
	freopen("climb.in", "r", stdin); freopen("climb.out", "w", stdout);
	int n, q, x, y;
	scanf("%d", &n);
	build(1, 0, n);
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", query(1, x, y));
	}
	return 0;
}