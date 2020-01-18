// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::sort;

const int N = 100;
struct Student
{
	static const int LEN = 10;
	char id[LEN + 1];
	int k, age;
	bool operator<(const Student &b)
	{
		if (age >= 60 && b.age >= 60)
			return age == b.age ? k < b.k : age > b.age;
		if (age >= 60) return true;
		if (b.age >= 60) return false;
		return k < b.k;
	}
} student[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%d", student[i].id, &student[i].age);
		student[i].k = i;
	}
	sort(student, student + n);
	for (int i = 0; i < n; ++i) puts(student[i].id);
	return 0;
}