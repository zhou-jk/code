#include <cstdio>

const int N_NODE=300000;
class Monotone_Queue
{
public:
	Monotone_Queue()
	{
		n_node=l=r=0;
	}
	inline void add(const int num)
	{
		this->num[n_node]=num;
		push(n_node++);
	}
	inline int pop(const int min_l)
	{
		maint(min_l);
		return num[queue[l]];
	}
private:
	int queue[N_NODE+1],num[N_NODE+1],n_node,l,r;
	inline void push(const int k)
	{
		while (r-l&&num[queue[r-1]]>=num[k]) r--;
		queue[r++]=k;
	}
	inline void maint(const int min_l)
	{
		while (queue[l]<min_l) l++;
	}
} monotone_queue;

int main()
{
	freopen("qzdz.in","r",stdin); freopen("qzdz.out","w",stdout);
	int n,m,num,sum=0,tmp,ans=0;
	scanf("%d%d",&n,&m);
	monotone_queue.add(0);
	for (int i=0; i<n; i++)
	{
		scanf("%d",&num);
		sum+=num;
		monotone_queue.add(sum);
		tmp=monotone_queue.pop(i-m+1);
		//printf("%d\n",tmp);
		if (sum-tmp>ans) ans=sum-tmp;
	}
	printf("%d",ans);
	return 0;
}