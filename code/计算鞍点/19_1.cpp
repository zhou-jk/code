// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int N = 5;
int a[N][N], s1[N];

int main()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &a[i][j]);
			s1[i] = max(s1[i], a[i][j]);
		}
	bool flag = true;
	for (int i = 0; i < N; ++i)
	{
		int s2 = 0;
		for (int j = 1; j < N; ++j)
			if (a[j][i] < a[s2][i]) s2 = j;
		if (a[s2][i] == s1[s2])
		{
			printf("%d %d %d\n", s2 + 1, i + 1, a[s2][i]);
			flag = false;
		}
	}
	if (flag) puts("not found");
	return 0;
}