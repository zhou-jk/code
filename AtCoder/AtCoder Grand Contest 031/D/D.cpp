#include<iostream>
#include<cstdio>
#include<cassert>
#include<vector>
using namespace std;
const int N=100005;
typedef vector<int> Permutation;
int n,k;
Permutation p,q;
Permutation a[7];
Permutation operator*(const Permutation &p,const Permutation &q)
{
	assert(p.size()==q.size());
	Permutation res(p.size());
	for(size_t i=1;i<res.size();i++)
		res[i]=p[q[i]];
	return res;
}
Permutation getinv(const Permutation &p)
{
	Permutation res(p.size());
	for(size_t i=1;i<p.size();i++)
		res[p[i]]=i;
	return res;
}
Permutation operator/(const Permutation &p,const Permutation &q)
{
	return p*getinv(q);
}
Permutation ksm(Permutation a,int b)
{
	Permutation res(a.size());
	for(size_t i=1;i<res.size();i++)
		res[i]=i;
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a,b>>=1;
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&k);
	p.resize(n+1),q.resize(n+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&q[i]);
	a[1]=p,a[2]=q;
	for(int i=3;i<=6;i++)
		a[i]=a[i-1]/a[i-2];
	Permutation A=q/p/q*p;
	Permutation res=ksm(A,(k-1)/6)*a[(k-1)%6+1]*ksm(getinv(A),(k-1)/6);
	for(int i=1;i<=n;i++)
		printf("%d ",res[i]);
	return 0;
}
