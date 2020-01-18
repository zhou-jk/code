//Virtual Judge POJ 3690
#include <stdio.h>
#include <cstring>

char s[1000][1001],c[50][51];
int time,tt[250000][2],tot;
short f[250000];

void build(char *c) {
	int k=0;
	for (int i=0;c[i];i++) {
		short p=c[i]=='*';
		if (!tt[k][p]) tt[k][p]=++tot;
		k=tt[k][p];
	}
}

unsigned char find(char *s,int p,int q) {
	
}

int main() {
	int n,m,t,p,q,a;
	while (scanf("%d %d %d %d %d",&n,&m,&t,&p,&q)&&(n||m||t||p||q)) {
		memset(tt,0,sizeof(tt));
		tot=0;
		for (int i=0;i<n;i++) scanf("%s",s[i]);
		for (int i=0;i<t;i++) {
			for (int j=0;j<p;j++) scanf("%s",c[j]);
			build(*c);
		}
		for (int i=0;i<n-p;i++)
			for (int j=0;j<n-q;j++) a+=find(&s[i][j],p,q);
	}
	return 0;
}
