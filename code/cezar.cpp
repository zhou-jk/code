#include <stdio.h>
#include <string.h>

int t[12];
int n,i,m,x,y,z;
char s[3];

int main() {
	freopen("cezar.in","r",stdin); freopen("cezar.out","w",stdout);
	scanf("%d",&n);
	for (i=2;i<=9;i++) t[i]=4;
	t[10]=16; t[11]=4; x=21;
	for (i=1;i<=n;i++) {
		scanf("%s",&s);
		if (!(strcmp(s,"10")&&strcmp(s,"J")&&strcmp(s,"Q")&&strcmp(s,"K"))) m=10;
		else if (!(strcmp(s,"A")&&strcmp(s,"11"))) m=11;
		     else m=int(s[0])-int('0');
        t[m]--; x-=m;
	}
	for (i=2;i<=x;i++) y+=t[i];
	for (i=x+1;i<=11;i++) z+=t[i];
	if (z>=y) printf("DOSTA");
	else printf("VUCI");
	return 0;
}
