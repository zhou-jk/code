// AC
#include <cstdio>

const int N = 1000;
int s[N], cnt;

int main()
{
	int a;
	while (scanf("%d", &a) != EOF)
	{
		int k = -1;
		for (int j = 0; j < cnt; ++j)
			if (s[j] >= a && (k == -1 || s[j] < s[k])) k = j;
		if (k == -1)
			s[cnt++] = a;
		else
			s[k] = a;
	}
	printf("%d", cnt);
	return 0;
}