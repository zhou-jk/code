// VOJ HDU 1711
#include <cstdio>

const int N = 1000000, M = 10000;
int a[N], b[M], next[M], n, m;

void make_next()
{
    next[0] = next[1] = 0;
    for (int i = 1, j = 0; i < m - 1; i++)
    {
	while (j && b[i] != b[j]) j = next[j];
	next[i + 1] = b[i] == b[j] ? ++j : 0;
    }
}

int match()
{
    for (int i = 0, j = 0; i < n; i++)
    {
	while (j && a[i] != b[j]) j = next[j];
	if (a[i] == b[j]) j++;
	if (j == m) return i - m + 1;
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	make_next();
	int tmp;
	printf("%d\n", (tmp = match()) < 0 ? tmp : tmp + 1);
    }
    return 0;
}