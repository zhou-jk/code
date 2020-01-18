// AC
#include <algorithm>
#include <cstdio>

using std::swap;

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) && a && b)
	{
		bool ans = true;
		if (a < b) swap(a, b);
		while (a / b == 1)
		{
			a -= b;
			swap(a, b);
			ans = !ans;
		}
		puts(ans ? "win" : "lose");
	}
	return 0;
}