//Virtual Judge POJ 3630
#include <stdio.h>
#include <cstring>

int tt[100001][10],c;
bool e[100001];

bool build(char *s) {
	//printf("&&");
	int k=0,l=strlen(s);
	bool b=true; 
	for (int i=0;i<l;i++) {
		int p=s[i]-'0';
		if (!tt[k][p]) {
			tt[k][p]=++c;
			b=false; 
		}
		k=tt[k][p];
		if (e[k]) return true;
	}
	e[k]=true;
	return b;
}

int main() {
	char s[11];
	int t,n;
	bool f;
	for (scanf("%d",&t);t;t--) {
		memset(tt,0,sizeof(tt)); memset(e,0,sizeof(e));
		f=true; c=0;
		for (scanf("%d",&n);n;n--) {
			scanf("%s",s);
			if (f&&build(s)) {
				printf("NO\n");
				f=false;
			}
		}
		if (f) printf("YES\n");
	}
	return 0;
}
