#include <stdio.h>
#include <math.h>

// konversi dari desimal ke dalam binary 8-bit
long long convertDectoBin(int n){
    long long bin = 0;
    int rem, i = 1;
    while (n > 255){
        n -= 256;
    }

    while (n != 0){
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}

// Konversi dari binary ke dalam desimal
int convertBintoDec(long long n) {
  int dec = 0, i = 0, rem;

  while (n > 11111111){
        n -= 100000000;
    }

  while (n != 0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
    }
    return dec;
}

int main(){
    signed int x, y;
    int A, hasil;
    int n = 1;

    printf("Masukkan nilai A: ");
    scanf("%d",&A);

    x = 10100101;
    y = 11101111;
    x = convertBintoDec(x);
    y = convertBintoDec(y);
    hasil = (A & y) ^ x;
    printf("\nHasil operasi %d  dalam binary 8-bit adalah %lld", n, convertDectoBin(hasil));
    n += 1;

    x = 11011011;
    y = 11110011;
    x = convertBintoDec(x);
    y = convertBintoDec(y);
    hasil = (~(y >> 4) && x) + A;
    printf("\nHasil operasi %d  dalam binary 8-bit adalah %lld", n, convertDectoBin(hasil));
    n += 1;

    x = 101111;
    y = 10100101;
    x = convertBintoDec(x);
    y = convertBintoDec(y);
    hasil = ((x >> 2) | y) * A;
    printf("\nHasil operasi %d  dalam binary 8-bit adalah %lld", n, convertDectoBin(hasil));

    return 0;
}