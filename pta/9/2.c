#include <stdio.h>
#include <string.h>

int main()
{
    char s[10001];
    scanf("%s", s);
    int n = strlen(s);
    int g = 0, p = 0, l = 0, t = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == 'G' || s[i] == 'g')
            g++;
        else if (s[i] == 'P' || s[i] == 'p')
            p++;
        else if (s[i] == 'L' || s[i] == 'l')
            l++;
        else if (s[i] == 'T' || s[i] == 't')
            t++;
    while(g>0||p>0||l>0||t>0)
    {
        if(g>0)
        {
            printf("G");
            g--;
        }
        if(p>0)
        {
            printf("P");
            p--;
        }
        if(l>0)
        {
            printf("L");
            l--;
        }
        if(t>0)
        {
            printf("T");
            t--;
        }
    }
    return 0;
}