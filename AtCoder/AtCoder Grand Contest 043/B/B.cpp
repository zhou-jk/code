#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int n;
char s[N];
int a[N];
int cnt[3];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		a[i]=s[i]-'1';
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1) flag=true;
		cnt[a[i]]+=(((n-1)&(i-1))==(i-1));
	}
	if(cnt[1]&1) printf("1");
	else if(!flag&&(cnt[2]&1)) printf("2");
	else printf("0");
	return 0;
}
