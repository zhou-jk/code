#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
template<typename T,typename Compare=less<T>>
struct BIT
{
    int n;
    T a[N];
    T C[N];
    Compare comp;
    BIT(Compare _comp=Compare()):comp(_comp){}
    int lowbit(int x)const
    {
        return x&-x;
    }
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            a[i]=C[i]=0;
        return;
    }
    void init(const T *_a,int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            a[i]=_a[i];
        for(int i=1;i<=n;i++)
        {
            C[i]=a[i];
            for(int j=1;j<lowbit(i);j<<=1)
                C[i]=comp(C[i],C[i-j])?C[i]:C[i-j];
        }
        return;
    }
    void modify(int x,T v)
    {
        a[x]=v;
        for(int i=x;i<=n;i+=lowbit(i))
        {
            C[i]=a[i];
            for(int j=1;j<lowbit(i);j<<=1)
                C[i]=comp(C[i],C[i-j])?C[i]:C[i-j];
        }
        return;
    }
    T query(int l,int r)const
    {
        T res=a[r];
        while(true)
        {
            res=comp(res,a[r])?res:a[r];
            if(r==l) break;
            for(r--;r-lowbit(r)>=l;r-=lowbit(r))
                res=comp(res,C[r])?res:C[r];
        }
        return res;
    }
};
/*

BIT<int,less<int>>T;
BIT<int,greater<int>>T;

*/