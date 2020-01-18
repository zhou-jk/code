//PrayerOJ 1733
#include <stdio.h>

long long n,m,t,i;

struct a {
	char a[17];
} t1,p,p1;

char q[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

a convert(long long num) {
	for (int i=m-1;i>=0;i--) {
		t1.a[i]=q[num%n]; num/=n;
	}
	return t1;
}

int check(long long num) {
    int j;
    p=convert(num);
    //printf("%s\n",p.a);
	for (int i=2;i<=m;i++) {
		//printf("$%d\n",i); 
		p1=convert(num*i);
		//printf("*%s\n",p1.a);
		//printf("%c %c|",p.a[0],p1.a[0]);
		for (j=0;j<=m-1&&p.a[j]!=p1.a[0];j++);  //printf("%c %c|",p.a[j],p1.a[0]);
		if (p.a[j]!=p1.a[0]) return 0;
		for (int k=1;k<=m-1;k++)
		  if (p1.a[k]!=p.a[(j+k)%m]) return 0;
	}
	return 1;
}

int main() {
	scanf("%lld %lld",&n,&m);
	//printf("&&");
	t=1; t1.a[m]=p.a[m]=p1.a[m]='\0';
	for (i=1;i<=m;i++) t*=n;
	//printf("&&"); 
	for (i=t/n;i<=(t-1)/m;i++) {
	  //printf("%lld %s\n",i,convert(i));
	  if (check(i)) {
          printf("%s",convert(i).a);
          return 0;
      }
    }
    printf("no solutioin");
    return 0;
}
