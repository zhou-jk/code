//VOJ 2018年寒假网赛第四场 C
#include <cstdio>
#include <cstring>

int main() {
	char s[101],t[101];
	int len;
	scanf("%s%s",s,t);
	len=strlen(s)-1;
	s[len]++;
	for (int i=len;s[i]>'z';i--) {
		s[i-1]+=(s[i]-'a')/26;
		s[i]=(s[i]-'a')%26+'a';
	}
	if (strcmp(s,t)) puts(s);
	else puts("No such string");
	return 0;
}
