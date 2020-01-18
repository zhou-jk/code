// AC
#include <cstdio>

const int N = 15000;
int s[N + 1] = {0, 1};

int main()
{
	int k;
	scanf("%d", &k);
	for (int i = 2; i < (k | 1); i += 2)
		s[i - 1] = s[i - 2] + (s[i] = s[i >> 1]);
	printf("%d", s[k - 1]);
	return 0;
}
