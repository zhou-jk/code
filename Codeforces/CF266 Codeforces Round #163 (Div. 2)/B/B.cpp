#include<iostream>
#include<cstdio>
using namespace std;
const int N=55;
int n,m;
char s[N];
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    while(m--)
    {
        static char t[N];
        for(int i=1;i<=n;i++)
            if(s[i]=='B'&&s[i+1]=='G')
            {
                t[i]='G',t[i+1]='B';
                i++;
            }
            else t[i]=s[i];
        for(int i=1;i<=n;i++)
            s[i]=t[i];
    }
    printf("%s",s+1);
    return 0;
}