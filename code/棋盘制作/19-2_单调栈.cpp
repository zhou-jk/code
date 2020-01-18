#include <algorithm>
#include <cstdio>
#include <functional>
#include <utility>

using std::less;
using std::make_pair;
using std::max;
using std::min;
using std::pair;

const int N = 2000;
int a[N][N], f[N][N], g[N][N];
template <typename Cmp> class MonotoneStack
{
  public:
	MonotoneStack() : t(0) {}
	int push(int k, int num)
	{
		int ret = 0, tmp = k;
		while (!empty() && !cmp(top(), num))
		{
			tmp = stack[t - 1].first;
			ret = max(ret, pop(k));
		}
		stack[t] = make_pair(tmp, num);
		++t;
		return ret;
	}
	void pop()
	{
		if (!empty()) --t;
	}
	int pop(int k)
	{
		if (!empty())
		{
			--t;
			// printf("#%d %d %d\n", k, stack[t].first, stack[t].second);
			return (k - stack[t].first) * stack[t].second;
		}
		return -1;
	}
	bool empty() { return !t; }
	int top()
	{
		if (empty()) return -1;
		return stack[t - 1].second;
	}

  private:
	pair<int, int> stack[N + 2];
	int s[N + 2], t;
	Cmp cmp;
};

int main()
{
	int n, m, ans1 = 0, ans2 = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &a[i][j]);
			a[i][j] ^= (i + j) & 1;
			f[i][j] = j && a[i][j] ? f[i][j - 1] + 1 : a[i][j];
			if (i && j && a[i][j] == a[i - 1][j - 1] && a[i][j] == a[i - 1][j]
				&& a[i][j] == a[i][j - 1])
				g[i][j] =
					min(g[i - 1][j - 1], min(g[i - 1][j], g[i][j - 1])) + 1;
			else
				g[i][j] = 1;
			ans1 = max(ans1, g[i][j] * g[i][j]);
		}
	for (int i = 0; i < m; ++i)
	{
		MonotoneStack<less<int> > s;
		s.push(-1, 0);
		for (int j = 0; j < n; ++j) ans2 = max(ans2, s.push(j, f[j][i]));
		ans2 = max(ans2, s.push(n, 0));
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			a[i][j] = !a[i][j];
			f[i][j] = j && a[i][j] ? f[i][j - 1] + 1 : a[i][j];
		}
	for (int i = 0; i < m; ++i)
	{
		MonotoneStack<less<int> > s;
		s.push(-1, 0);
		for (int j = 0; j < n; ++j) ans2 = max(ans2, s.push(j, f[j][i]));
		ans2 = max(ans2, s.push(n, 0));
	}
	printf("%d\n%d", ans1, ans2);
	return 0;
}