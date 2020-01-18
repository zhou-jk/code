// AC
#include <algorithm>
#include <cstdio>

using std::sort;

const int N = 100000;
struct Ques
{
	int k, c;
} qu[N];
int an[N], ans[N];

bool cmp(Ques &a, Ques &b)
{
	return a.k < b.k;
}

int main()
{
	freopen("queue.in", "r", stdin);
	freopen("queue.out", "w", stdout);
	int n, l, q, k, d;
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &k, &d);
		an[i] = d ? l - k : k;
	}
	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
	{
		scanf("%d", &qu[i].k);
		qu[i].c = i;
	}
	sort(qu, qu + q, cmp);
	sort(an, an + n);
	for (int i = 0, j = 0; i < q; ++i)
	{
		while (j < n && qu[i].k >= an[j]) ++j;
		ans[qu[i].c] = j;
	}
	for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
	return 0;
}