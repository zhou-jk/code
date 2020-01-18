#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Rank{
	int a,b,c;
	bool operator<(Rank &b) {
		return a<b.a;
	}
};

class BIT
{
public:
	BIT(int n):tr(new int[n+1])
	{
		this->n=n;
		memset(tr,0x3f,(n+1)*sizeof *tr);
	}
	void update(int k,int num)
	{
		for (;k<=n;k+=low_bit(k)) tr[k]=min(tr[k],num);
	}
	int query(int k)
	{
		int ans=0x3f3f3f3f;
		for (;k;k-=low_bit(k)) ans=min(ans,tr[k]);
		return ans;
	}
private:
	int low_bit(int num)
	{
		return num&(-num);
	}
	int n,*tr;
};

int main() {
	freopen("team.in","r",stdin); freopen("team.out","w",stdout);
	int n,tmp,ans;
	scanf("%d",&n);
	Rank *r=new Rank[n];
	BIT bit(n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&tmp);
		r[tmp-1].a=i;
	}
	for (int i=1;i<=n;i++) {
		scanf("%d",&tmp);
		r[tmp-1].b=i;
	}
	for (int i=1;i<=n;i++) {
		scanf("%d",&tmp);
		r[tmp-1].c=i;
	}
	sort(r,r+n);
	ans=n;
	for (int i=0;i<n;i++) {
		if (bit.query(r[i].b-1)<r[i].c) ans--;
		bit.update(r[i].b,r[i].c);
	}
	printf("%d",ans);
	return 0;
}