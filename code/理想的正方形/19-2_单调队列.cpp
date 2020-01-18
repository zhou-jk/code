// AC
#include <algorithm>
#include <cstdio>
#include <deque>
#include <functional>
#include <utility>

using std::deque;
using std::greater;
using std::less;
using std::make_pair;
using std::min;
using std::pair;
using std::printf;
using std::scanf;

const int N = 1000;
int f[N][N], g[N][N];
template <typename Cmp> class MonotoneQueue : deque<pair<int, int> >
{
  public:
	void push(const int k, const int num)
	{
		while (!empty() && !cmp(back().second, num)) pop_back();
		push_back(make_pair(k, num));
	}
	void pop(const int l)
	{
		update(l);
		pop_front();
	}
	int top(const int l)
	{
		update(l);
		return front().second;
	}

  private:
	Cmp cmp;

	void update(const int l)
	{
		while (!empty() && front().first < l) pop_front();
	}
};

int main()
{
	int n, m, l, ans = 1E9;
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 0; i < n; ++i)
	{
		MonotoneQueue<less<int> > q1;
		MonotoneQueue<greater<int> > q2;
		for (int j = 0; j < m; ++j)
		{
			int a;
			scanf("%d", &a);
			q1.push(j, a);
			f[i][j] = q1.top(j - l + 1);
			q2.push(j, a);
			g[i][j] = q2.top(j - l + 1);
		}
	}
	for (int i = l - 1; i < m; ++i)
	{
		MonotoneQueue<less<int> > q1;
		MonotoneQueue<greater<int> > q2;
		for (int j = 0; j < n; ++j)
		{
			q1.push(j, f[j][i]);
			q2.push(j, g[j][i]);
			if (j >= l - 1)
				ans = min(ans, q2.top(j - l + 1) - q1.top(j - l + 1));
		}
	}
	printf("%d", ans);
	return 0;
}