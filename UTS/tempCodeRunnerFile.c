#include "stdio.h"
#include "math.h"

//https://www.programiz.com/c-programming/examples/binary-decimal-convert
int BinaryDecimal(long long n) {
    int dec = 0, i = 0, rem;

    while (n > 11111111){
        n -= 100000000;
    }
    while (n!=0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }

  return dec;
}

long long DecimalBinary(int n) {
    long long bin = 0;
    int rem, i = 1;

    while (n > 255){
        n -= 256;
    }
    while (n!=0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }

    return bin;
}

int main(){
    signed int x,y;
    int a,result;

    printf("Silahkan masukkan nilai A: ");
    scanf("%d",&a);

    x = 10100101;
    x = BinaryDecimal(x);
    y = 11101111;
    y = BinaryDecimal(y);
    result = (a & y)^x;
    printf("\nhasil dalam 8 bit adalah: %lld",DecimalBinary(result));

    x = 11011011;
    x = BinaryDecimal(x);
    y = 11110011;
    y = BinaryDecimal(y);
    result = (~(y >> 4) && x) + a;
    printf("\nhasil dalam 8 bit adalah: %lld",DecimalBinary(result));

    x = 101111;
    x = BinaryDecimal(x);
    y = 10100101;
    y = BinaryDecimal(y);
    result = ((x >> 2) | y) * a;
    printf("\nhasil dalam 8 bit adalah: %lld",DecimalBinary(result));

    return 0;
}