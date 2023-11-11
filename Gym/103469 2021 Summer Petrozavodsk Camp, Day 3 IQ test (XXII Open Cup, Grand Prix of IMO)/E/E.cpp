#include<iostream>
#include<cstdio>
#include<random>
#include<chrono>
using namespace std;
int n;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    cout<<"? "<<n;
    for(int i=1;i<=n;i++)
        cout<<" "<<i;
    cout<<endl;
    int tot;
    cin>>tot;
    for(int t=1;t<30;t++)
    {
        vector<int>posl,posr;
        for(int i=1;i<=n;i++)
            if(rnd()&1) posl.emplace_back(i);
            else posr.emplace_back(i);
        int kl=posl.size();
        cout<<"? "<<kl;
        for(int u:posl)
            cout<<" "<<u;
        cout<<endl;
        int resl;
        cin>>resl;
        int kr=posr.size();
        cout<<"? "<<kr;
        for(int u:posr)
            cout<<" "<<u;
        cout<<endl;
        int resr;
        cin>>resr;
        if((tot-resl-resr)&1)
        {
            cout<<"! NO"<<endl;
            return 0;
        }
    }
    cout<<"! YES"<<endl;
    return 0;
}
