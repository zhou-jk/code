//VOJ 2018年寒假网赛第五场 A
#include <cstdio>

int ans1,ans2;

int main() {
	char s[9];
	for (int i=0;i<8;i++) {
		scanf("%s",s);
		for (int j=0;j<8;j++) {
			switch (s[j]) {
				case 'Q':{
					ans1+=9;
					break;
				}
				case 'R':{
					ans1+=5;
					break;
				}
				case 'B':{
					ans1+=3;
					break;
				}
				case 'N':{
					ans1+=3;
					break;
				}
				case 'P':{
					ans1++;
					break;
				}
				case 'q':{
					ans2+=9;
					break;
				}
				case 'r':{
					ans2+=5;
					break;
				}
				case 'b':{
					ans2+=3;
					break;
				}
				case 'n':{
					ans2+=3;
					break;
				}
				case 'p':{
					ans2++;
					break;
				}
			}
			//printf("%d %d\n",ans1,ans2);
		}
	}
	if (ans1==ans2) puts("Draw");
	else if (ans1>ans2) puts("White");
	else puts("Black");
	return 0;
}
