#include <stdio.h>
double cache(int objsize,
int Rdatabwsr, // avg data rate to browser
int RTT,
int Raclink, // access link rate
int a, // proxy switch
float Dinternet, // Internet delay
float Dlan, // LAN delay, ms to s
float Dcache);
   
double cache(int objsize,
int Rdatabwsr, // avg data rate to browser
int RTT,
int Raclink, // access link rate
int a, // proxy switch
float Dinternet, // Internet delay
float Dlan, // LAN delay, ms to s
float Dcache)
{
    /*
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
    */
    
    float lan; // LAN util
    float aclink; // Access Link util
    float D; // total delay

    // Enter 0: w/o proxy, 1: w/ proxy

    if (a == 0)
    {
        lan = Rdatabwsr / 100000000;
        aclink = Rdatabwsr / Raclink;
        D = Dinternet + Dlan + 120; // access link delay = 2min = 120s
        return D;
    }

    else if (a == 1)
    {
        // cache hit rate = 0.4, access link util = 0.6
        Rdatabwsr *= 0.6;
        aclink = Rdatabwsr / Raclink;
        D = 0.6 * (Dinternet + Dlan) + 0.4 * Dcache;
        return D;
    }
}
