#include<iostream>
#include<cstdio>
using namespace std;
int m,d;
int main()
{
	scanf("%d%d",&m,&d);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		for(int d10=2;d10<=d/10;d10++)
			if(i%d10==0)
			{
				int d1=i/d10;
				if(d1>=2&&d1<=9&&d10*10+d1<=d) ans++;
			}
	}
	printf("%d",ans);
	return 0;
}
