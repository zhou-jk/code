// AC
#include <cstdio>

const int N = 1000;
int a[N], f[N], s[N], cnt;

int main()
{
	int ans = 0;
	for (int i = 0; scanf("%d", a + i) != EOF; ++i)
	{
		for (int j = 0; j < i; ++j)
			if (a[j] >= a[i] && f[j] > f[i]) f[i] = f[j];
		++f[i];
		if (f[i] > ans) ans = f[i];
		int k = -1;
		for (int j = 0; j < cnt; ++j)
			if (s[j] >= a[i] && (k == -1 || s[j] < s[k])) k = j;
		if (k == -1)
			s[cnt++] = a[i];
		else
			s[k] = a[i];
	}
	printf("%d\n%d", ans, cnt);
	return 0;
}