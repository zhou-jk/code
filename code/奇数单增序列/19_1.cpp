// AC
#include <algorithm>
#include <cstdio>

using std::sort;

const int N = 500;
int a[N];

int main()
{
	int n;
	bool flag = false;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
		if (a[i] & 1)
		{
			if (flag) putchar(',');
			flag = true;
			printf("%d", a[i]);
		}
	return 0;
}