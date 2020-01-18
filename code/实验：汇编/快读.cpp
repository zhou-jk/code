#include <cstdio>

using namespace std;

const int maxn = 2 << 16;

char buffer[maxn], *S, *T;
char Get_Char()
{
	if (S == T)
	{
		T = (S = buffer) + fread(buffer, 1, maxn, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}

int Get_Int()
{
	char c;
	int re = 0;
	for (c = Get_Char(); c < '0' || c > '9'; c = Get_Char())
		;
	while (c >= '0' && c <= '9')
		re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
	return re;
}

int main()
{
	int a = Get_Int();
	printf("%d", a);
	return 0;
}