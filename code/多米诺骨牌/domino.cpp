// AC
#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("domino.in", "r", stdin);
	freopen("domino.out", "w", stdout);
	int n, c = 0, d = 0;
	bool flag = false;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if ((a & 1) ^ (b & 1)) flag = true;
		c ^= a & 1;
		d ^= b & 1;
	}
	if (c ^ d)
		puts("-1");
	else if (c)
	{
		if (flag)
			puts("1");
		else
			puts("-1");
	}
	else
		puts("0");
	return 0;
}
