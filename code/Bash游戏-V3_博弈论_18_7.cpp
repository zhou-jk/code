//51Nod-1068
#include <cstdio>

const int LEN=1000;
char n[LEN+1];

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int tmp=0;
		scanf("%s",n);
		for (int i=0; n[i]; ++i) tmp=((tmp<<3)+(tmp<<1)+(n[i]^48))%3;
		if (tmp) puts("A");
		else puts("B");
	}
	return 0;
}