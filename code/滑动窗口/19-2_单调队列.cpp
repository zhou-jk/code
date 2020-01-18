#include <cstdio>
#include <deque>
#include <functional>
#include <utility>

using std::deque;
using std::greater;
using std::less;
using std::make_pair;
using std::pair;
using std::printf;
using std::scanf;

const int N = 1000000;
int s[N];
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
	int n, m;
	scanf("%d%d", &n, &m);
	MonotoneQueue<less<int> > q1;
	MonotoneQueue<greater<int> > q2;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		q1.push(i, a);
		q2.push(i, a);
		if (i >= m - 1)
		{
			printf("%d ", q1.top(i - m + 1));
			s[i] = q2.top(i - m + 1);
		}
	}
	putchar('\n');
	for (int i = m - 1; i < n; ++i) printf("%d ", s[i]);
	return 0;
}