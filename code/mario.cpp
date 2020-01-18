#include <stdio.h>


#define N 10000001

bool v[N];
int p[5000000],s[4],t1;

int main() {
	long long m,n;
	for (int i=2;i<N;i++) {
		//printf("%d\n",t1);
		if (!v[i]) p[t1++]=i;
		for (int j=0;j<t1&&i*p[j]<N&&i%p[j];j++) v[i*p[j]]=true;
	}
	while (scanf("%lld %lld",&m,&n)!=EOF) {
		int max=0,t2=-1;
		bool b=true;
		n/=m;
		memset(s,0,sizeof(s));
		for (int i=0;i<t1;i++) {
			if (!n%p[i]) t2++;
			while (!n%p[i]) {
				n/=p[i];
				s[t2]++;
			}
			printf("%d %d\n",t2,s[t2]);
			if (s[t2]>max) max=s[t2];
			if (t2>2||t2==2&&max>1||t2==1&&(s[0]>1&&s[1]>1||max>3)||t2==0&&s[0]>6) {
				printf("Mario wins!\n");
				b=false;
				break;
			}
		}
		if (b) printf("Wario wins!\n");
	}
	return 0;
}
