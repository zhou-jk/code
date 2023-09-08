#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include"xylophone.h"
using namespace std;
void solve(int N)
{
    int n=N;
    vector<int>a(n);
    vector<int>d1(n-1),d2(n-2);
    for(int i=0;i<n-1;i++)
        d1[i]=query(i+1,i+1+1);
    for(int i=0;i<n-2;i++)
        d2[i]=query(i+1,i+2+1);
    a[0]=0,a[1]=d1[0];
    for(int i=0;i<n-2;i++)
        if(d2[i]==d1[i]+d1[i+1])
        {
            if(a[i+1]>a[i]) a[i+2]=a[i+1]+d1[i+1];
            else a[i+2]=a[i+1]-d1[i+1];
        }
        else
        {
            if(a[i+1]>a[i]) a[i+2]=a[i+1]-d1[i+1];
            else a[i+2]=a[i+1]+d1[i+1];
        }
    int v=*min_element(a.begin(),a.end());
    for(int i=0;i<n;i++)
        a[i]+=-v+1;
    int mn=min_element(a.begin(),a.end())-a.begin(),mx=max_element(a.begin(),a.end())-a.begin();
    if(mn>mx)
    {
        for(int i=0;i<n;i++)
            a[i]=n-a[i]+1;
    }
    for(int i=0;i<n;i++)
        answer(i+1,a[i]);
    return;
}