//Virtual Judge HDU 1251
#include <stdio.h>
#include <cstring>

struct node {
	int c[26],s;
} tr[1000003];

int t;

void build(char *s) {
	int k=0,l=strlen(s);
	for (int i=0;i<l;i++) {
		int p=s[i]-'a';
		if (!tr[k].c[p]) tr[k].c[p]=++t;
		k=tr[k].c[p];
		tr[k].s++;
	}
}

int find(char *s) {
	int k=0,l=strlen(s);
	for (int i=0;i<l;i++) {
		int p=s[i]-'a';
		if (!tr[k].c[p]) return 0;
		k=tr[k].c[p];
	}
	return tr[k].s;
}

int main() {
	char s[11];
	while (gets(s)&&strlen(s)) build(s);
	while (gets(s)) printf("%d\n",find(s));
	return 0;
}
