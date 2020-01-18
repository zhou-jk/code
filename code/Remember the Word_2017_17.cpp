//Virtual Judge UVALive 3942
#include <stdio.h>
#include <cstring>

int s,t[200500][26],f[300001],tot;
char w[300001],w1[101];
bool v[200500];

void build(char *w) {
	int k=0,l=strlen(w);
	for (int i=0;i<l;i++) {
		int p=w[i]-'a';
		//printf("%d %d %d %d\n",i,k,p,t[k][p]);
		if (!t[k][p]) t[k][p]=++tot;
		//printf("%d %d %d %d\n",i,k,p,t[k][p]);
		k=t[k][p];
	}
	v[k]=true;
	//printf("**"); 
}

int main() {
	//printf("&&");
	int c=0;
	while (scanf("%s",w)!=EOF) {
		memset(t,0,sizeof(t)); memset(v,0,sizeof(v)); memset(f,0,sizeof(f)); tot=0;
		scanf("%d",&s);
		for (int i=0;i<s;i++) {
			scanf("%s",w1);
			//printf("%s\n",w1);
			build(w1);
		}
		//printf("%d\n",s); 
		int l=strlen(w);
		f[l]=1;
		for (int i=l-1;i>=0;i--) {
			int k=0,e=i+100;
            for (int j=i;j<l&&j<e;j++) {
            	//printf("%d %d\n",i,j);
            	int p=w[j]-'a';
				if (!t[k][p]) break;
				k=t[k][p];
				if (v[k]) f[i]+=f[j+1];
		    }
		    f[i]%=20071027;
		}
		printf("Case %d: %d\n",++c,f[0]);
	}
	return 0;
}
