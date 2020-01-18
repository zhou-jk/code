#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int oo=1000000000;
struct Edge{
	int key,v,next;
};
struct Point{
	int room,key;
};
class Map{
public:
	static const int N=5000,M=6000,K=10,N1=1<<K; //N:房间数 M:边数 K:钥匙种类数 N1:钥匙组合数
	inline int input_key() {
		int key=0,tmp;
		for (int i=0;i<k;i++) {
				scanf("%d",&tmp);
				key<<=1; key|=tmp;
			}
		return key;
	}
	inline void add_edge(int u,int v,int key) {
		edge[tot_edge]=Edge{key,v,room[u].head};
		room[u].head=tot_edge++;
	}
	inline void init() {
		int u,v;
		scanf("%d%d%d",&n,&m,&k);
		for (int i=0;i<n;i++) {
			room[i].key=input_key();
			room[i].head=-1;
		}
		for (int i=0;i<m;i++) {
			scanf("%d%d",&u,&v);
			//printf("%d %d\n",u,v);
			add_edge(u-1,v-1,input_key());
		}
	}
	inline void bfs() {
		//puts("&&");
		for (int i=0;i<n;i++) memset(room[i].d,-1,sizeof room[i].d);
		room[0].d[room[0].key]=0;
		int l=0,r=1;
		q[0].room=0; q[0].key=room[0].key;
		//printf("%d\n",room[q[l].room].head);
		while (l<r) {
			for (int i=room[q[l].room].head;i>=0;i=edge[i].next) {
				//printf("%d %d %d %d\n",i,edge[i].v,edge[i].key,edge[i].next);
				if (room[edge[i].v].d[q[l].key|room[edge[i].v].key]<0&&(q[l].key|edge[i].key)==q[l].key) {
					room[edge[i].v].d[q[l].key|room[edge[i].v].key]=room[q[l].room].d[q[l].key]+1;
					q[r].room=edge[i].v; q[r++].key=q[l].key|room[edge[i].v].key;
					//printf("%d %d %d\n",edge[i].v,q[l].key|room[edge[i].v].key,room[edge[i].v].d[q[l].key|room[edge[i].v].key]);
				}
				//printf("&%d %d %d %d\n",i,edge[i].v,edge[i].key,edge[i].next);
			}
			l++;
		}
	}
	inline int get_ans() {
		int tmp=n-1,ans=oo;
		for (int i=0;i<N1;i++)
			if (room[tmp].d[i]>=0) ans=min(ans,room[tmp].d[i]);
		return ans;
	}
private:
	Edge edge[M+1];
	struct Room{
		int key,head,d[N1];
	} room[N];
	Point q[N*N1];
	int n,m,k,tot_edge;
} map;

int main() {
	freopen("room.in","r",stdin); freopen("room.out","w",stdout);
	map.init();
	map.bfs();
	int ans=map.get_ans();
	if (ans==oo) puts("No Solution");
	else printf("%d",ans);
	return 0;
}