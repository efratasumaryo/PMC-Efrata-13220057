#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#define max 255

int main(){
    double e = 1.602e-19;
    double mo = 9.109e-31;
    double c = 2.9979e8;
    double resultc,resultmo,resultm;
    int vlt[max];
    resultc = pow(c,2);
    resultmo = pow(mo,2);


    FILE* file;
    char baris[max];
    char *token;
    int i=0;
    file = fopen("tegangan.txt","r");

    while(fgets(baris, sizeof baris, file) != NULL){
        token = strtok(baris,"\n");
        vlt[i] = atof(token);
        ++i;
    }

    int j=0;
    double m;
    double v_pow;

    for(j=0;j<i;++j){
        m = ((vlt[j]*e)/resultc)+mo;
        resultm = pow(m,2);
        v_pow = resultc-(resultmo*resultc/resultm);
        printf("untuk tegangan ke-%d:\n",j+1);
        printf("m = %e\n",m);
        printf("v = %e\n",sqrt(v_pow));
    }

    fclose(file);

    return 0;
}