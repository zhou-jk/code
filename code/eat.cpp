#define N 50000

#include <cstdio>

using namespace std;

int fa[3*N],ans;

int get_fa(int k) {
	/**if (fa[k]==k) return k;  
    int t=k;  
    while (fa[k]!=k) {  
        k=fa[k];  
    }  
    while (fa[t]!=t) {  
        int t2=t;  
        t=fa[t];  
        fa[t2]=k;  
    } 
    return k;*/ 
	if (fa[k]!=k) fa[k]=get_fa(fa[k]);
	return fa[k];
}

bool same(int x,int y) {
	return get_fa(x)==get_fa(y);
}

void merge(int x,int y) {
	fa[get_fa(x)]=get_fa(y);
}

int main() {
	int n,k,d,x,y;
	freopen("eat.in","r",stdin); freopen("eat.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=0;i<3*n;i++) fa[i]=i;
	for (int i=0;i<k;i++) {
		scanf("%d%d%d",&d,&x,&y);
		x--; y--;
		if (x>=n||y>=n) ans++;
		else if (d==1)
			if (same(x,y+n)||same(x,y+2*n)) ans++;
			else {
				merge(x,y); merge(x+n,y+n); merge(x+2*n,y+2*n);
			}
		else if (same(x,y)||same(x,y+2*n)) ans++;
		else {
			merge(x,y+n); merge(x+n,y+2*n); merge(x+2*n,y);
		}
	}
	printf("%d",ans);
	return 0;
}
