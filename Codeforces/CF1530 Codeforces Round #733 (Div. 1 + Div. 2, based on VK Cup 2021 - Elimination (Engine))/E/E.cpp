#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=100005;
int n;
char s[N];
int cnt[26];
void solve()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    fill(cnt,cnt+26,0);
    for(int i=1;i<=n;i++)
        cnt[s[i]-'a']++;
    int c=-1;
    for(int i=0;i<26;i++)
        if(cnt[i]==1)
        {
            c=i;
            break;
        }
    if(c!=-1)
    {
        printf("%c",c+'a');
        for(int ch=0;ch<26;ch++)
            if(ch!=c)
            {
                for(int j=1;j<=cnt[ch];j++)
                    printf("%c",ch+'a');
            }
        printf("\n");
        return;
    }
    int c1=-1;
    for(int i=0;i<26;i++)
        if(cnt[i]>=1)
        {
            c1=i;
            break;
        }
    if(cnt[c1]<=(n+2)/2)
    {
        vector<int>S;
        for(int i=0;i<26;i++)
            if(i!=c1)
                for(int j=1;j<=cnt[i];j++)
                    S.emplace_back(i);
        int j=0;
        for(int i=1;i<=cnt[c1];i++)
        {
            printf("%c",c1+'a');
            if(i>1&&j<(int)S.size()) printf("%c",S[j]+'a'),j++;
        }
        for(;j<(int)S.size();j++)
            printf("%c",S[j]+'a');
        printf("\n");
        return;
    }
    int c2=-1;
    for(int i=0;i<26;i++)
        if(i!=c1&&cnt[i]>=1)
        {
            c2=i;
            break;
        }
    if(c2==-1)
    {
        printf("%s\n",s+1);
        return;
    }
    int c3=-1;
    for(int i=0;i<26;i++)
        if(i!=c1&&i!=c2&&cnt[i]>=1)
        {
            c3=i;
            break;
        }
    if(c3==-1)
    {
        printf("%c",c1+'a');
        for(int i=1;i<=cnt[c2];i++)
            printf("%c",c2+'a');
        for(int i=2;i<=cnt[c1];i++)
            printf("%c",c1+'a');
        printf("\n");
        return;
    }
    printf("%c%c",c1+'a',c2+'a');
    for(int i=2;i<=cnt[c1];i++)
        printf("%c",c1+'a');
    printf("%c",c3+'a');
    vector<int>S;
    for(int i=0;i<26;i++)
        if(i!=c1)
        {
            for(int j=1;j<=cnt[i]-(i==c2)-(i==c3);j++)
                S.emplace_back(i);
        }
    for(int i:S)
        printf("%c",i+'a');
    printf("\n");
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}
