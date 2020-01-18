//51Nod-1714
#include <cstdio>

const int LEN=64;
int sg[LEN+1],vis[200000000];

int main()
{
	for (int i=1; i<=LEN; ++i)
	{
		for (int a=0; a<i; ++a)
			for (int b=a; b<i; ++b)
				for (int c=b; c<i; ++c)
					for (int d=c; d<i; ++d)
						for (int e=d; e<i; ++e)
							for (int f=e; f<i; ++f)
								for (int g=f; g<i; ++g)
									vis[sg[a]^sg[b]^sg[c]^sg[d]^sg[e]^sg[f]^sg[g]]=i;
		for (int j=0;; ++j)
			if (vis[j]!=i)
			{
				sg[i]=j;
				break;
			}
		printf("%d,",sg[i]);
	}
	return 0;
}