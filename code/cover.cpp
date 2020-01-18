#include <cstdio>
#include <cstring>

class BIT
{
public:
	BIT(int n):tr(new int[n+1])
	{
		this->n=n;
		memset(tr,0,(n+1)*sizeof *tr);
	}
	void change(int k,int num)
	{
		for (;k<=n;k+=low_bit(k)) tr[k]+=num;
	}
	int get_sum(int k)
	{
		int sum=0;
		for (;k;k-=low_bit(k)) sum+=tr[k];
		return sum;
	}
private:
	int low_bit(int num)
	{
		return num&(num^(num-1)); //num&(-num)
	}
	int n,*tr;
};

int main()
{
	freopen("cover.in","r",stdin); freopen("cover.out","w",stdout);
	int n,m,x,y,k;
	char act[2];
	scanf("%d%d",&n,&m);
	BIT bit(n);
	for (int i=0;i<m;i++)
	{
		scanf("%s",act);
		if (act[0]=='C')
		{
			scanf("%d%d",&x,&y);
			bit.change(x,1); bit.change(y+1,-1);
		}
		else
		{
			scanf("%d",&k);
			printf("%d\n",bit.get_sum(k));
		}
	}
	return 0;
}