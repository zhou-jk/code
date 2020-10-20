#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=105;
const char t[]=" keyence";
int n;
char s[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int i=1,a=1,j=n,b=7;
	while(s[i]==t[a]) i++,a++;
	while(s[j]==t[b]) j--,b--;
	if(a-1+1>=b+1) printf("YES");
	else printf("NO");
	return 0;
}
