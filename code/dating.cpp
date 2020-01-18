#include <cstdio>
#include <algorithm>

using std::sort;
using std::min;

const int N=50;
struct Node
{
	char c;
	int k;
} s1[N],s2[N];
char s[N];
bool vis[N];

bool cmp(Node a,Node b)
{
	return a.c<b.c;
}

int main()
{
	freopen("dating.in","r",stdin); freopen("dating.out","w",stdout);
	int k,len,n,i,m,a=0,b=0,c=0,d=0;
	scanf("%s%d",s,&k);
	for (i=0; s[i]; i++)
		if ('a'<=s[i]&&s[i]<='z') s1[a++]= {s[i],i};
		else s2[b++]= {s[i],i};
	len=n=i; i--;
	sort(s1,s1+a,cmp); sort(s2,s2+b,cmp);
	m=min(a,b);
	if (!m)
	{
		puts("-1");
		return 0;
	}
	while (m--)
	{
		int tmp=(k-1)%len+1;
		do
		{
			i=(i+1)%n;
			if (!vis[i]) tmp--;
		}
		while (tmp);
		vis[i]=true;
		printf("%c",s[i]);
		if ('a'<=s[i]&&s[i]<='z')
		{
			while (vis[s2[d].k]) d++;
			vis[s2[d].k]=true;
			printf("%c ",s2[d].c);
			d++;
		}
		else
		{
			while (vis[s1[c].k]) c++;
			vis[s1[c].k]=true;
			printf("%c ",s1[c].c);
			c++;
		}
		len-=2;
	}
	return 0;
}