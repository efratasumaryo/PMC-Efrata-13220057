#include <stdio.h>

int main(){
    int noInst = 0;
    int a = 0;
    int b = 0;
    int c = 4;
    
    while(1 == 1) //sama seperti while true
    { 
        printf("ember 3 liter       ember 5 liter\n");
        printf("      %d                  %d\n",a,b);
        printf("Pilih no instruksi\n");
        printf("1. isi ember 3 liter\n");
        printf("2. isi ember 5 liter\n");
        printf("3. kosongkan ember 3 liter\n");
        printf("4. kosongkan ember 5 liter\n");
        printf("5. tuang isi ember 3 liter ke ember 5 liter\n");
        printf("6. tuang isi ember 5 liter ke ember 3 liter\n");
        printf("\n");
        printf("Nomor instruksi yang dipilih: ");
        scanf("%c", &noInst);
        printf("\n");

        switch(noInst)
        {
            case '1':
                a = 3;
                break;
            case '2':
                b = 5;
                break;
            case '3':
                a = 0;
                break;
            case '4':
                b = 0;
                break;
            case '5':
                if (a+b >= 5){ //saat kondisi ember b penuh
                a = (a+b)-5;
                b = 5;
                }
                else{
                b = a + b;
                a = 0;
                }
                break;
            case '6':
                if (a+b >= 3){ //saat kondisi ember a penuh
                b = (b+a)-3;
                a = 3;
                }
                else{
                int e = a;
                a = b + a;
                b = b - (a - e);
                }
        }
        
        if (a == 4 || b == 4){ //kondisi untuk menyelesaikan loop
            printf("Program ended");
            break;
            }
        }
        
    return 0;
    }

    