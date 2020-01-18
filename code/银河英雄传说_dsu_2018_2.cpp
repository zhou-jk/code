//Ве№И 1196 
#include <cstdio>
#include <cmath>

using namespace std;

const int N=30000;
struct Dsu{
	int fa[N],d[N],sum[N];
	Dsu(int n) {
		for (int i=0;i<n;i++) fa[i]=i,d[i]=0,sum[i]=1;
	}
	int get_root(int k) {
		if (k==fa[k]) return k;
		int tmp=fa[k];
		fa[k]=get_root(fa[k]);
		d[k]+=d[tmp];
		return fa[k];
	}
	void merge(int x,int y) {
		int root_x=get_root(x),root_y=get_root(y);
		if (root_x!=root_y) {
			fa[root_x]=root_y;
			d[root_x]=sum[root_y];
			sum[root_y]+=sum[root_x];
		}
	}
	bool is_same(int x,int y) {
		return get_root(x)==get_root(y);
	}
};

int main() {
	int m,x,y;
	Dsu f(N);
	char c[2];
	for (scanf("%d",&m);m;m--) {
		scanf("%s%d%d",c,&x,&y);
		x--; y--;
		if (c[0]=='M') f.merge(x,y);
		else if (f.is_same(x,y)) printf("%d\n",(int)abs(f.d[x]-f.d[y])-1);
		else puts("-1");
	}
	return 0; 
}
