#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n,m,len;
int c[N];
int a[N],b[N];
bool check(int v)
{
    int cur=1;
    a[1]=v;
    for(int i=1;i<=m;i++)
    {
        if(cur<=len&&c[cur]%a[1]==0) b[i]=c[cur]/a[1],cur++;
        else if(cur+1<=len&&(c[cur]*10+c[cur+1])%a[1]==0&&(c[cur]*10+c[cur+1])/a[1]<=9) b[i]=(c[cur]*10+c[cur+1])/a[1],cur+=2;
        else return false;
    }
    for(int i=2;i<=n;i++)
    {
        a[i]=-1;
        for(int j=1;j<=m;j++)
            if(b[j]!=0)
            {
                int val=-1;
                if(cur<=len&&c[cur]%b[j]==0) val=c[cur]/b[j],cur++;
                else if(cur+1<=len&&(c[cur]*10+c[cur+1])%b[j]==0&&(c[cur]*10+c[cur+1])/b[j]<=9) val=(c[cur]*10+c[cur+1])/b[j],cur+=2;
                else return false;
                if(a[i]!=-1&&a[i]!=val) return false;
                else a[i]=val;
            }
            else
            {
                if(cur<=len&&c[cur]==0) cur++;
                else return false;
            }
    }
    return cur==len+1;
}
void solve()
{
    cin>>n>>m;
    string str;
    cin>>str;
    len=str.size();
    for(int i=1;i<=len;i++)
        c[i]=str[i-1]-'0';
    for(int v=1;v<=9;v++)
        if(check(v))
        {
            for(int i=1;i<=n;i++)
                cout<<a[i];
            cout<<" ";
            for(int i=1;i<=m;i++)
                cout<<b[i];
            cout<<"\n";
            return;
        }
    cout<<"Impossible\n";
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