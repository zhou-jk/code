#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
char s[N];
int prej[N],sufi[N];
long long prejo[N],sufoi[N];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    {
        prej[i]=prej[i-1];
        prejo[i]=prejo[i-1];
        if(s[i]=='J') prej[i]++;
        else if(s[i]=='O') prejo[i]+=prej[i-1];
    }
    for(int i=n;i>=1;i--)
    {
        sufi[i]=sufi[i+1];
        sufoi[i]=sufoi[i+1];
        if(s[i]=='I') sufi[i]++;
        else if(s[i]=='O') sufoi[i]+=sufi[i+1];
    }
    long long sum=0;
    for(int i=1;i<=n;i++)
        if(s[i]=='I') sum+=prejo[i];
    long long ans=sum;
    for(int i=0;i<=n;i++)
    {
        long long resj=sum+sufoi[i+1],reso=sum+(long long)prej[i]*sufi[i+1],resi=sum+prejo[i];
        ans=max(ans,max({resj,reso,resi}));
    }
    printf("%lld",ans);
    return 0;
}