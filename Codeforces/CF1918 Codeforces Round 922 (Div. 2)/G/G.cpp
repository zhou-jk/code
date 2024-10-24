#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1000005;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    if(n==3||n==5)
    {
        cout<<"NO\n";
        return 0;
    }
    vector<int>res;
    if(n%2==0) res={1,2};
    else res={-3,-3,2,1,-1,1,-2};
    for(int i=res.size();i<n;i+=2)
    {
        int a=res[i-2],b=res[i-1];
        res.emplace_back(-b),res.emplace_back(a-b);
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++)
        cout<<res[i]<<" ";
    cout<<"\n";
    return 0;
}