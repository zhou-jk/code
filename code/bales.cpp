#include <cstdio>

const int N=25000;
int num[N],l_min[N],l_max[N],r_min[N],r_max[N],n_num;

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=0; i<q; ++i)
	{
		int l,r,_num;
		scanf("%d%d%d",&l,&r,&_num);
		for (int j=0; j<n_num; ++j)
			if (num[j]==_num)
			{
				l_min[j]=min(l_min[j],l);
				l_max[j]=max(l_max[j],l);
				r_min[j]=min(r_min[j],r);
				r_max[j]=max(r_max[j],r);
			}
			else if (num[j]<_num)
			{

			}
	}
	return 0;
}