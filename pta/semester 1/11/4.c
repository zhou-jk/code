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
	FILE *fin = fopen("student.dat", "rb");
	while (fread(a[n].name, sizeof(char), 20, fin))
	{
		fread(&a[n].english, sizeof(int), 1, fin);
		fread(&a[n].math, sizeof(int), 1, fin);
		fread(&a[n].c, sizeof(int), 1, fin);
		fread(&a[n].total, sizeof(int), 1, fin);
		n++;
	}
	fclose(fin);
	for (int i = 0; i < n; i++)
		for (int j = 0; j + 1 < n; j++)
			if (a[j].english < a[j + 1].english)
			{
				struct Student t = a[j];
				a[j] = a[j + 1], a[j + 1] = t;
			}
	printf("         Name    English     Math       C        Total\n");
	for (int i = 0; i < n; i++)
		printf("%12s%12d%12d%12d%12d\n", a[i].name, a[i].english, a[i].math, a[i].c, a[i].total);
	return 0;
}
