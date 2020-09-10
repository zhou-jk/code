#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=15;
int n;
char s[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n&1)
	{
		printf("No");
		return 0;
	}
	for(int i=1;i<=n;i+=2)
		if(s[i]!='h'||s[i+1]!='i')
		{
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}
