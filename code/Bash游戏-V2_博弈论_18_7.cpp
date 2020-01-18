//51Nod-1067
#include <cstdio>

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		if (!(n%7)||n%7==2) puts("B");
		else puts("A");
	}
	return 0;
}