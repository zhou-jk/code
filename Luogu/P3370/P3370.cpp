#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1501;
const int base=233;
const int MOD1=1000000007,MOD2=1000000009;
int n;
long long gethash(char *s,int MOD)
{
    int len=strlen(s+1);
    long long res=0;
    for(int i=1;i<=len;i++)
        res=(res*base%MOD+s[i])%MOD;
    return res;
}
char s[N];
vector<pair<long long,long long> >res;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        res.push_back(make_pair(gethash(s,MOD1),gethash(s,MOD2)));
    }
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    printf("%lu",res.size());
    return 0;
}
