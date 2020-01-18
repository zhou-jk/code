#include <cstdio>
#include <cstring>

using namespace std;

char h[2000][51],w1[1000][51],w2[1000][51],f[1000];
int t,fa[2000];

int get_id(char *w) {
	int i;
	for (i=0;i<=t;i++)
		if (!strcmp(h[i],w)) return i;
	strcpy(h[++t],w);
	return t;
}

int get_fa(int k) {
	if (fa[k]!=k) fa[k]=get_fa(fa[k]);
	return fa[k];
}

void init() {
	freopen("logician.in","r",stdin); freopen("logician.out","w",stdout);
}

void doit() {
	char tmp[3];
	int m,n,i,id1,id2;
	for (scanf("%d",&m);m;m--) {
		bool b=true;
		t=0;
		scanf("%d",&n);
		for (int i=0;i<2*n;i++) fa[i]=i;
		memset(f,0,sizeof(f));
		for (i=0;i<n;i++) {
			scanf("%s%s%s",w1[i],tmp,w2[i]);
			if (getchar()==' ') {
				scanf("%s",w2[i]);
				f[i]=true;
			}
			else fa[get_fa(get_id(w1[i]))]=get_fa(get_id(w2[i]));
		}
		for (int i=0;i<n;i++)
			if (f[i]&&get_fa(get_id(w1[i]))==get_fa(get_id(w2[i]))) {
				printf("Skywalker will jump.\n");
				b=false;
				break;
			}
		if (b) printf("Skywalker disappears.\n");
	}
}

int main() {
	init();
	doit();
	return 0;
}
