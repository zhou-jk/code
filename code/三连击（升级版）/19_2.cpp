// AC
#include <algorithm>
#include <cstdio>

using std::next_permutation;

int aa[9];

int dd(int k)
{
	return aa[k] * 100 + aa[k + 1] * 10 + aa[k + 2];
}

int main()
{
	int a, b, c, ans = 0;
	scanf("%d%d%d", &a, &b, &c);
	int a1 = b * c, b1 = a * c, c1 = a * b;
	for (int i = 0; i < 9; ++i) aa[i] = i + 1;
	do
	{
		int tmp1 = dd(0), tmp2 = dd(3), tmp3 = dd(6);
		if (tmp1 * a1 == tmp2 * b1 && tmp2 * b1 == tmp3 * c1)
		{
			printf("%d %d %d\n", tmp1, tmp2, tmp3);
			++ans;
		}
	} while (next_permutation(aa, aa + 9));
	if (!ans) puts("No!!!");
	return 0;
}