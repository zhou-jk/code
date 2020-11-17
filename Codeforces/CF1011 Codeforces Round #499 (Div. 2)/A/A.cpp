#include<iostream>
#include<cstdio>
using namespace std;
const int N=55;
int n,k;
char s[N];
int cnt[27];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		cnt[s[i]-'a'+1]++;
	int pre=-1,s=0;
	int ans=0;
	for(int i=1;i<=26;i++)
	{
		if(cnt[i]&&i-pre>1)
		{
			pre=i;
			s++;
			ans+=i;
		}
		if(s==k) break;
	}
	if(s==k) printf("%d",ans);
	else printf("-1");
	return 0;
}
