#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=105;
int n;
char s[N];
struct Matrix
{
    int n;
    vector<vector<int>>c;
    Matrix(){}
    Matrix(const int _n)
    {
        n=_n;
        c.resize(n);
        for(int i=0;i<n;i++)
            c[i].resize(n);
    }
    Matrix rotate()const
    {
        Matrix res(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                res.c[i][j]=c[n-j-1][i];
        return res;
    }
};
bool check(const Matrix &a,const Matrix &b)
{
    if(a.n!=b.n) return false;
    int n=a.n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a.c[i][j]==1&&b.c[i][j]!=1) return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    Matrix a(n),b(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a.c[i][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&b.c[i][j]);
    for(int k=0;k<4;k++)
    {
        if(check(a,b))
        {
            printf("Yes");
            return 0;
        }
        a=a.rotate();
    }
    printf("No");
    return 0;
}