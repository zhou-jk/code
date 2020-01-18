//VOJ 2018年寒假网赛第六场 A 
#include <cstdio>

bool f[26];

int main() {
	int n;
	char s[101];
	scanf("%d%s",&n,&s);
	for (int i=0;i<n;i++)
		if (s[i]>='A'&&s[i]<='Z') f[s[i]-'A']=true;
		else f[s[i]-'a']=true;
	for (int i=0;i<26;i++)
		if (!f[i]) {
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}
