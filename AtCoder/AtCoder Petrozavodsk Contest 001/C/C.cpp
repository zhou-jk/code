#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n;
int col[N];
int query(int i)
{
    if(col[i]!=-1) return col[i];
    cout<<i-1<<endl;
    string s;
    cin>>s;
    if(s=="Vacant") exit(0);
    else if(s=="Male") return col[i]=0;
    else if(s=="Female") return col[i]=1;
    else return col[i]=-1;
}
int main()
{
    cin>>n;
    fill(col+1,col+n+1,-1);
    query(1),query(n);
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if((mid-l+1)%2==(query(l)^query(mid))) r=mid;
        else l=mid;
    }
    return 0;
}