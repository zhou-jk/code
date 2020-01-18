#include <cstdio>
#include <cstring>

const int LEN = 500;
char s1[LEN + 1], s2[LEN + 1];

int main()
{
	double a;
	scanf("%lf%s%s", &a, s1, s2);
	int len = strlen(s1), ans = 0;
	for (int i = 0; i < len; ++i) ans += s1[i] == s2[i];
	puts((double)ans / len >= a ? "yes" : "no");
	return 0;
}