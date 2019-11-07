#include<iostream>
#include<cstdio>
using namespace std;
int n;
bool book[1025]={1};
int main()
{
    scanf("%d",&n);
    for(int i=0;i<(1<<n);i++)
	{
        for(int j=1;j<(1<<n)-i;j++)
			putchar(' ');
        for(int j=i;j>=0;j--)
			book[j]^=book[j-1];
        if(!(i&1))
			for(int j=0;j<=i;j++)
				if(book[j]) printf("/\\");
				else printf("  ");
        else
			for(int j=0;j<=i;j+=2)
				if(book[j]) printf("/__\\");
				else printf("    ");
        putchar('\n');
    }
    return 0;
}