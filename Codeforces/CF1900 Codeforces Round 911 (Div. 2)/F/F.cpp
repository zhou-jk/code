#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m;
int a[N];
vector<int>b[20];
vector<int>work(const vector<int> &now,bool op)
{
    if((int)now.size()<=1) return now;
    vector<int>to;
    if(op)
    {
        if((a[now[0]]<a[now[1]])) to.push_back(now[0]);
        for(int i=1;i+1<(int)now.size();i++)
            if(a[now[i]]<a[now[i-1]]&&a[now[i]]<a[now[i+1]]) to.push_back(now[i]);
        if(a[now[now.size()-1]]<a[now[now.size()-2]]) to.push_back(now[now.size()-1]);
    }
    else
    {
        if((a[now[0]]>a[now[1]])) to.push_back(now[0]);
        for(int i=1;i+1<(int)now.size();i++)
            if(a[now[i]]>a[now[i-1]]&&a[now[i]]>a[now[i+1]]) to.push_back(now[i]);
        if(a[now[now.size()-1]]>a[now[now.size()-2]]) to.push_back(now[now.size()-1]);
    }
    return to;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        b[0].emplace_back(i);
    for(int i=1;i<20;i++)
        b[i]=work(b[i-1],i&1);
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        vector<int>L,R;
        l--,r--;
        for(int i=0;i<20;i++)
        {
            if(l>=r)
            {
                for(int j=l;j<=r;j++)
                    L.push_back(b[i][j]);
                for(int j:R)
                    L.push_back(j);
                while((int)L.size()>1)
                    L=work(L,(i&1)^1),i++;
                cout<<a[L[0]]<<"\n";
                break;
            }
            L.push_back(b[i][l]);
            L.push_back(b[i][l+1]);
            L=work(L,(i&1)^1);
            if(L.back()==b[i][l+1]) L.pop_back();
            R.insert(R.begin(),b[i][r]);
            R.insert(R.begin(),b[i][r-1]);
            R=work(R,(i&1)^1);
            if(R[0]==b[i][r-1]) R.erase(R.begin());
            l=upper_bound(b[i+1].begin(),b[i+1].end(),b[i][l])-b[i+1].begin();
            r=lower_bound(b[i+1].begin(),b[i+1].end(),b[i][r])-b[i+1].begin()-1;
        }
    }
    return 0;
}