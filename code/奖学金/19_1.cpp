// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;
using std::sort;

const int N = 100;
struct Student
{
	int id, chinese, sum;
	bool operator<(const Student &b)
	{
		return sum == b.sum ?
				   chinese == b.chinese ? id < b.id : chinese > b.chinese :
				   sum > b.sum;
	}
} student[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		scanf("%d%d%d", &student[i].chinese, &a, &b);
		student[i].id = i + 1;
		student[i].sum = student[i].chinese + a + b;
	}
	sort(student, student + n);
	for (int i = 0; i < min(5, n); ++i)
		printf("%d %d\n", student[i].id, student[i].sum);
	return 0;
}