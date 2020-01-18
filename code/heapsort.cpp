#define N 1000000
#include <cstdio>

int r[N],q[N+1],t;

int min(int x,int y) {
	//printf("%d %d %d %d\n",x,y,q[x],q[y]);
	if (y>t||q[x]<q[y]) return x;
	return y;
}

void swap(int &a,int &b) {
	int t=a; a=b; b=t;
}

void up(int k) {
	while (k>1&&q[k]<q[k>>1]) {
		swap(q[k],q[k>>1]);
		k>>=1;
	}
}

void down(int k) {
	while (k<<1<=t) {
		int s=min(k<<1,(k<<1)+1);
		if (q[s]<q[k]) swap(q[s],q[k]);
		k=s;
	}
}

void add(int u) {
	q[++t]=u;
	up(t);
}

void del() {
	//printf("^");
	//for (int i=1;i<=t;i++) printf("%d ",q[i]);
	//printf("\n");
	//printf("&%d %d ",q[t],t);
	q[1]=q[t--];
	//printf("*");
	//for (int i=1;i<=t;i++) printf("%d ",q[i]);
	//printf("\n");
	//printf("%d %d\n",q[1],t);
	down(1);
}

int main() {
    int n,u;
    scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&u);
		add(u);
		//for (int i=1;i<=t;i++) printf("%d ",q[i]);
	    //printf("\n");
	}
	
	for (int i=0;i<n;i++) {
		r[i]=q[1];
		del();
		printf("%d ",r[i]);
	}
	printf("\n");
	for (int i=n-1;i>=0;i--) printf("%d ",r[i]);
	return 0;
}
