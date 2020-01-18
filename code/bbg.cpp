#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char a[10001],b[10001],c[10001],d[10001];
short f[17][6][4][3];
//int ma,mb,mc,md; 

short mod(char *s,short m) {
	short t=0;
	for (int i=0;s[i];i++) t=(t*10+s[i]-'0')%m;
	//printf("%d %d\n",t,m);
	return t;
}

short dfs(short a,short b,short c,short d) {
	if (a<0||b<0||c<0||d<0) return 1;
	if (!(a||b||c||d)) return 0;
	//ma=max(ma,(int)a); mb=max(mb,(int)b); mc=max(mc,(int)c); md=max(md,(int)d);
	if (f[a][b][c][d]!=-1) return f[a][b][c][d];
	bool t=1;
	t=t&&dfs(a+2,b-1,c,d);
	if (!t) {
	    f[a][b][c][d]=1;
	    return 1;
	}
	t=t&&dfs(a+1,b+1,c-1,d);
	if (!t) {
        f[a][b][c][d]=1;
	    return 1;
	}
	t=t&&dfs(a+1,b,c+1,d-1);
	if (!t) {
		f[a][b][c][d]=1;
		return 1;
	}
	t=t&&dfs(a,b+2,c,d-1);
	if (!t) {
		f[a][b][c][d]=1;
		return 1;
	}
	t=t&&dfs(a-1,b,c,d);
	if (!t) {
		f[a][b][c][d]=1;
		return 1;
	}
	t=t&&dfs(a,b-2,c,d);
	if (!t) {
		f[a][b][c][d]=1;
		return 1;
	}
	t=t&&dfs(a,b,c-3,d);
	if (!t) {
		f[a][b][c][d]=1;
		return 1;
	}
	t=t&&dfs(a,b,c,d-4);
	if (!t) {
		f[a][b][c][d]=1;
		return 1;
	}
	f[a][b][c][d]=0;
	return 0;
}

int main() {
	//printf("**"); 
	freopen("bbg.in","r",stdin);
	//printf("&&"); 
	freopen("bbg.out","w",stdout);
	//printf("^^"); 
	memset(f,-1,sizeof(f));
	//printf("%d\n",f[0][0][0][0]);
	int t,a1,b1,c1,d1;
	scanf("%d",&t);
	//printf("%d",t); 
	for (short i=0;i<t;i++) {
		scanf("%s %s %s %s",a,b,c,d);
		//printf("%s %s %s %s",a,b,c,d);
		a1=mod(a,2); b1=mod(b,3); c1=mod(c,2); d1=mod(d,3);
		printf("%d\n",dfs(a1,b1,c1,d1));
		//printf("%d %d %d %d\n",a1,b1,c1,d1);
		//printf("%d %d %d %d\n",ma,mb,mc,md);
	}
	return 0;
}
