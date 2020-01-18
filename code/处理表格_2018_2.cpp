//Virtual Judge 2018年寒假网赛第一场 B
#include <cstdio>

int main() {
	int n,i,j,k,t,w3,p;
	char s[17],w1[6],w2[8],w4[6];
	for (scanf("%d",&n);n;n--) {
		scanf("%s",s);
		for (i=0;s[i]>='A'&&s[i]<='Z';i++) w1[i]=s[i];
		for (j=0;s[i+j]>='0'&&s[i+j]<='9';j++) w2[j]=s[i+j];
		w1[i]=w2[j]=w3=0;
		if (s[i+j]>='A'&&s[i+j]<='Z') {
			t=i+j+1;
			for (k=0;s[t+k];k++) w3=w3*10+s[t+k]-'0';
			p=0;
			while (w3) {
				w4[p++]='A'+(w3-1)%26;
				w3=(w3-1)/26;
			}
			for (k=p-1;k>=0;k--) printf("%c",w4[k]);
			printf("%s\n",w2);
		}
		else {
			printf("R%s",w2);
			for (k=0;w1[k];k++) w3=w3*26+w1[k]-'A'+1;
			printf("C%d\n",w3);
		}
	}
	return 0;
}
