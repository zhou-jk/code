#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000001;
char s[N];
int Next[N];
int T,n;
void kmp()
{
    Next[1]=0;
    for(int i=2,j=0;i<=n;i++)
    {
        while(j&&s[i]!=s[j+1]) j=Next[j];
        if(s[i]==s[j+1]) j++;
        Next[i]=j;
    }
    return;
}
int main()
{
    int Case=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        kmp();
        printf("Test case #%d\n",++Case);
        for(int i=2;i<=n;++i)
            if(i%(i-Next[i])==0&&i/(i-Next[i])>1) printf("%d %d\n",i,i/(i-Next[i]));
        printf("\n");
    }
    return 0;
}