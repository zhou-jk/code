#include <cstdio>

const int N = 200, NUM = 100000000;
int a[5][N], n;

bool find(int num)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (a[4][mid] > num)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return a[4][r] == num;
}

int main()
{
	freopen("zero.in", "r", stdin);
	freopen("zero.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				for (int p = 0; p < n; p++)
				{
					int sum = a[0][i] + a[1][j] + a[2][k] + a[3][p];
					if (sum >= -NUM && sum <= NUM)
						if (find(-sum))
						{
							puts("YES");
							return 0;
						}
				}
	puts("NO");
	return 0;
}