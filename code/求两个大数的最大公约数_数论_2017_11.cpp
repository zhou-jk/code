//PrayerOJ 1719 
#include <stdio.h>

typedef int n[102];

int i,m;

bool c(n a,n b) {
	if (a[0]>b[0]) return 1;
	if (a[0]<b[0]) return 0;
	for (i=1;i<=a[0];i++) {
	  if (a[i]<b[i]) return 0;
	  if (a[i]>b[i]) return 1;
    }
    return 1;
}

n d(n a,n b) {
	m=a[0];
	for (i=1;i<=m;i++) {
		a[i]-=b[i];
		if (a[i]<0) {
			a[i]+=10;
			a[i+1]--;
	    }
	    if (a[i]>0) a[0]=i;
    }
    return a;
}

n mod(n a,n b) {
	n t={0}; 
	for (int i=1;i<=a[0];i++) {
		for (int j=1;j<=t[0];j++) t[j+1]=t[j];
		t[0]++; t[1]=a[i];
	    while c(t,b) {
	       t=d(t,b);
	    }
	}
	return t;
}

n gcd(n a,n b) {
	n t=mod(a,b);
	if (t[0]=1)and(t[1]=0) return b;
	else gcd(b,t);
}


int main() {
	char sa[101],sb[101]; 
	n a,b;
    scanf("%s",sa); scanf("%s",sb);
    for (i=1;i<=strlen(sa);i++) a[i]=int(sa[i])-int('0');
    for (i=1;i<=strlen(sb);i++) b[i]=int(sb[i])-int('0');
	t=gcd(a,b);
    for (i=t[0];i>=1;i--) prinft("%d",t[i]);
	return 0;
}
