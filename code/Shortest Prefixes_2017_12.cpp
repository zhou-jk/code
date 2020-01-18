//Virtual Judge POJ 2001
#include <stdio.h>

int tt[200000][26],c[200000],t;
char s[1000][21];

void solve(char *s) {
	int k=0,i;
	for (i=0;s[i]&&c[k]>1;i++) {
		printf("%c",s[i]);
		k=tt[k][s[i]-'a'];
	}
	printf("\n");
}

void build(char *s) {
	int k=0;
	for (int i=0;s[i];i++) {
		int p=s[i]-'a';
		if (!tt[k][p]) tt[k][p]=++t;
		k=tt[k][p];
		c[k]++;
	}
}

int main() {
	int i; 
	for (i=0;scanf("%s",s[i])!=EOF;i++) build(s[i]);
	c[0]=10000;
	int n=i;
	for (i=0;i<n;i++) {
		printf("%s ",s[i]);
		solve(s[i]);
	}
	return 0;
}
