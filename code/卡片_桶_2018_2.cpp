//VOJ 2018年寒假网赛第四场 D
#include <cstdio>
#include <algorithm>

using namespace std;

const int LEN=200001;
int f1[123],f2[123],ans1,ans2;
char s[LEN],t[LEN];


void rep(char s,char t) {
	for (char i=s;i<=t;i++) {
		int tmp=min(f1[i],f2[i]);
		f1[i]-=tmp; f2[i]-=tmp;
		ans1+=tmp;
	}
}

int main() {
	scanf("%s%s",s,t);
	for (int i=0;s[i];i++) f1[s[i]]++;
	for (int i=0;t[i];i++) f2[t[i]]++;
	rep('a','z'); rep('A','Z');
	for (char i='a';i<='z';i++) ans2+=min(f1[i],f2[i-'a'+'A']);
	for (char i='A';i<='Z';i++) ans2+=min(f1[i],f2[i-'A'+'a']);
	printf("%d %d",ans1,ans2);
	return 0;
}
