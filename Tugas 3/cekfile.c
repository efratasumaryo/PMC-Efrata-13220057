#include "stdio.h"

int main(){
    char nama_file[] = "";
    unsigned char tes[12];
    FILE *file;

    printf("Masukkan nama file : ");
    scanf("%s", nama_file);
    file = fopen(nama_file, "rb");
    
    while(file == NULL){
        printf("File tidak ada. Silahkan input kembali!");
        printf("\nMasukkan nama file : ");
        scanf("%s", nama_file);
        file = fopen(nama_file, "rb");
    }

    fread(tes,sizeof(tes),1,file);
    //pdf = 25 50 44 46
    if((tes[0]==0x25) && (tes[1]==0x50) && (tes[2]==0x44) && (tes[3]==0x46)){
        printf("file merupakan pdf");
    }
    //png = 89 50 4E 47 0D 0A 1A 0A
    else if((tes[0]==0x89) && (tes[1]==0x50) && (tes[2]==0x4E) && (tes[3]==0x47) && (tes[4]==0x0D) && 
    (tes[5]==0x0A) && (tes[6]==0x1A) && (tes[7]==0x0A)){
        printf("file merupakan png");
    }
    //jpg
    return 0;
}