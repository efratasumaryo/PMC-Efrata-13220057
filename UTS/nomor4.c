#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define max 255

int pencarian(file){
    char *token;
    int i=0;
    int j=0;
    int parameter;
    char baris[max];
    int nomor[max];
    int nik[max];
    char namaLengkap[max][max];
    char tempatLahir[max][max];
    int tanggalLahir[max];
    int umur[max];
    char jenisKelamin[max][max];
    char golonganDarah[max][max];
    char status[max][max];
    char pekerjaan[max][max];
    char temp[max];
    int temp_no[max];

    while(fgets(baris, sizeof baris, file) != NULL){
        token = strtok(baris,",");
        nomor[i]=atof(token);

        token = strtok(NULL,",");
        nik[i]=atof(token);

        token = strtok(NULL,",");
        strcpy(namaLengkap[i],token);

        token = strtok(NULL,",");
        strcpy(tempatLahir[i],token);

        token = strtok(NULL,",");
        tanggalLahir[i]=atof(token);

        token = strtok(NULL,",");
        umur[i]=atof(token);

        token = strtok(NULL,",");
        strcpy(jenisKelamin[i],token);

        token = strtok(NULL,",");
        strcpy(golonganDarah[i],token);

        token = strtok(NULL,",");
        strcpy(status[i],token);

        token = strtok(NULL,",");
        strcpy(pekerjaan[i],token);

        ++i;
    }
      
    printf("\nSilahkan masukkan parameter yang anda inginkan!");
    printf("\n1. NIK");
    printf("\n2. Nama");
    printf("\n1. Umur");
    printf("\nParameter yang anda inginkan(eg.'1'): ");
    if(parameter == 1){
        printf("\nSilahkan masukkan NIK: ");
        fgets(temp_no,max,stdin);
        strtok(temp_no,"\n");

        while(j<i){
            if(!strcasecmp(temp_no,nik[j])){
                printf("%d. %d %s %s %d %d %s %s %s %s",nomor[j],nik[j],namaLengkap[j],tempatLahir[j]
                ,tanggalLahir[j],umur[j],jenisKelamin[j],golonganDarah[j],status[j],pekerjaan[j]);;
            }
            else
                ++j;
        }
    }
    if(parameter == 2){
        printf("\nSilahkan masukkan Nama Lengkap: ");
        fgets(temp,max,stdin);
        strtok(temp,"\n");

        while(j<i){
            if(!strcasecmp(temp_no,nik[j])){
                printf("%d. %d %s %s %d %d %s %s %s %s",nomor[j],nik[j],namaLengkap[j],tempatLahir[j]
                ,tanggalLahir[j],umur[j],jenisKelamin[j],golonganDarah[j],status[j],pekerjaan[j]);;
            }
            else
                ++j;
        }
    }
    if(parameter == 3){
        printf("\nSilahkan masukkan Umur: ");
        fgets(temp_no,max,stdin);
        strtok(temp_no,"\n");

        while(j<i && !found){
            if(!strcasecmp(temp_no,nik[j])){
                printf("%d. %d %s %s %d %d %s %s %s %s",nomor[j],nik[j],namaLengkap[j],tempatLahir[j]
                ,tanggalLahir[j],umur[j],jenisKelamin[j],golonganDarah[j],status[j],pekerjaan[j]);;
            }
            else
                ++j;
        }
    }
    else
        NULL;
    
    return 0;
}

int main(){

    int menu_utama;
    int sub_1;
    printf("--SELAMAT DATANG DI PROGRAM PENCATATAN DATA KEPENDUDUKAN--\n");
    printf("Silahkan Import data kependudukan terlebih dahulu!!\n");

        char nama_file[]="";
        FILE* file;
        printf("Masukkan nama file: ");
	    scanf("%s", nama_file);
	    file = fopen(nama_file,"r");

    while(file != NULL){
        printf("Silahkan pilih apa yang ingin anda lakukan!\n");
        printf("1. Mengubah data\n");
        printf("2. Pencarian data\n");
        printf("Silahkan input nomor yang anda inginkan(eg.'1'): ");
        scanf("%d",menu_utama);

        if(menu_utama == 1){
            printf("Silahkan pilih apa yang ingin anda lakukan!\n");
            printf("1. Membuat data baru\n");
            printf("2. Mengubah data\n");
            printf("3. Menghapus data\n");
            printf("Silahkan input nomor yang anda inginkan(eg.'1'): ");
            scanf("%d",sub_1);
        }
        if(menu_utama == 2){
            pencarian(file);
        }
    }
    return 0;
}