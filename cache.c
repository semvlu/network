#include <stdio.h>

int main()
{
    int objsize = 1000000;
    int Rdatabwsr = 15000000; // avg data rate to browser
    int RTT = 2;
    int Raclink = 15400000; // access link rate
    int a; // proxy switch
    float lan; // LAN util
    float aclink; // Access Link util
    float D; // total delay
    float Dinternet = 2.0; // Internet delay
    float Dlan = 0.003; // LAN delay, ms to s
    float Dcache = 0.001; // chche delat

    puts("Enter 0: w/o proxy, 1: w/ proxy: ");
    scanf("%d", &a);

    if (a == 0)
    {
        lan = Rdatabwsr / 100000000;
        aclink = Rdatabwsr / Raclink;
        D = Dinternet + Dlan + 120; // access link delay = 2min = 120s
        printf("Total delay are %fs.\n", D);
    }

    else if (a == 1)
    {
        // cache hit rate = 0.4, access link util = 0.6
        Rdatabwsr *= 0.6;
        aclink = Rdatabwsr / Raclink;
        D = 0.6 * (Dinternet + Dlan) + 0.4 * Dcache;
        printf("Total delay are %fs.\n", D);
    }
}