#include "stdlib.h"
#include "stdio.h"
#include "math.h"

int main(){
    int r = 20000;
    float c = 132057e-12;
    float tau,t,vout;
    t=0;

    do{
        vout = 5-5*exp(-t/(r*c));
        printf("nilai tegangan output saat t = %e adalah = %e volt\n",t,vout);
        t += 1 * pow(10,-5);
    }
    while(vout<5);
    
    tau = r*c;
    printf("\nkonstanta waktu dari sistem RC: %e",tau);

    return 0;
}