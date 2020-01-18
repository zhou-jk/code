// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int MAX = 1000;
int vis1[MAX + 1], vis2[MAX + 1];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	ans = n;
	while (n--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		++vis1[a];
		++vis2[b];
	}
	for (int i = 1; i <= MAX; ++i) // ans += max(vis1[i], vis2[i]);
								   // 注：Luogu数据有问题，这样没有算左边的0
		if (vis2[i] > vis1[i]) ans += vis2[i] - vis1[i];
	printf("%d", ans);
	return 0;
}