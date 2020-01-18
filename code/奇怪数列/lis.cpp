// AC
#include <cstdio>
#include <cstring>

const int N = 30000;
int s[N] = {0, 1}, s1[N], len = 2;

int main()
{
	freopen("lis.in", "r", stdin);
	freopen("lis.out", "w", stdout);
	int k;
	scanf("%d", &k);
	while (len < k)
	{
		for (int i = 1; i < len; ++i) s1[(i << 1) - 1] = s[i - 1] + s[i];
		for (int i = 0; i < len; ++i) s1[i << 1] = s[i];
		len += len - 1;
		memcpy(s, s1, len * sizeof s[0]);
	}
	printf("%d", s[k - 1]);
	// puts("");
	// for (int i = 0; i < len; ++i) printf("%d ", s[i]);
	return 0;
}