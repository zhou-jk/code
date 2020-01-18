//Virtual Judge 2018年寒假网赛第一场 C
#define N 1000

#include <cstdio>
#include <cstring>

int p[N],s[N],b[N],t,max;
char name[N][33],h[N][33];

int find(char *s) {
	for (int i=0;i<t;i++)
		if (!strcmp(s,h[i])) return i;
	strcpy(h[t++],s);
	return t-1;
}

int main() {
	int n,ans;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%s%d",name[i],&p[i]);
		int k=find(name[i]);
		s[k]+=p[i];
	}
	for (int i=0;i<t;i++)
		if (s[i]>max) max=s[i];
	for (int i=0;i<n;i++) {
		int k=find(name[i]);
		if (s[k]==max) {
			b[k]+=p[i];
			if (b[k]>=max) {
				printf("%s",name[i]);
				return 0;
			}
		}
	}
}
