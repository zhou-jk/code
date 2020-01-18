//Virtual Judge 2018年寒假网赛第四场 A
#include <cstdio>

bool s[123];
char ans[101];
int t;

int main() {
	int n;
	s['a']=s['e']=s['i']=s['u']=s['o']=s['y']=true;
	for (scanf("%d\n",&n);n;n--) {
		scanf("%c",&ans[t]);
		if (!t||!s[ans[t]]||!s[ans[t-1]]) t++;
	}
	if (s[ans[t]]&&s[ans[t-1]]) ans[t]=0;
	puts(ans);
	return 0;
}
