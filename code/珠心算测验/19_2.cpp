// AC
#include <cstdio>

const int N = 100;
int a[N];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 0; i < n; ++i)
	{
		bool flag = false;
		for (int j = 0; j < n; ++j)
		{
			for (int k = j + 1; k < n; ++k)
				if (a[j] + a[k] == a[i])
				{
					flag = true;
					break;
				}
			if (flag) break;
		}
		if (flag) ++ans;
	}
	printf("%d", ans);
	return 0;
}