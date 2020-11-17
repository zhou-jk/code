#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int a,b;
int main()
{
	scanf("%d%d",&a,&b);
	int k=0;
	for(int i=1;;i++)
		if(1LL*i*(i+1)/2<=a+b) k=max(k,i);
		else break;
	vector<int>d1,d2;
	for(int i=k;i>=1;i--)
		if(a>=i) d1.emplace_back(i),a-=i;
		else if(b>=i) d2.emplace_back(i),b-=i;
		else exit(1);
	int n=d1.size(),m=d2.size();
	printf("%d\n",n);
	for(int u:d1)
		printf("%d ",u);
	printf("\n");
	printf("%d\n",m);
	for(int u:d2)
		printf("%d ",u);
	return 0;
}
