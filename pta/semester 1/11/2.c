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
	FILE *fout = fopen("result.dat", "wb");
	fwrite(a, sizeof(struct Student), n, fout);
	return 0;
}
