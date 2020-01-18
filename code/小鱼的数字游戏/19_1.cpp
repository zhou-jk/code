// AC
#include <cstdio>

const int N = 100 + 1;
int a[N];

int main()
{
	int n = 0;
	do
	{
		scanf("%d", a + n);
		++n;
	} while (a[n - 1]);
	for (int i = n - 2; ~i; --i) printf("%d ", a[i]);
	return 0;
}