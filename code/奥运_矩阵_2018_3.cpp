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
	Matrix(const int num=0)
	{
		memset(mat,0,sizeof mat);
		for (int i=0;i<id;i++) mat[i][i]=num;
	}
	Matrix operator+(const Matrix &b)
	{
		Matrix r(d);
		for (int i=0;i<id;i++)
			for (int j=0;j<id;j++) r.mat[i][j]=(mat[i][j]+b.mat[i][j])%d;
		return r;
	}
	Matrix operator*(const Matrix &b)
	{
		Matrix r(d);
		for (int i=0;i<id;i++)
			for (int k=0;k<id;k++)
				if (mat[i][k])
					for (int j=0;j<id;j++)
						r.mat[i][j]=(r.mat[i][j]+mat[i][k]*b.mat[k][j])%d;
		return r;
	}
} a[10001];

int main()
{
	int n,k,t1,t2;
	unsigned int u,v,s,t;
	while (scanf("%d",&n)!=EOF)
	{
		hash_table.clear(); id=0;
		a[1]=Matrix();
		for (int i=0;i<n;i++) {
			scanf("%d%d",&u,&v);
			a[1].mat[hash_(u)-1][hash_(v)-1]++;
		}
		for (int i=2;i<=10000;i++) a[i]=(a[i-1]*a[1])+a[1];
		scanf("%d",&k);
		for (int i=0;i<k;i++) {
			scanf("%d%d%d%d",&s,&t,&t1,&t2);
			if (!(s=hash_table[s])||!(t=hash_table[t])) {
				puts("0");
				continue;
			}
			s--; t--;
			if (t1>t2) swap(t1,t2);
			if (!t1) t1++;
			printf("%d\n",(a[t2].mat[s][t]-a[t1-1].mat[s][t]+2008)%2008);
		}
	}
	return 0;
}