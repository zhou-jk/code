// AC
#include <cstdio>

const int M = 5000;
bool vis[M + 1];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		if (!vis[a])
		{
			vis[a] = true;
			printf("%d ", a);
		}
	}
	return 0;
}