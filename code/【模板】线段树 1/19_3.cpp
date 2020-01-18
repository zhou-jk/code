// AC
#include <cstdio>

#define mid ((l[k] + r[k]) >> 1)
#define lc (k << 1)
#define rc ((k << 1) | 1)

const int N = 100000;
int l[N << 2], r[N << 2];
long long node[N << 2], tag[N << 2];

void modify(int k, long long val)
{
	node[k] += val * (r[k] - l[k] + 1);
	tag[k] += val;
}

void push_up(int k)
{
	node[k] = node[lc] + node[rc];
}

void push_down(int k)
{
	modify(lc, tag[k]);
	modify(rc, tag[k]);
	tag[k] = 0;
}

void build(int k, int _l, int _r)
{
	l[k] = _l;
	r[k] = _r;
	if (_l == _r)
	{
		scanf("%lld", node + k);
		return;
	}
	build(lc, l[k], mid);
	build(rc, mid + 1, r[k]);
	push_up(k);
}

void update(int k, int l_, int r_, long long val)
{
	if (l_ <= l[k] && r[k] <= r_)
	{
		modify(k, val);
		return;
	}
	push_down(k);
	if (l_ <= mid) update(lc, l_, r_, val);
	if (r_ > mid) update(rc, l_, r_, val);
	push_up(k);
}

long long query(int k, int l_, int r_)
{
	if (l_ <= l[k] && r[k] <= r_) return node[k];
	long long ret = 0;
	push_down(k);
	if (l_ <= mid) ret += query(lc, l_, r_);
	if (r_ > mid) ret += query(rc, l_, r_);
	return ret;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	while (m--)
	{
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1)
		{
			long long val;
			scanf("%lld", &val);
			update(1, l, r, val);
		}
		else
			printf("%lld\n", query(1, l, r));
	}
	return 0;
}