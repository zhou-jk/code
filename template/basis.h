#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct Basis
{
private:
    static const int N=63;
    long long a[N];
    vector<int>b;
public:
    Basis()
    {
        for(int i=0;i<N;i++)
            a[i]=0;
        b.clear();
        return;
    }
    void clear()
    {
        for(int i=0;i<N;i++)
            a[i]=0;
        b.clear();
        return;
    }
    void insert(const long long &x)
    {
        long long t=x;
        for(int i=N-1;i>=0;i--)
            if((t>>i)&1)
            {
                if(a[i]) t^=a[i];
                else
                {
                    for(int j=0;j<i;j++)
                        if((t>>j)&1) t^=a[j];
                    for(int j=i+1;j<N;j++)
                        if((a[j]>>i)&1) a[j]^=t;
                    a[i]=t;
                }
            }
        b.clear();
        for(int i=0;i<N;i++)
            if(a[i]) b.push_back(a[i]);
        return;
    }
    int size()const
    {
        return b.size();
    }
    long long max_xor()const
    {
        long long res=0;
        for(int i=N-1;i>=0;i--)
            res^=a[i];
        return res;
    }
};