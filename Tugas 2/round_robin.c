#include "stdio.h"

void main(){
    int waktu_kuantum,banyak_proses;
    printf("Round Robin Scheduling");
    printf("\nMasukkan waktu kuantum (ms) : ");
    scanf("%d", &waktu_kuantum);
    printf("Berapa proses yang dilakukan : ");
    scanf("%d", &banyak_proses);

    int i,j;
    int sum_eksekusi = 0;
    int arrray_proses [banyak_proses];
    int array_waktu_kedatangan [banyak_proses];
    int array_waktu_eksekusi [banyak_proses];

    for(i=0;i<banyak_proses;i++){
        printf("Waktu kedatangan proses ke-%d : ",i);
        scanf("%d", &array_waktu_kedatangan[i]);
        printf("Waktu eksekusi proses ke-%d : ",i);
        scanf("%d", &array_waktu_eksekusi[i]);
        sum_eksekusi += array_waktu_eksekusi[i];
    }

    printf("-------------------------");
    for(j=0;j<sum_eksekusi;j++){
        
    }
}