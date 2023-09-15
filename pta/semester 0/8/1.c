#include <stdio.h>

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

struct Fraction
{
    int p, q;
};

struct Fraction add(struct Fraction a, struct Fraction b)
{
    struct Fraction c;
    c.q = lcm(a.q, b.q);
    c.p = c.q / a.q * a.p + c.q / b.q * b.p;
    return c;
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Fraction a[100];
    for (int i = 0; i < n; i++)
        scanf("%d/%d", &a[i].p, &a[i].q);
    for (int i = 0; i < n; i++)
    {
        int g = gcd(a[i].p, a[i].q);
        a[i].p /= g, a[i].q /= g;
    }
    struct Fraction res = a[0];
    for (int i = 1; i < n; i++)
        res = add(res, a[i]);
    res.q *= n;
    int g = gcd(res.p, res.q);
    res.p /= g, res.q /= g;
    if (res.q == 1)
        printf("%d", res.p);
    else
        printf("%d/%d", res.p, res.q);
    return 0;
}