// AC
#include <cstdio>
#include <cstring>

const int P = 100;
bool f[P], g[P];

int main()
{
	int n, p;
	scanf("%d%d", &n, &p);
	g[0] = true;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		memset(f, false, p);
		for (int j = 0; j < p; ++j)
			if (g[j]) f[(j + a) % p] = f[((j - a) % p + p) % p] = true;
		memcpy(g, f, p);
	}
	puts(f[0] ? "YES" : "NO");
	return 0;
}