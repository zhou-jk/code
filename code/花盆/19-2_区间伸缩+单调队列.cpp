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
using std::sort;

const int N = 100000;
pair<int, int> a[N];
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
	int n, d;
	scanf("%d%d", &n, &d);
	MonotoneQueue<less<int> > q1;
	MonotoneQueue<greater<int> > q2;
	int l = 0, ans = 100000000;
	for (int i = 0; i < n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
	{
		q1.push(a[i].first, a[i].second);
		q2.push(a[i].first, a[i].second);
		while (q2.top(a[l].first) - q1.top(a[l].first) >= d)
		{
			ans = min(ans, a[i].first - a[l].first);
			++l;
		}
	}
	printf("%d", ans == 100000000 ? -1 : ans);
	return 0;
}