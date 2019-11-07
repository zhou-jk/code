#include<iostream>
#include<cstdio>
const int N=1000000;
int n;
bool a[1000001];
int main()
{
	for(int i=2;i<=N/2;i++)
		if(!a[i])
			for(int j=2*i;j<=N;j+=i) a[j]=true;
	while(1)
	{
		bool flag=false;
        scanf("%d",&n);
		if(n==0) return 0;
		for(int i=3;i<=N/2;i++)
			if(a[i]==0&&a[n-i]==0)
			{
				printf("%d = %d + %d\n",n,i,n-i);
                flag=true;
                break;
			}
		if(!flag) printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}