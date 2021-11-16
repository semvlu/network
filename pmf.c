#include <stdio.h>
#include <math.h>
int main()
{
    /* 
    Σ[i >= n, ttl] (ttl i) * pow(p, i) * pow(1 - p, ttl - i)
    (ttl i) = (ttl! / i! (ttl - i)!)
    var: i, p, ttl
    */
    long double i, ttl; 
    long double p;
    printf("Enter pkt sw maximum capacity, total users, and percentage: ");
    scanf("%Lf %Lf %Lf", &i, &ttl, &p);

    // ttl!
    double a;
    long double ttlf = 1; 
    for (a = 1; a <= ttl; a++)
    {
        ttlf =  ttlf * a;
    }

    // matrix nested loop ≡ Σ
    long double pmf, sumpmf;
    long double n = i, ttli;
    long double c;
    for (i = n; i <= ttl; i++)
    {
        // i!
        long double b;
        long double ifa = 1;
        for (b = 1; b <= i; b++)
        {
            ifa =  ifa * b;
        }

        // (ttl- i)!
        ttli = ttl - i;
        long double d;
        long double ttlif = 1;
        for (d = 1; d <= ttli; d++)
        {
            ttlif =  ttlif * d;
        }

        c  = (long double) ttlf / (ifa * ttlif); // c = (ttl i) = (ttl! / i! (ttl - i)!)
        pmf = (long double) c * pow(p, (long double) i) * pow(1.0 - p, (long double)(ttl - i));
        sumpmf = sumpmf + pmf;
    }
    printf("The probability mass is %Lf.\n", sumpmf);

    return 0;
}