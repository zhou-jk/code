//codevs 1729
#include <stdio.h>
#include <cstring>

int t[40000][26];
int c;

void build(char *s) {
	int k=1;
	for (int i=0;i<strlen(s);i++) {
		int p=s[i]-'A';
		if (t[k][p]) k=t[k][p];
		else {
        	 t[k][p]=++c;
        	 k=c;
		}
    }
}

int main() {
	char s[64];
	c=1;
	while (scanf("%s",&s)!=EOF) build(s);
	printf("%d",c);
	return 0;
}
