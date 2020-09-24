#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=20;
int n;
char s[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='x') cnt++;
	if(15-cnt>=8) printf("YES");
	else printf("NO");
	return 0;
}
