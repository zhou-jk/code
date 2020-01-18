#include<iostream>
#include<cstdio>
using namespace std;
string str[10]={"-|| ||-","  |  | ","- |-| -","- |- |-"," ||- | ","-| - |-","-| -||-","- |  | ","-||-||-","-||- |-"},s;
int k;
int main()
{
    cin>>k>>s;
    for(int i=0;i<7;i++)
    {
        if(i==2||i==5) continue;
        if(i==0||i==3||i==6)
        {
            for(int j=0;j<s.size();j++)
            {
                putchar(' ');
                for(int t=0;t<k;t++)
                    putchar(str[s[j]-'0'][i]);
                putchar(' ');
                putchar(' ');
            }
            putchar('\n');
        }
        else
            for(int j=0;j<k;j++)
            {
                for(int t=0;t<s.size();t++)
                {
                	putchar(str[s[t]-'0'][i]);
                    for(int l=0;l<k;l++)
                        putchar(' ');
                    putchar(str[s[t]-'0'][i+1]);
					putchar(' ');
                }
                putchar('\n');
            }
    }
    return 0;
}