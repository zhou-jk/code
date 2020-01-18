#include <algorithm>
#include <cstdio>
#include <functional>

using std::max;
using std::swap;

const int N = 100000, M = 1000000;
struct Node
{
	Node(const int _num = -1) : num(_num), next(NULL) {}
	int num;
	Node *next;
} * head[M], *h[M];
int a[N], cnt[M], hh[M], n, ans;

void check(int k, int num)
{
	if (k >= n || k < 0)
		return;
	//printf("%d %d %d\n",k,num,a[k]);
	if (a[k] == num)
		--ans;
}

void merge(int x, int y)
{
	if (x == y)
		return;
	if (cnt[x] < cnt[y])
	{
		swap(h[x], h[y]);
		swap(head[x], head[y]);
		swap(hh[x], hh[y]);
	}
	Node *p = h[y]->next;
	//printf("%d %d\n",x,y);
	if (p == NULL)
		return;
	while (p != NULL)
	{
		//printf("#%d\n",p->num);
		check(p->num + 1, hh[x]);
		check(p->num - 1, hh[x]);
		p = p->next;
	}
	p = h[y]->next;
	while (p != NULL)
	{
		a[p->num] = hh[x];
		p = p->next;
	}
	head[x]->next = h[y]->next;
	head[x] = head[y];
	head[y] = h[y];
	h[y]->next = NULL;
	cnt[x] += cnt[y];
	cnt[y] = 0;
}

int main()
{
	freopen("pudding.in", "r", stdin);
	freopen("pudding.out", "w", stdout);
	int q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < M; ++i)
	{
		head[i] = h[i] = new Node;
		hh[i] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
		--a[i];
		++cnt[a[i]];
		head[a[i]]->next = new Node(i);
		head[a[i]] = head[a[i]]->next;
		if (!i || a[i] != a[i - 1])
			++ans;
	}
	for (int i = 0; i < q; ++i)
	{
		int op;
		scanf("%d", &op);
		if (op == 2)
			printf("%d\n", ans);
		else
		{
			int x, y;
			scanf("%d%d", &x, &y);
			merge(y - 1, x - 1);
		}
	}
	return 0;
}
