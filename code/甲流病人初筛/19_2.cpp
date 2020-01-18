// AC
#include <cstdio>

const int LEN = 8;

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		char name[LEN + 1];
		float t;
		int flag;
		scanf("%s%f%d", name, &t, &flag);
		if (flag && t >= 37.5)
		{
			puts(name);
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}