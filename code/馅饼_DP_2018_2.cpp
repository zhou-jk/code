//Virtual Judge 2018年寒假网赛第三场 G
#define T 100001
#define X 11
#define oo 1E9

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int s[T][X],f[T][X];

int main() {
	int n,x,t,max_t,ans;
	while (~scanf("%d",&n)&&n) {
		memset(s,0,sizeof s);
		max_t=ans=0;
		for (;n;n--) {
			scanf("%d%d",&x,&t);
			s[t][x]++;
			max_t=max(max_t,t);
		}
		for (int i=0;i<X;i++) f[0][i]=-oo;
		f[0][5]=0;
		for (int i=1;i<=max_t;i++) {
			f[i][0]=max(f[i-1][0],f[i-1][1])+s[i][0];
			for (int j=1;j<X-1;j++) f[i][j]=max(max(f[i-1][j-1],f[i-1][j+1]),f[i-1][j])+s[i][j];
			f[i][X-1]=max(f[i-1][X-1],f[i-1][X-2])+s[i][X-1];
		}
		for (int i=0;i<X;i++) ans=max(ans,f[max_t][i]);
		printf("%d\n",ans);
	}
	return 0;
}
