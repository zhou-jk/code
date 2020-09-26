#include<iostream>
#include<cstdio>
using namespace std;
const int N=3005;
int R,G,B,n;
int main()
{
	scanf("%d%d%d%d",&R,&G,&B,&n);
	int ans=0;
	for(int r=0;r*R<=n;r++)
		for(int g=0;r*R+g*G<=n;g++)
		{
			int ret=n-r*R-g*G;
			if(ret%B==0) ans++;
		}
	printf("%d",ans);
	return 0;
}
