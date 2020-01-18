// AC
#include <algorithm>
#include <cstdio>

using std::sort;

const int N = 100;
struct Student
{
	int id;
	double score;
} student[N];

bool isScoreGreater(Student &a, Student &b)
{
	return a.score > b.score;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d%lf", &student[i].id, &student[i].score);
	sort(student, student + n, isScoreGreater);
	printf("%d %g", student[k - 1].id, student[k - 1].score);
	return 0;
}