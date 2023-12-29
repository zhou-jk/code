#include <stdio.h>

struct Student
{
	char name[20];
	int english, math, c, total;
};
int main()
{
	struct Student a[50];
	int n = 0;
	while (scanf("%s%d%d%d", a[n].name, &a[n].english, &a[n].math, &a[n].c) != EOF)
		a[n].total = a[n].english + a[n].math + a[n].c, n++;
	for (int i = 0; i < n; i++)
		for (int j = 0; j + 1 < n; j++)
			if (a[j].total < a[j + 1].total)
			{
				struct Student t = a[j];
				a[j] = a[j + 1], a[j + 1] = t;
			}
	FILE *fout = fopen("result.txt", "w");
	fprintf(fout, "         Name    English     Math       C        Total\n");
	for (int i = 0; i < n; i++)
		fprintf(fout, "%12s%12d%12d%12d%12d\n", a[i].name, a[i].english, a[i].math, a[i].c, a[i].total);
	return 0;
}
