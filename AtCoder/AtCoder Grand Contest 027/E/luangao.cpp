#include <cstdio>
#include <cstring>
#include <algorithm>
#include<iostream>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=1e5+5,Mo=1e9+7;

int n,sum[N],f[N],nxt[N][3];
char s[N];

void inc(int &x,int y) {x=x+y>=Mo?x+y-Mo:x+y;}

int main() {
	scanf("%s",s+1);n=strlen(s+1);
	bool ok=0;
	fo(i,1,n-1) if (s[i]==s[i+1]) {ok=1;break;}
	if (!ok) {puts("1");return 0;}
	sum[0]=0;fo(i,1,n) sum[i]=(sum[i-1]+((s[i]=='a')?1:2))%3;
	fo(i,0,2) nxt[n][i]=n+1;
	fd(i,n-1,0) {
		fo(j,0,2) nxt[i][j]=nxt[i+1][j];
		nxt[i][sum[i+1]]=i+1;
	}
	f[0]=1;int ans=0;
	fo(i,0,n) {
		fo(j,1,2) inc(f[nxt[i][(sum[i]+j)%3]],f[i]),cerr<<"Add"<<i<<" "<<nxt[i][(sum[i]+j)%3]<<"\n";
		if (i&&sum[i]==sum[n]) inc(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}