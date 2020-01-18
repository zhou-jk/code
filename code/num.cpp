#include <cstdio>
#include <cstring>

const int LEN=2010;
char s[LEN+1];
int num[LEN+1],a[4]= {6,8,2,4},b[10]= {1,1,2,6,4,2,2,4,2,8};

int main()
{
	freopen("num.in","r",stdin); freopen("num.out","w",stdout);
	int t,len,tmp;
	scanf("%d",&t);
	while (t--)
	{
		tmp=0;
		scanf("%s",s);
		len=strlen(s);
		for (int i=0; s[i]; i++) num[i]=s[i]-'0';
		for (int i=0; i<len-1; i++) tmp=(tmp+num[i])%4;
		if (len>1) printf("%d\n",a[tmp]*b[num[len-1]]%10);
		else printf("%d\n",b[num[len-1]]);
	}
	return 0;
}