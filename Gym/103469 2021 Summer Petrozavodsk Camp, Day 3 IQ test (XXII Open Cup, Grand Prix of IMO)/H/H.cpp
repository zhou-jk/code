#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>k;
    if(k==1)
    {
        cout<<"2 1\n1 2";
        return 0;
    }
    if(k==2)
    {
        cout<<"4 4\n1 2\n1 3\n2 3\n3 4";
        return 0;
    }
    if(k<=20)
    {
        int n=k;
        vector<pair<int,int>>edge;
        for(int i=2;i<=n;i++)
            edge.emplace_back(i,i-1);
        edge.emplace_back(n,1);
        int m=edge.size();
        cout<<n<<" "<<m<<"\n";
        for(auto [u,v]:edge)
            cout<<u<<" "<<v<<"\n";
        return 0;
    }
    for(int a=3;a<=20;a++)
        for(int b=1;a+b<=20;b++)
            if((a+4)*(a-1)/2+b-1-1==k)
            {
                vector<pair<int,int>>edge;
                int n=a+b;
                for(int i=1;i<=a;i++)
                    for(int j=i+1;j<=a;j++)
                        edge.emplace_back(i,j);
                for(int j=a+1;j<=a+b;j++)
                    edge.emplace_back(j,j-1);
                edge.emplace_back(a+b,1);
                int m=edge.size();
                cout<<n<<" "<<m<<"\n";
                for(auto [u,v]:edge)
                    cout<<u<<" "<<v<<"\n";
                return 0;
            }
    return 0;
}
