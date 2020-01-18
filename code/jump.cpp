#include <cstdio>

const int R=750,C=750,D=1000000007;
int x[R][C],f[R][C];

int main() {
	//freopen("jump.in","r",stdin); freopen("jump.out","w",stdout);
	int r,c,k;
	scanf("%d%d%d",&r,&c,&k);
	for (int i=0;i<r;i++)
		for (int j=0;j<c;j++) scanf("%d",&x[i][j]);
	f[0][0]=1;
	for (int i=0;i<r;i++)
		for (int j=0;j<c;j++)
			for (int k=0;k<i;k++)
				for (int p=0;p<j;p++)
					if (x[i][j]!=x[k][p]) f[i][j]=(f[i][j]+f[k][p])%D;
	printf("%d",f[r-1][c-1]);
	return 0;
}
