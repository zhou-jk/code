#include <cstdio>
#include <cstdlib>

int e = 1, f = 2;

inline int x(int a, int b)
{
	return a + b;
}

int main()
{
	int a = 3, b = 4, c = 0;
	a = e + f;
	b = x(e, f);
	printf("%d %d %d", a, b, c);
	system("pause");
	return 0;
}