//POJ-2251
#include <cstdio>
#include <cstring>
// *INDENT-OFF*
const int N=30,
          dx[6]= {-1,1,0,0,0,0},
          dy[6]= {0,0,-1,1,0,0},
          dz[6]= {0,0,0,0,-1,1};
// *INDENT-ON*
char map[N][N][N];
int dist[N][N][N];
bool vis[N][N][N];

struct Node
{
	int x,y,z;
} q[N*N*N];

int main()
{
	int l,r,ll,rr,c,tx,ty,tz;
	char tmp[10];
	while (scanf("%d%d%d\n",&ll,&rr,&c)!=EOF&&ll&&rr&&c)
	{
		memset(vis,false,sizeof vis);
		l=r=0;
		for (int i=0; i<ll; i++)
		{
			for (int j=0; j<rr; j++)
			{
				for (int k=0; k<c; k++)
				{
					scanf("%c",&map[i][j][k]);
					if (map[i][j][k]=='S')
					{
						q[r].x=i; q[r].y=j; q[r++].z=k;
						vis[i][j][k]=true; dist[i][j][k]=0;
					}
				}
				gets(tmp);
			}
			gets(tmp);
		}
		bool flag=false;
		while (l<r)
		{
			for (int i=0; i<6; i++)
			{
				tx=q[l].x+dx[i]; ty=q[l].y+dy[i]; tz=q[l].z+dz[i];
				if (tx>=0&&tx<ll&&ty>=0&&ty<rr&&tz>=0&&tz<c
				        &&!vis[tx][ty][tz]&&map[tx][ty][tz]!='#')
				{
					dist[tx][ty][tz]=dist[q[l].x][q[l].y][q[l].z]+1;
					q[r].x=tx; q[r].y=ty; q[r++].z=tz;
					vis[tx][ty][tz]=true;
					if (map[tx][ty][tz]=='E')
					{
						printf("Escaped in %d minute(s).\n",dist[tx][ty][tz]);
						flag=true;
					}
				}
			}
			if (flag) break;
			l++;
		}
		if (!flag) puts("Trapped!");
	}
	return 0;
}