#define LEN 100

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int M=LEN+1,N=M*10*10;
struct Node{
	int i,j,k;
} q[N];
int d[M][10][10],n,l,r;
bool vis[M][10][10];

void update(int i,int j,int k,int i1,int j1,int k1) {
	if (j1<0||k1>9||j1>=k1) return;
	if (d[i][j][k]+1<d[i1][j1][k1]) {
		d[i1][j1][k1]=d[i][j][k]+1;
		if (!vis[i1][j1][k1]) {
			q[r]=Node{i1,j1,k1};
			r=(r+1)%N;
			vis[i1][j1][k1]=true;
		}
	}
}

int main() {
	char s[M];
	int num[LEN];
	freopen("button.in","r",stdin); freopen("button.out","w",stdout);
	while (gets(s)) {
		n=strlen(s);
		for (int i=0;i<n;i++) num[i]=(s[i]-'0'+9)%10;
		l=0; r=1; q[0]=Node{0,4,5};
		memset(d,127,sizeof d); d[0][4][5]=0;
		memset(vis,false,sizeof vis); vis[0][4][5]=true;
		int t1=0,t2=4,t3=5;
		while (vis[t1][t2][t3]) {
			//printf("%d %d %d\n",t1,t2,t3);
			vis[t1][t2][t3]=false;
			for (int i=-1;i<2;i++)
				for (int j=-1;j<2;j++) update(t1,t2,t3,t1,t2+i,t3+j);
			if (t1<n) {
				if (t2==num[t1])
					for (int i=-1;i<2;i++) update(t1,t2,t3,t1+1,t2,t3+i);
				if (t3==num[t1])
					for (int i=-1;i<2;i++) update(t1,t2,t3,t1+1,t2+i,t3);
			}
			l=(l+1)%N;
			t1=q[l].i; t2=q[l].j; t3=q[l].k;
		}
		int ans=0x3fffffff;
		for (int i=0;i<10;i++)
			for (int j=0;j<10;j++) ans=min(ans,d[n][i][j]);
		printf("%d\n",ans);
	}
	return 0;
}
