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
    //jpg FF D8 FF DB
    //    FF D8 FF E0 00 10 4A 46 49 46 00 01
    else if(((tes[0]==0xFF) && (tes[1]==0xD8) && (tes[2]==0xFF) && (tes[3]==0xDB)) || ((tes[3]==0xE0) && 
    (tes[4]==0x00) && (tes[5]==0x10) && (tes[6]==0x4A) && (tes[7]==0x46) && (tes[8]==0x49) && (tes[9]==0x46)
    (tes[10]==0x00) && (tes[11]==0x01))){
        printf("file merupakan jpg");
    }
    else{
        printf("file bukan png atau jpg atau pdf");
    }

    fclose(file);

    return 0;
}