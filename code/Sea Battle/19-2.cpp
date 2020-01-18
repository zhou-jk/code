#include <cstdio>

int main()
{
	int w1, h1, w2, h2;
	scanf("%d%d%d%d", &w1, &h1, &w2, &h2);
	if (w1 > w2)
		printf("%d\n",
			   (w1 + 2) * (h1 + h2 + 2) - (w1 - w2) * h2 - w1 * h1 - w2 * h2);
	else if (w1 == w2)
		printf("%d\n", (w1 + 2) * (h1 + h2 + 2) - w1 * (h1 + h2));
	else
		printf("%d\n",
			   (w2 + 2) * (h1 + h2 + 2) - (w2 - w1) * h1 - w1 * h1 - w2 * h2);
	return 0;
}