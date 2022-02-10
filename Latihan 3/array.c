#include<stdio.h>  
#include <string.h>  

struct mahasiswa{    
    char nim[8];
    char nama[255];
    int persentase_kehadiran;    
}; 

int main(){    
    int i;    
    struct mahasiswa st[5];    
    printf("Masukkan data 5 mahasiswa");    
    for(i=0;i<2;i++){    
        printf("\nMasukkan NIM:");    
        scanf("%s",&st[i].nim);    
        printf("Masukkan Nama:");    
        scanf("%s",&st[i].nama);
        printf("Masukkan Persentase Kehadiran:");    
        scanf("%d",&st[i].persentase_kehadiran);    
    }    
    printf("\nMahasiswa yang kehadiran kurang dari 80 persen:");    
    for(i=0;i<5;i++){  
        if (st[i].persentase_kehadiran < 80){
            printf("\nNIM:%s, Nama:%s, Kehadiran:%d", st[i].nim,st[i].nama, st[i].persentase_kehadiran);     
        }    
    }    
    return 0;    
}    