#define N 200000
#define M 400000

#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,l[N],r[N],l1[N],r1[N],k[N<<1],h[N<<1],fa[N],time[N];

int get_fa(int k) {
	if (fa[k] == k) return k;
	get_fa(fa[k]);
	time[k] = min(time[k], time[fa[k]]);
	return fa[k] = fa[fa[k]];
	/*if (fa[k]!=k) fa[k]=get_fa(fa[k]);
	time[k]=min(time[k],time[fa[k]]);
	return fa[k];错 要在fa[k]更新前计算time*/
}

void merge(int a,int b,int new_time=M) {
	//printf("&%d\n",new_time);
	if (a>-1&&b>-1) {
		int x=get_fa(a),y=get_fa(b);
		printf("&&%d %d\n",x,y);
		if (x!=y)
			if (x==0) {
			    //printf("%d %d\n",a,b);
				time[y]=new_time;
				fa[y]=0;
			}
			else if (y==0) {
					 //printf("%d %d\n",a,b);
					 time[x]=new_time;
					 fa[x]=0;
				 }
				 else fa[x]=y;
	}
}

void init() {
	freopen("monkey.in","r",stdin); freopen("monkey.out","w",stdout);
}

void input() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&l[i],&r[i]);
		l[i]--; r[i]--;
		l1[i]=l[i]; r1[i]=r[i];
		fa[i]=i;
		time[i]=M;
		//printf("^%d %d\n",l[i],r[i]);
	}
	for (int i=0;i<m;i++) {
		scanf("%d%d",&k[i],&h[i]);
		k[i]--;
	    if (h[i]==1) l1[k[i]]=-1;
	    else r1[k[i]]=-1;
	    //printf("&%d %d\n",k[i],h[i]);
    }
}

void doit() {
	for (int i=0;i<n;i++) {
		merge(l1[i],i); merge(r1[i],i);
	}
	//printf("$%d\n",get_fa(0));
	for (int i=m-1;i>=0;i--)
		if (h[i]==1) {
			//printf("#%d %d\n",l[k[i]],k[i]);
			merge(l[k[i]],k[i],i);
	    }
		else {
			//printf("#%d %d\n",r[k[i]],k[i]);
			merge(r[k[i]],k[i],i);
		}
}

void output() {
	for (int i=0;i<n;i++) {
		get_fa(i);
		printf("%d\n",time[i]<M?time[i]:-1);
	}
}

int main() {
    //init();
    input();
    doit();
    output();
	return 0;
}
