#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=105;
int n;
int a[N];
int b[N],tot;
int cnt[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    tot=0;
    for(int i=1;i<=n;i++)
        b[++tot]=a[i];
    sort(b+1,b+tot+1);
    tot=unique(b+1,b+tot+1)-b-1;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
    for(int i=1;i<=tot;i++)
        cnt[i]=0;
    for(int i=1;i<=n;i++)
        cnt[a[i]]++;
    int n1=n/2,n2=n-n1;
    if(cnt[1]>cnt[2]) swap(cnt[1],cnt[2]);
    if(tot==1||(tot==2&&cnt[1]==n1&&cnt[2]==n2)) cout<<"Yes\n";
    else cout<<"No\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}