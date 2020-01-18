#include <cstdio>

const int N = 100000;
int f[N + 1], l[N + 1], len_lis, ans;

int find(int u)
{
	int l = 1, r = len_lis - 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (f[mid] >= u)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return r;
}

int main()
{
	freopen("lisagain.in", "r", stdin);
	freopen("lisagain.out", "w", stdout);
	int n, a;
	scanf("%d", &n);
	f[0] = -2000000000;
	scanf("%d", &f[1]);
	l[1] = 1;
	len_lis = 1;
	ans = 1;
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &a);
		if (a > f[len_lis])
			f[++len_lis] = a, l[len_lis] = ans = l[len_lis - 1];
		else
		{
			int tmp = find(a);
			//printf("%d\n",tmp);
			f[tmp + 1] = a;
			if (!tmp)
				l[tmp + 1] = i + 1;
			else
				l[tmp + 1] = l[tmp];
			ans += l[len_lis];
		}
	}
	printf("%d", ans);
	return 0;
}