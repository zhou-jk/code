#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n,q;
int p[N];
struct BIT
{
    int C[N];
    void clear()
    {
        for(int i=1;i<=n;i++)
            C[i]=0;
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]+=y;
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=C[i];
        return res;
    }
}T;
bool totalodd;
int cnt_odd;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(p[i]>i) cnt++;
    long long sum=0;
    for(int i=1;i<=n;i++)
        sum+=T.getsum(n)-T.getsum(p[i]),T.add(p[i],1);
    totalodd=sum%2==1;
    for(int i=1;i<=n;i++)
        if(p[i]%2!=i%2) cnt_odd++;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(p[x]>x) cnt--;
        if(p[y]>y) cnt--;
        if(p[x]%2!=x%2) cnt_odd--;
        if(p[y]%2!=y%2) cnt_odd--;
        swap(p[x],p[y]);
        if(p[x]>x) cnt++;
        if(p[y]>y) cnt++;
        if(p[x]%2!=x%2) cnt_odd++;
        if(p[y]%2!=y%2) cnt_odd++;
        totalodd=!totalodd;
        if(cnt==0) cout<<-1<<"\n";
        else if(totalodd) cout<<n<<"\n";
        else if(cnt_odd) cout<<n-1<<"\n";
        else cout<<n-2<<"\n";
    }
    return 0;
}