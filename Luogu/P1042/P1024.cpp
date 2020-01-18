#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char ch[100000];
int cnt1,cnt2,len;
int main()
{
    scanf("%[^E]", ch);
    len=strlen(ch);
    for(int i=0;i<len;i++)
    {
        if(ch[i]=='W') cnt1++;
        if(ch[i]=='L') cnt2++;
        if((cnt1>=11||cnt2>=11)&&abs(cnt1-cnt2)>=2)
        {
            printf("%d:%d\n",cnt1,cnt2);
            cnt1=cnt2=0;
        }
    }
    printf("%d:%d\n\n",cnt1,cnt2);
    cnt1=cnt2=0;
    for(int i=0;i<len;i++)
    {
        if(ch[i]=='W') cnt1++;
        if(ch[i]=='L') cnt2++;
        if((cnt1>=21||cnt2>=21)&&abs(cnt1-cnt2)>=2)
        {
            printf("%d:%d\n",cnt1,cnt2);
            cnt1=cnt2=0;
        }
    }
    printf("%d:%d",cnt1,cnt2);
    return 0;
}