#include <cstdio>

const int D=1337;
int sum,num[10],s,
    a[11]= {1337,548,866,892,64,1303,97,1278,1278,960,934},
           b[11]= {1,1,-1,-1,1,1,-1,1,-1,1,1};

int main()
{
	freopen("seven.in","r",stdin); freopen("seven.out","w",stdout);
	int x,k,j,add,t;
	bool tmp;
	t=x/100000000;
	scanf("%d",&x);
	k=a[t]; add=b[t];
	num[8]=t; x%=100000000;
	if (num[8]==7) s++;
	for (int i=0; i<x; i++)
	{
		k+=add;
		sum++;
		tmp=false;
		if (sum==7)
		{
			sum=0;
			tmp=true;
		}
		j=0;
		num[j]++;
		while (num[j]>9)
		{
			num[j]=0;
			num[++j]++;
		}
		if (num[j]==8) s--;
		if (num[j]==7) s++;
		if (tmp||s) add=-add; //直接写这里的话，check1为true时check2就不会运行
	}
	k%=D;
	if (k<=0) k+=D;
	printf("%d",k);
	return 0;
}