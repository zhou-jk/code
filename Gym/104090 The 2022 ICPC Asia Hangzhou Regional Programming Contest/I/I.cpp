#include<iostream>
#include<cstdio>
#include<random>
#include<chrono>
#include<unordered_map>
using namespace std;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
int walk(int x)
{
    cout<<"walk "<<x<<endl;
    int res;
    cin>>res;
    return res;
}
void guess(int p)
{
    cout<<"guess "<<p<<endl;
    exit(0);
    return;
}
int rand(int l,int r)
{
    return rnd()%(r-l+1)+l;
}
unordered_map<int,int>book;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int k=3000;
    int t=0;
    for(int i=1;i<=k;i++)
        t=max(t,walk(rand(1,1e9)));
    int sum=0;
    for(int i=1;i<=k;i++)
    {
        int cur=walk(1);
        sum++;
        if(book.count(cur)) guess(sum-book[cur]);
        book[cur]=sum;
    }
    int cur=walk(t);
    sum+=t;
    for(int i=1;i<=k;i++)
    {
        if(book.count(cur)) guess(sum-book[cur]);
        book[cur]=sum;
        cur=walk(k);
        sum+=k;
    }
    return 0;
}