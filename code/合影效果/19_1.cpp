// AC
#include <algorithm>
#include <cstdio>
#include <functional>

using std::greater;
using std::sort;

const int N = 40, LEN = 5;
double a[2][N];
int cnt[2];
char sex[LEN + 1];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		double tmp;
		scanf("%s%lf", sex, &tmp);
		a[sex[0] == 'f'][cnt[sex[0] == 'f']++] = tmp;
	}
	sort(a[0], a[0] + cnt[0]);
	sort(a[1], a[1] + cnt[1], greater<double>());
	for (int i = 0; i < cnt[0]; ++i) printf("%.2f ", a[0][i]);
	for (int i = 0; i < cnt[1]; ++i) printf("%.2f ", a[1][i]);
	return 0;
}