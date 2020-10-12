#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n;
char s[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int R=0,B=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='R') R++;
		else if(s[i]=='B') B++;
	if(R>B) printf("Yes");
	else printf("No");
	return 0;
}
