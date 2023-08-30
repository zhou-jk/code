#include<iostream>
#include<cstdio>
#include<vector>
#include"ramen.h"
using namespace std;
void Ramen(int N)
{
    int n=N;
    vector<int>a,b;
    for(int i=0;i+1<n;i+=2)
        if(Compare(i,i+1)==1) a.emplace_back(i),b.emplace_back(i+1);
        else a.emplace_back(i+1),b.emplace_back(i);
    if(n%2==1) a.emplace_back(n-1),b.emplace_back(n-1);
    int mx=a[0],mn=b[0];
    for(int i=1;i<(int)a.size();i++)
    {
        if(Compare(a[i],mx)==1) mx=a[i];
        if(Compare(b[i],mn)==-1) mn=b[i];
    }
    Answer(mn,mx);
    return;
}