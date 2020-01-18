#include <stdio.h>
#include <cstring>

char n[1000000],p[1000000];

void change(char *s) {
	int l=0,i=0;
	if (s[0]=='-') l=1;
	int k=l;
	while (s[k]=='0'&&s[k+1]&&s[k+1]!='.') k++;
	for (i=0;s[i+k];i++) s[i+l]=s[i+k];
	s[i+l]=s[i+k];
	k=i+l-1;
	for (i=0;s[i]&&s[i]!='.';i++);
	//printf("%d %d\n",k,i);
	if (s[i]=='.')
	   while (s[k]=='0') {
	   	s[k]='\0';
	   	k--;
	   }
    //printf("%s\n",s);
    if (s[k]=='.') s[k]='\0';
}

int main() {
	freopen("pvsnp.in","r",stdin); freopen("pvsnp.out","w",stdout);
	scanf("%s %s",n,p);
	change(n); change(p);
	if (!(strcmp(n,"1")&&strcmp(p,"0")&&strcmp(p,"-0"))) printf("True");
	else printf("False"); 
	return 0;
}
