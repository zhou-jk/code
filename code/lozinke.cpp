#include <stdio.h>
#include <cstring>
#include <algorithm>

using std::sort;

struct str {
	char s[12];
	int f;
} p1[200001],p[20001],s;

int n,i,j,k,t,t1,a,s1[20000],f1[20000],f2[200000];
bool v[20000];

bool cmp(str a,str b) {
	return strcmp(a.s,b.s)<0;
}

void change(str *p,int *f,int *n) {
	sort(p,p+*n,cmp);
	strcpy(p[*n].s,"zzzzzzzzzzz");
	t1=j=-1;
	for (i=0;i<*n;i++)
    	if (cmp(p[i],p[i+1])) {
    		p[++t1]=p[i]; f[t1]=i-j;
    		//printf("%d %d %d %d %d\n",i,j,i-j,f1[t1],t1);
    		j=i;
		}
	*n=t1+1;
}

int main() {
	freopen("lozinke.in","r",stdin); freopen("lozinke.out","w",stdout);
	scanf("%d",&n);
	t=-1;
	for (i=0;i<n;i++) {
		scanf("%s",&p[i].s);
		p[i].f=i; s=p[i];
		while (s.s[0]!='\0') {
			p1[++t]=s;
			for (j=0;s.s[j]!='\0';j++) s.s[j]=s.s[j+1];
		}
    }
    //printf("&%d\n",t);
    //memset(f1,0,sizeof(f1)); 
    change(p,f1,&n); //change(p1,f2,t+1);
    //printf("&%d %d %d\n",t,sizeof(str),sizeof(p1));
    sort(p1,p1+t+1,cmp);
    j=0;
    //memset(v,false,sizeof(v));
    //printf("%d\n",n);
    for (i=0;i<n;i++) {
    	//printf("%s %d\n",p[i].s,f1[i]);
    	while (cmp(p1[j],p[i])&&j<t) j++;
    	if (cmp(p1[j],p[i])) break;
    	k=j; t1=-1;
    	while (k<=t&&strncmp(p1[k].s,p[i].s,strlen(p[i].s))==0) {
    		if (!v[p1[k].f]) {
    			//printf("%d %d\n",i,p1[k].f);
    			a+=f1[i];
    			v[p1[k].f]=true;
    			s1[++t1]=p1[k].f;
			}
			k++;
		}
		for (k=0;k<=t1;k++) v[s1[k]]=false;
		a-=f1[i];
	}
	printf("%d",a);
	return 0;
}
