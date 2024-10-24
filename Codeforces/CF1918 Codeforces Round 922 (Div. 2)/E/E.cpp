#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
char query(int i)
{
    cout<<"? "<<i<<endl;
    char ch;
    cin>>ch;
    return ch;
}
void submit(const vector<int> &p)
{
    cout<<"!";
    for(int u:p)
        cout<<" "<<u;
    cout<<endl;
    return;
}
const int N=2005;
int n;
int p[N];
int mn,mx,x;
void solve(int l,int r)
{
    if(l>=r) return;
    int mid=(l+r)>>1;
    while(x<mid) x++,query(mx); 
    while(x>mid) x--,query(mn);
    int pmid=0;
    vector<int>vl,vr;
    for(int i=l;i<=r;i++)
    {
        char ch=query(p[i]);
        if(ch=='<') vl.emplace_back(p[i]),query(mx);
        else if(ch=='>') vr.emplace_back(p[i]),query(mn);
        else pmid=p[i];
    }
    p[mid]=pmid;
    for(int i=0;i<(int)vl.size();i++)
        p[l+i]=vl[i];
    for(int i=0;i<(int)vr.size();i++)
        p[mid+1+i]=vr[i];
    solve(l,mid-1);
    solve(mid+1,r);
    return; 
}
int res[N];
void solve()
{
    cin>>n;
    mx=mn=0;
    for(int i=1;i<=n;i++)
    {
        char ch=query(i);
        if(ch=='='||ch=='>')
        {
            mx=i;
            while(ch=='>') ch=query(i);
        }
        else if(mx) query(mx);
    }
    for(int i=1;i<=n;i++)
    {
        char ch=query(i);
        if(ch=='='||ch=='<')
        {
            mn=i;
            while(ch=='<') ch=query(i);
        }
        else if(mn) query(mn);
    }
    x=1;
    int cnt=1;
    p[1]=mn,p[n]=mx;
    for(int i=1;i<=n;i++)
        if(i!=mn&&i!=mx) p[++cnt]=i;
    solve(2,n-1);
    for(int i=1;i<=n;i++)
        res[p[i]]=i;
    submit(vector<int>(res+1,res+n+1));
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