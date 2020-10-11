#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int h,w,n;
int sr,sc;
char s[N],t[N];
int main()
{
	scanf("%d%d%d",&h,&w,&n);
	scanf("%d%d",&sr,&sc);
	scanf("%s",s+1);
	scanf("%s",t+1);
	int lr=1,rr=h;
	for(int i=n;i>=1;i--)
	{
		if(t[i]=='U') rr++;
		else if(t[i]=='D') lr--;
		if(lr>rr)
		{
			printf("NO");
			return 0;
		}
		lr=max(lr,1),lr=min(lr,h);
		rr=max(rr,1),rr=min(rr,h);
		if(s[i]=='U') lr++;
		else if(s[i]=='D') rr--;
		if(lr>rr)
		{
			printf("NO");
			return 0;
		}
		lr=max(lr,1),lr=min(lr,h);
		rr=max(rr,1),rr=min(rr,h);
	}
	int lc=1,rc=w;
	for(int i=n;i>=1;i--)
	{
		if(t[i]=='L') rc++;
		else if(t[i]=='R') lc--;
		if(lc>rc)
		{
			printf("NO");
			return 0;
		}
		lc=max(lc,1),lc=min(lc,w);
		rc=max(rc,1),rc=min(rc,w);
		if(s[i]=='L') lc++;
		else if(s[i]=='R') rc--;
		if(lc>rc)
		{
			printf("NO");
			return 0;
		}
		lc=max(lc,1),lc=min(lc,w);
		rc=max(rc,1),rc=min(rc,w);
	}
	if(lr<=sr&&sr<=rr&&lc<=sc&&sc<=rc) printf("YES");
	else printf("NO");
	return 0;
}
