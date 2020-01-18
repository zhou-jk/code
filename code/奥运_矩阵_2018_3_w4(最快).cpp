//VOJ HDU 2254
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int N=30;
map<unsigned int,int> hash_table;
int id,nn,d=2008;

inline int hash_(unsigned int u) {
	if (hash_table.find(u)!=hash_table.end()) return hash_table[u];
	return hash_table[u]=++id;
}

struct Matrix
{
	int mat[N][N];
	void init(const int num=0)
	{
		memset(mat,0,sizeof mat);
		for (int i=0;i<id;i++) mat[i][i]=num;
	}
	Matrix operator+(const Matrix &b)
	{
		Matrix r;
		for (int i=0;i<id;i++)
			for (int j=0;j<id;j++) r.mat[i][j]=(mat[i][j]+b.mat[i][j])%d;
		return r;
	}
	inline void operator+=(const Matrix &b)
	{
		(*this)=(*this)+b;
	}
	Matrix operator*(const Matrix &b)
	{
		Matrix r;
		r.init();
		for (int i=0;i<id;i++)
			for (int k=0;k<id;k++)
				if (mat[i][k])
					for (int j=0;j<id;j++)
						r.mat[i][j]=(r.mat[i][j]+mat[i][k]*b.mat[k][j])%d;
		return r;
	}
	inline void operator*=(const Matrix &b)
	{
		(*this)=(*this)*b;
	}
} mat,e,ans;


inline void solve(const int k) {
	if (k==0) return;
	solve(k>>1);
	ans+=ans*e;
	e*=e;
	if (k&1) {
		e*=mat;
		ans+=e;
	}
}

inline Matrix sum(const int k) {
	ans.init(); e.init(1);
	solve(max(k,0));
	return ans;
}

int main()
{
	int n,k,t1,t2;
	unsigned int u,v,s,t;
	while (scanf("%d",&n)!=EOF)
	{
		hash_table.clear(); id=0;
		mat.init();
		for (int i=0;i<n;i++) {
			scanf("%d%d",&u,&v);
			mat.mat[hash_(u)-1][hash_(v)-1]++;
		}
		scanf("%d",&k);
		for (int i=0;i<k;i++) {
			scanf("%d%d%d%d",&s,&t,&t1,&t2);
			if (!(s=hash_table[s])||!(t=hash_table[t])) {
				puts("0");
				continue;
			}
			s--; t--;
			if (t1>t2) swap(t1,t2);
			printf("%d\n",(sum(t2).mat[s][t]-sum(t1-1).mat[s][t]+2008)%2008);
		}
	}
	return 0;
}