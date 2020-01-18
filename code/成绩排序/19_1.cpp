// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::sort;

const int N = 100;
struct Student
{
	static const int LEN = 20;
	char name[LEN + 1];
	int score;
	bool operator<(const Student &b)
	{
		return score == b.score ? strcmp(name, b.name) < 0 : score > b.score;
	}
} student[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s%d", student[i].name, &student[i].score);
	sort(student, student + n);
	for (int i = 0; i < n; ++i)
		printf("%s %d\n", student[i].name, student[i].score);
	return 0;
}