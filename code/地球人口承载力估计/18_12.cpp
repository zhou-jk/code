//AC
#include <cstdio>

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%.2lf",(double)(c*d-a*b)/(d-b)); //bx+y=ab dx+y=cd x=(cd-ab)/(d-b)
	return 0;
}
