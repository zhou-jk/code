// AC
#include <cstdio>

const int N = 5000;
bool a[N + 1];

int main()
{
	int n, m;
	bool flag = false;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
		for (int j = i; j <= n; j += i) a[j] = !a[j];
	for (int i = 1; i <= n; ++i)
		if (a[i])
		{
			if (flag) putchar(',');
			flag = true;
			printf("%d", i);
		}
	return 0;
}