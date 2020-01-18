// AC
#include <cstdio>

const int LEN = 6, P = 47;
char a[LEN + 1], b[LEN + 1];

int main()
{
	int tmp1 = 1, tmp2 = 1;
	scanf("%s%s", a, b);
	for (int i = 0; a[i]; ++i) tmp1 = tmp1 * (a[i] - 'A' + 1) % P;
	for (int i = 0; b[i]; ++i) tmp2 = tmp2 * (b[i] - 'A' + 1) % P;
	puts(tmp1 == tmp2 ? "GO" : "STAY");
	return 0;
}