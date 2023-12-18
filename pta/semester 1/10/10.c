#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[1002];
    while (fgets(s, sizeof(s), stdin))
    {
        int n = strlen(s);
        int vis[21] = {};
        for (int i = 0, j = 0; i < n; i = j)
        {
            while (j < n && s[j] != ',')
                j++;
            int flag = 0;
            int a = atoi(s + i), b = 0;
            for (int k = i; k < j; k++)
                if (s[k] == '-')
                {
                    flag = 1;
                    b = atoi(s + k + 1);
                    break;
                }
            if (flag)
            {
                for (int k = a; k <= b; k++)
                    vis[k] = 1;
            }
            else
                vis[a] = 1;
            j++;
        }
        int cnt = 0;
        for (int i = 1; i <= 20; i++)
            if (vis[i])
            {
                if (cnt >= 1)
                    printf(",");
                cnt++;
                printf("%d", i);
            }
        printf("\n");
    }
    return 0;
}