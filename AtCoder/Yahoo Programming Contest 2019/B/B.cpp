#include<iostream>
#include<cstdio>
using namespace std;
const int N=5;
int n;
int deg[N];
int main()
{
	n=4;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		deg[x]++,deg[y]++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(deg[i]>2||deg[i]==0)
		{
			printf("NO");
			return 0;
		}
		else if(deg[i]==1) cnt++;
	if(cnt==2) printf("YES");
	else printf("NO");
	return 0;
}
