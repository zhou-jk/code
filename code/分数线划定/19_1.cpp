// AC
#include <algorithm>
#include <cstdio>

using std::sort;

const int N = 5000;
struct Student
{
	int id, score;
} student[N];

bool isScoreGreater(const Student &a, const Student &b)
{
	return a.score == b.score ? a.id < b.id : a.score > b.score;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &student[i].id, &student[i].score);
	sort(student, student + n, isScoreGreater);
	int k = m * 1.5 - 1, ans = 0;
	for (int i = 0; i < n && student[i].score >= student[k].score; ++i) ++ans;
	printf("%d %d\n", student[k].score, ans);
	for (int i = 0; i < n && student[i].score >= student[k].score; ++i)
		printf("%d %d\n", student[i].id, student[i].score);
	return 0;
}