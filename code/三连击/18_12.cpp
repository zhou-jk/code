//AC
#include <cstdio>
#include <cstring>

const int N=9+1;
bool used[N];

bool check(int num)
{
	if (num>987) return true;
	for (int i=0;i<3;++i)
	{
		if (!(num%10)||used[num%10]) return true;
		used[num%10]=true;
		num/=10;
	}
	return false;
}

int main()
{
	for (int i=1;i<N;++i)
		for (int j=1;j<N;++j)
			for (int k=1;k<N;++k)
			{
				memset(used,false,sizeof used);
				int tmp=i*100+j*10+k;
				if (check(tmp)||check(tmp*2)||check(tmp*3)) continue;
				printf("%d %d %d\n",tmp,tmp*2,tmp*3);
			}
	return 0;
}
