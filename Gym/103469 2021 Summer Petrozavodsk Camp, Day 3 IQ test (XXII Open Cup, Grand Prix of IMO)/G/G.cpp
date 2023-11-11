#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
const int N=2005;
int n;
char s[N][N];
bitset<N> mpb[N],mpy[N];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        for(int j=1;j<=n;j++)
            s[i][j]=str[j-1];
        for(int j=1;j<=n;j++)
            if(i!=j)
            {
                if(s[i][j]=='B') mpb[i][j]=1;
                else mpy[i][j]=1;
            }
    }
    long long c2=0,c6=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(s[i][j]=='B')
            {
                int t=(mpy[i]&mpy[j]).count();
                c2+=(long long)t*(t-1)/2;
            }
            else
            {
                int t=(mpb[i]&mpb[j]).count();
                c2+=(long long)t*(t-1)/2;
            }
            c6+=(long long)(mpy[i]&mpb[j]).count()*(mpb[i]&mpy[j]).count();
        }
    c6/=2;
    long long ans=c6-c2;
    cout<<ans;
    return 0;
}
