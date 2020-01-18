#include <cstdio>

int main()
{
	while (scanf("%d%d",&n_node,&n_edge)!=EOF)
		for (int i=0; i<n_edge; i++) scanf("%d%d%d",&u[i],&v[i],&num[i]);

	return 0;
}