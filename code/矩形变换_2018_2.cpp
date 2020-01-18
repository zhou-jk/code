//VOJ 2018年寒假网赛第六场 B
#include <cstdio>

const int N=100,M=100; 
char map[N][M],tmp[M<<1];

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) scanf("%s",map[i]);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) tmp[j<<1]=tmp[(j<<1)|1]=map[j][i];
		puts(tmp); puts(tmp);
	}
	return 0;
}
