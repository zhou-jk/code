#define lc (k << 1)
#define rc ((k << 1) | 1)
#define mid ((l[k] + r[k]) >> 1)

#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

using std::sort;
using std::swap;

const int N = 500000, M = 1000000;
struct A
{
	int u, v, len;
} a[M];
int num[N << 2], l[N << 2], r[N << 2];
bool lazy[N << 2];

inline int read()
{
	int X = 0, w = 0;
	char ch = 0;
	while (!isdigit(ch))
	{
		w |= ch == '-';
		ch = getchar();
	}
	while (isdigit(ch))
		X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	return w ? -X : X;
}

bool cmp(A a, A b)
{
	return a.v < b.v;
}

void push_down(int k)
{
	num[lc] = mid - l[k] + 1;
	num[rc] = r[k] - mid;
	lazy[lc] = lazy[rc] = true;
}

void push_up(int k)
{
	num[k] = num[lc] + num[rc];
}

void build(int k, int _l, int _r)
{
	l[k] = _l;
	r[k] = _r;
	if (l[k] == r[k])
		return;
	build(lc, l[k], mid);
	build(rc, mid + 1, r[k]);
}

void update(int k, int l_, int r_)
{
	if (l[k] == l_ && r[k] == r_)
	{
		num[k] = r[k] - l[k] + 1;
		lazy[k] = true;
		return;
	}
	if (lazy[k])
		push_down(k);
	if (r_ <= mid)
		update(lc, l_, r_);
	else if (l_ > mid)
		update(rc, l_, r_);
	else
		update(lc, l_, mid), update(rc, mid + 1, r_);
	push_up(k);
}

int query1(int k, int l_, int r_)
{
	if (l[k] == l_ && r[k] == r_)
		return num[k];
	if (lazy[k])
		push_down(k);
	if (r_ <= mid)
		return query1(lc, l_, r_);
	else if (l_ > mid)
		return query1(rc, l_, r_);
	else
		return query1(lc, l_, mid) + query1(rc, mid + 1, r_);
}

int query2(int k, int l_, int r_, int len, int &ret)
{
	int tmp, tmp2;
	if (l_ == r_)
	{
		ret = 1 - num[k];
		return l_;
	}
	if (lazy[k])
		push_down(k);
	if (r_ <= mid)
		return query2(lc, l_, r_, len, ret);
	else if (l_ > mid)
		return query2(rc, l_, r_, len, ret);
	else
	{
		tmp = query2(rc, mid + 1, r_, len, ret);
		if (ret >= len)
			return tmp;
		else
		{
			tmp2 = query2(lc, l_, mid, len - ret, tmp);
			ret += tmp;
			return tmp2;
		}
	}
}

int main()
{
	freopen("wall.in", "r", stdin);
	freopen("wall.out", "w", stdout);
	int n, m, nop, ans = 0;
	n = read();
	m = read();
	for (int i = 0; i < m; i++)
	{
		a[i] = {read(), read(), read()};
		if (a[i].u > a[i].v)
			swap(a[i].u, a[i].v);
	}
	sort(a, a + m, cmp);
	build(1, 1, n);
	for (int i = 0; i < m; i++)
	{
		int tmp1 = a[i].len - query1(1, a[i].u, a[i].v);
		//printf("%d\n",tmp1);
		if (tmp1 > 0)
		{
			update(1, query2(1, a[i].u, a[i].v, tmp1, nop), a[i].v);
			ans += tmp1;
		}
	}
	printf("%d", ans);
	return 0;
}