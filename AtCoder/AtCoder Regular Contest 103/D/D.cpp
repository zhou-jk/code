#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1005;
int n;
int x[N],y[N];
vector<int>d;
int main()
{
	scanf("%d",&n);
	int c0=0,c1=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if((x[i]+y[i])%2==0) c0++;
		else c1++;
	}
	if(c0&&c1)
	{
		printf("-1");
		return 0;
	}
	if(c0) d.emplace_back(1);
	for(int i=30;i>=0;i--)
		d.emplace_back(1<<i);
	int m=d.size();
	printf("%d\n",m);
	for(int c:d)
		printf("%d ",c);
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		int nowx=x[i],nowy=y[i];
		for(int c:d)
			if(labs(nowx)>labs(nowy))
			{
				if(nowx>=0) nowx-=c,printf("R");
				else nowx+=c,printf("L");
			}
			else
			{
				if(nowy>=0) nowy-=c,printf("U");
				else nowy+=c,printf("D");
			}
		printf("\n");
	}
	return 0;
}
