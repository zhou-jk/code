#include <stdio.h>
#include <string.h>

int main()
{
    char str[20002];
    scanf("%s", str);
    int len = strlen(str);
    int n;
    scanf("%d", &n);
    char tmp[20002];
    for (int t = 1; t <= n; t++)
    {
        int ps, pt;
        char pre[7], suf[7];
        scanf("%d%d%s%s", &ps, &pt, pre, suf);
        ps--, pt--;
        int lenp = strlen(pre), lens = strlen(suf);
        int lent = pt - ps + 1;
        for (int i = 0; i < lent; i++)
            tmp[i] = str[i + ps];
        tmp[lent] = '\0';
        for (int i = ps; i + lent <= len; i++)
            str[i] = str[i + lent];
        len -= lent;
        int vis = 0;
        for (int p = lenp; p + lens - 1 < len; p++)
        {
            int book = 1;
            for (int i = 0; i < lenp; i++)
                if (pre[i] != str[i + p - lenp])
                {
                    book = 0;
                    break;
                }
            for (int i = 0; i < lens; i++)
                if (suf[i] != str[i + p])
                {
                    book = 0;
                    break;
                }
            if (book)
            {
                vis = 1;
                for (int i = len; i >= p; i--)
                    str[i + lent] = str[i];
                len += lent;
                for (int i = 0; i < lent; i++)
                    str[i + p] = tmp[i];
                break;
            }
        }
        if (!vis)
        {
            for (int i = 0; i < lent; i++)
                str[i + len] = tmp[i];
            len += lent;
        }
    }
    printf("%s", str);
    return 0;
}