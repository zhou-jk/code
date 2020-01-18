#include <cstdio>
#include <cstdlib>
#include <ctime>

const int M = 1000000000;

int main()
{
	freopen("bird.in", "w", stdout);
	srand(time(NULL));
	int n = rand() % 30 + 1;
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) printf("%d ", rand() % M + 1);
	return 0;
}