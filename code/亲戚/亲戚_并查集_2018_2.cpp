// AC
#include <cstdio>

const int N = 20000;
struct Dsu
{
	int fa[N];
	Dsu(int n)
	{
		for (int i = 0; i < n; i++) fa[i] = i;
	}
	int get_root(int k) { return k == fa[k] ? k : get_root(fa[k]); }
	void merge(int x, int y) { fa[get_root(x)] = get_root(y); }
	bool is_same(int x, int y) { return get_root(x) == get_root(y); }
};

int main()
{
	int n, m, x, y, p;
	scanf("%d", &n);
	Dsu f(n);
	for (scanf("%d", &m); m; m--)
	{
		scanf("%d%d", &x, &y);
		f.merge(x - 1, y - 1);
	}
	for (scanf("%d", &p); p; p--)
	{
		scanf("%d%d", &x, &y);
		if (f.is_same(x - 1, y - 1))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
