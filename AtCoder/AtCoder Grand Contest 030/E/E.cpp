#include<iostream>
#include<cstdio>
using namespace std;
const int N=5005;
const int INF=1061109567;
int n;
char s[N],t[N];
int a[N],b[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	int tota=0,totb=0;
	for(int i=1;i<n;i++)
		if(s[i]!=s[i+1]) a[++tota]=i;
	for(int i=1;i<n;i++)
		if(t[i]!=t[i+1]) b[++totb]=i;
	int ans=INF;
	for(int i=-tota-1;i<=totb+1;i++)
		if((i&1)^(s[1]==t[1]))
		{
			int res=0;
			for(int j=min(1,1-i);j<=max(tota,totb-i);j++)
				res+=abs(((j<0)?0:((j>tota)?n:a[j]))-((j+i<0)?0:((j+i>totb)?n:b[j+i])));
			ans=min(ans,res);
		}
	printf("%d",ans);
	return 0;
}

