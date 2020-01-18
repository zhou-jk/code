// AC
#include <cstdio>

const int N = 100;
struct Student
{
	static const int LEN = 20;
	int score;
	char name[LEN + 1];
} student[N];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%s", &student[i].score, student[i].name);
		if (student[i].score > student[ans].score) ans = i;
	}
	printf("%s", student[ans].name);
	return 0;
}