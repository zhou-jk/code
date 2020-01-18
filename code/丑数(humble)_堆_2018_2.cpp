#include <cstdio>

int s[100],q[1000000],t,tmp;

void add(int u) {
	int k=++t;
	while (k>1&&u<q[k>>1]) {
		q[k]=q[k>>1];
		k=k>>1;
	}
	q[k]=u;
}

void del() {
	int k=1,s,u=q[t--];
	while (k<<1<t) {
		s=k<<1;
		if (s+1<=t&&q[s+1]<q[s]) s++;
		if (q[s]<u) {
			q[k]=q[s];
			k=s;
		}
		else break;
	}
	q[k]=u;
}

int main() {
	int n,k;    
	scanf("%d %d",&k,&n);
    for (int i=0;i<k;i++) {
    	scanf("%d",&s[i]);
    	add(s[i]);
	}
	while (n) {
		if (q[1]>tmp) {
			for (int i=0;i<k;i++) add(q[1]*s[i]);
			n--;
			tmp=q[1];
		}
		del();
	}
	printf("%d",tmp);
	return 0;
}
