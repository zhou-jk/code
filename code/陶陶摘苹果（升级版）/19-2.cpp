// AC
#include <algorithm>
#include <cstdio>

using std::sort;

const int N = 5000;
struct Apple
{
	int h, v;
} apple[N];

bool cmp(Apple a, Apple b)
{
	return a.v < b.v;
}

int main()
{
	int n, s, a, b, ans = 0;
	scanf("%d%d%d%d", &n, &s, &a, &b);
	for (int i = 0; i < n; ++i) scanf("%d%d", &apple[i].h, &apple[i].v);
	sort(apple, apple + n, cmp);
	for (int i = 0; i < n; ++i)
	{
		if (s < apple[i].v) break;
		if (apple[i].h <= a + b)
		{
			++ans;
			s -= apple[i].v;
		}
	}
	printf("%d", ans);
	return 0;
}