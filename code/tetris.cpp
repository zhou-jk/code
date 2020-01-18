#include <stdio.h>
#include <cstring>

char s[10][11];
int a[5];
int n,m;
char c;

int main() {
	freopen("tetris.in","r",stdin); freopen("tetris.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++) scanf("%s",&s[i]);
	memset(a,0,sizeof(a));
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
        	if (s[i][j]!='.') {
        		c=s[i][j]; s[i][j]='.';
        		if (s[i][j+1]==c&&s[i+1][j]==c&&s[i+1][j+1]==c) {
        			a[0]++;
        			s[i][j+1]='.'; s[i+1][j]='.'; s[i+1][j+1]=='.'; 
				}
				if (s[i][j+1]==c&&s[i][j+2]==c&&s[i][j+3]==c) {
        			a[1]++;
        			s[i][j+1]='.'; s[i][j+2]='.'; s[i][j+3]=='.'; 
				}
				if (s[i+1][j]==c&&s[i+2][j]==c&&s[i+3][j]==c) {
        			a[1]++;
        			s[i+1][j]='.'; s[i+2][j]='.'; s[i+3][j]=='.'; 
				}
				if (s[i][j+1]==c&&s[i+1][j]==c&&s[i+1][j-1]==c) {
        			a[2]++;
        			s[i][j+1]='.'; s[i+1][j]='.'; s[i+1][j-1]=='.'; 
				}
				if (s[i+1][j+1]==c&&s[i+1][j]==c&&s[i+2][j+1]==c) {
        			a[2]++;
        			s[i+1][j+1]='.'; s[i+1][j]='.'; s[i+2][j+1]=='.'; 
				}
				if (s[i][j+1]==c&&s[i+1][j+2]==c&&s[i+1][j+1]==c) {
        			a[3]++;
        			s[i][j+1]='.'; s[i+1][j+2]='.'; s[i+1][j+1]=='.'; 
				}
				if (s[i+1][j-1]==c&&s[i+1][j]==c&&s[i+2][j-1]==c) {
        			a[3]++;
        			s[i+1][j-1]='.'; s[i+1][j]='.'; s[i+2][j-1]=='.'; 
				}
				if (s[i+1][j+1]==c&&s[i+1][j]==c&&s[i+1][j-1]==c) {
        			a[4]++;
        			s[i+1][j+1]='.'; s[i+1][j]='.'; s[i+1][j-1]=='.';
				}
				if (s[i+2][j]==c&&s[i+1][j]==c&&s[i+1][j-1]==c) {
        			a[4]++;
        			s[i+2][j]='.'; s[i+1][j]='.'; s[i+1][j-1]=='.'; 
				}
				if (s[i+2][j]==c&&s[i+1][j]==c&&s[i+1][j+1]==c) {
        			a[4]++;
        			s[i+2][j]='.'; s[i+1][j]='.'; s[i+1][j+1]=='.'; 
				}
				if (s[i][j+1]==c&&s[i][j+2]==c&&s[i+1][j+1]==c) {
        			a[4]++;
        			s[i][j+1]='.'; s[i][j+2]='.'; s[i+1][j+1]=='.';
				}
			}
	for (int i=0;i<5;i++) printf("%d\n",a[i]);
    return 0;
}
