// AC
#include <cstdio>

const int N = 100, N_DIR = 4, dx[N_DIR] = {1, -1, 0, 0},
		  dy[N_DIR] = {0, 0, 1, -1};
char map[N][N + 1];
int qx[N * N], qy[N * N];

int main()
{
	int n, m, l = 0, r, r1 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%s", map[i]);
	scanf("%d", &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (map[i][j] == '@')
			{
				qx[r1] = i;
				qy[r1++] = j;
			}
	while (--m)
	{
		r = r1;
		for (; l < r; ++l)
			for (int i = 0; i < N_DIR; ++i)
			{
				int tx = qx[l] + dx[i], ty = qy[l] + dy[i];
				if (~tx && tx < n && ~ty && ty < n && map[tx][ty] == '.')
				{
					map[tx][ty] = '@';
					qx[r1] = tx;
					qy[r1++] = ty;
				}
			}
	}
	printf("%d", r1);
	return 0;
}