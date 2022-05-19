#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BINSIZE 3
#define NUMLIST 3
#define MAX_MINTERMS 8
#define MAX_DONTCARES 8
#define SIZE 10
#define MAX_IMP 8
#define MAX 20
#define CHKCHAR 1
#define ROWSIZE BINSIZE+CHKCHAR+1
#define POSLEN 4


typedef struct kmap {
	char ar0[SIZE][ROWSIZE];
	char ar1[SIZE][ROWSIZE];
	char ar2[SIZE][ROWSIZE];
	char ar3[SIZE][ROWSIZE];
}Kmap;

int mycomp(const void *p1, const void *p2);

int CompareTerms(const char *ar1, const char *ar2, int size);

char *ConvertToBinary(int num, char *);

int EatReapetedTerms(char list[MAX_IMP][ROWSIZE], char new_list[MAX_IMP][ROWSIZE], int row);
