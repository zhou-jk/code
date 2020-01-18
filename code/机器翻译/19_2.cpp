// AC
#include <cstdio>
#include <queue>

using std::queue;

const int MAX = 1000;
bool vis[MAX + 1];
queue<int> q;

int main()
{
	int m, n, ans = 0;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		if (!vis[a])
		{
			++ans;
			vis[a] = true;
			q.push(a);
			if (q.size() > m)
			{
				vis[q.front()] = false;
				q.pop();
			}
		}
	}
	printf("%d", ans);
	return 0;
}