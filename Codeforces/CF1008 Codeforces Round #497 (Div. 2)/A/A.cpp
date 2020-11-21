#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=105;
int n;
char s[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='n')
		{
			if(s[i+1]!='a'&&s[i+1]!='e'&&s[i+1]!='i'&&s[i+1]!='o'&&s[i+1]!='u')
			{
				printf("NO");
				return 0;
			}
		}
	printf("YES");
	return 0;
}
