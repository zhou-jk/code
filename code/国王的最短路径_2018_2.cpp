//Virtual Judge 2018年寒假网赛第一场 D
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	char s1[3],s2[3],c1,c2;
	int t1,t2,ans;
	scanf("%s",s1); scanf("%s",s2);
	t1=s2[0]-s1[0]; t2=s2[1]-s1[1];
	if (t1<0) {
		c1='L';
		t1=-t1;
	}
	else c1='R';
	if (t2<0) {
		c2='D';
		t2=-t2;
	}
	else c2='U';
	ans=max(t1,t2);
	printf("%d\n",ans);
	for (int i=0;i<ans;i++) {
		if (t1) {
			printf("%c",c1);
			t1--;
		}
		if (t2) {
			printf("%c",c2);
			t2--;
		}
		printf("\n");
	}
	return 0;
}
