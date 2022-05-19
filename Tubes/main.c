/* Tugas Besar Pemecahan Masalah dengan C
Nama Anggota Kelompok:
Muhammad Daris Nurhakim (13220047)
Raihan Fadhil Yanuarsyah (13220049)
Aloysius Efrata Sumaryo (13220057)
Minimisasi dengan Kmap dalam Sum of Product 3 variable
referensi: https://www.codeproject.com/Articles/37031/Karnaugh-Map-Minimizer-Three-Variables
*/

#include "kmap.h"

int main(){
	// inisialisasi variable
	Kmap ar[NUMLIST] = {""};
	int choice, term, index, index2;
	int i = 0, i2 = 0, i3 = 0, k = 0, n = 0, l = 0, p = 0, p2 = 0, q = 0, q2 = 0, q3 = 0;
	int m, j;
	int temp[MAX_MINTERMS], temp2[MAX_MINTERMS], temp3[MAX_MINTERMS];
	int count = 0, count2 = 0, count_DC = 0, count_ones = 0, rows0 = 0, rows1 = 0 ,rows2 = 0 ,rows3 = 0;
	int _rows0 = 0, _rows1 = 0, _rows2 = 0,_rows3 = 0, __rows0 = 0, __rows1 = 0;
	int bit_pos;
	int store_index[MAX];
	int store_index2[MAX];
	char ch = 'a';
	char tempchr;
	char str[MAX_MINTERMS] = {'\0'};
	char prime_imp[MAX_IMP][ROWSIZE] = {""};
	char prime_imp2[MAX][ROWSIZE] = {""};
	char binary[BINSIZE+1] = {'\0'};
	char store_inputs[MAX_MINTERMS][BINSIZE+1] = {""};
	char dont_care[MAX_MINTERMS][BINSIZE+1] = {""};
	char prime_imp_bin[ROWSIZE] = {""};
	char ess_pri_imp[MAX_IMP][ROWSIZE] = {""};
	char ess_pri_imp2[MAX_IMP][ROWSIZE] = {""};
	char ess_pri_imp3[MAX_IMP][ROWSIZE] = {""};
	char POS[MAX][POSLEN] = {""};
	char POS2[MAX][POSLEN+1] = {""};
	char POS3[MAX][(POSLEN+3)*2 + 1] = {""};
	int dashes = 0;
	int last_pos;
	int unrepeated_terms;
	int unrepeated_terms2;
	int unrepeated_terms3 = 0;
	bool check = false;

	// input
	printf("Masukkan minterm pertama (q untuk selesai):  ");
	while (scanf("%d",&term)){
		temp[i++] = term;
		if (i == MAX_MINTERMS)
			break;
		printf("Masukkan minterm berikutnya (q untuk selesai):  ");
	}
	fflush(stdin);

	printf("\nMasukkan don't care term pertama (q untuk selesai):  ");
	while (scanf("%d",&term)){
		temp[i] = term;
		temp2[i2] = term;
		ConvertToBinary(temp2[i2], binary);
		strcpy(dont_care[i2++], binary);
		if (i == MAX_MINTERMS)
			break;
		printf("Masukkan don't care term berikutnya (q untuk selesai):  ");
		i++;
	}
	fflush(stdin);

	for (index = 0; index < i; index++){
		ConvertToBinary(temp[index], binary);

		strcpy(store_inputs[n++],binary);

		for (j = 0; j < BINSIZE; j++)
			if (binary[j] == '1')
				count_ones++;

		if (count_ones == 0)
			strcpy(ar[0].ar0[rows0++], binary);
		else if (count_ones == 1)
			strcpy(ar[0].ar1[rows1++], binary);
		else if (count_ones == 2)
			strcpy(ar[0].ar2[rows2++], binary);
		else if (count_ones == 3)
			strcpy(ar[0].ar3[rows3++], binary);
		count_ones = 0;
	}

	if (rows0 > 0 && rows1 > 0){
		for (index = 0; index < rows1; index++){
			bit_pos = CompareTerms(ar[0].ar0[0], ar[0].ar1[index], BINSIZE);
			if (bit_pos != -1){
				for (j = 0; j < BINSIZE; j++){
					if (j == bit_pos)
						ar[1].ar0[_rows0][j] = '-';
					else
						ar[1].ar0[_rows0][j] = ar[0].ar1[index][j];
				}
				ar[0].ar0[0][BINSIZE] = 't'; 
				ar[0].ar0[0][BINSIZE+CHKCHAR] = '\0';
				ar[0].ar1[index][BINSIZE] = 't';
				ar[0].ar1[index][BINSIZE+CHKCHAR] = '\0';
				ar[1].ar0[_rows0][BINSIZE+CHKCHAR] = '\0';
				_rows0++;
			}
			else{
				if (ar[0].ar0[0][BINSIZE] != 't')
					ar[0].ar0[0][BINSIZE] = '*'; 
				ar[0].ar0[0][BINSIZE+CHKCHAR] = '\0';
				if (ar[0].ar1[index][BINSIZE] != 't')
					ar[0].ar1[index][BINSIZE] = '*';
				ar[0].ar1[index][BINSIZE+CHKCHAR] = '\0';
			}
		}
	}
	else if (rows0 > 0 && !rows1){
		ar[0].ar0[0][BINSIZE] = '*'; 
		ar[0].ar0[0][BINSIZE+CHKCHAR] = '\0';
	}

	_rows0 = EatReapetedTerms(ar[1].ar0, ar[1].ar0, _rows0);	

	if (rows1 > 0 && rows2 > 0){
		for (index2 = 0; index2 < rows1; index2++){
			for (index = 0; index < rows2; index++ ){
				bit_pos = CompareTerms(ar[0].ar1[index2], ar[0].ar2[index], BINSIZE);
				if (bit_pos != -1){
					for (j = 0; j < BINSIZE; j++){
						if (j == bit_pos)
							ar[1].ar1[_rows1][j] = '-';
						else
							ar[1].ar1[_rows1][j] = ar[0].ar2[index][j];

					}
					ar[0].ar1[index2][BINSIZE] = 't'; 
					ar[0].ar1[index2][BINSIZE+CHKCHAR] = '\0';
					ar[0].ar2[index][BINSIZE] = 't';
					ar[0].ar2[index][BINSIZE+CHKCHAR] = '\0';
					ar[1].ar1[_rows1][BINSIZE+CHKCHAR] = '\0';
					_rows1++;
				}
				else{
					if (ar[0].ar1[index2][BINSIZE] != 't')
						ar[0].ar1[index2][BINSIZE] = '*'; 
					ar[0].ar1[index2][BINSIZE+CHKCHAR] = '\0';
					if (ar[0].ar2[index][BINSIZE] != 't')
						ar[0].ar2[index][BINSIZE] = '*';
					ar[0].ar2[index][BINSIZE+CHKCHAR] = '\0';
				}
			}
		}
	}
	else if (rows1 > 0 && !rows2 && !rows0){
		for (index = 0; index < rows1; index++){
			ar[0].ar1[index][BINSIZE] = '*';
			ar[0].ar1[index][BINSIZE+CHKCHAR] = '\0';
		}
	}
	
	_rows1 = EatReapetedTerms(ar[1].ar1, ar[1].ar1, _rows1);

/* ============= Combining third group with fourth group ================ */

	if (rows2 > 0 && rows3 > 0){
		for (index2 = 0; index2 < rows2; index2++){
			for (index = 0; index < rows3; index++ ){
				bit_pos = CompareTerms(ar[0].ar2[index2], ar[0].ar3[index], BINSIZE);
				if (bit_pos != -1){
					for (j = 0; j < BINSIZE; j++){
						if (j == bit_pos)
							ar[1].ar2[_rows2][j] = '-';
						else
							ar[1].ar2[_rows2][j] = ar[0].ar3[index][j];
					}
					ar[0].ar2[index2][BINSIZE] = 't'; 
					ar[0].ar2[index2][BINSIZE+CHKCHAR] = '\0';
					ar[0].ar3[index][BINSIZE] = 't';
					ar[0].ar3[index][BINSIZE+CHKCHAR] = '\0';
					ar[1].ar2[_rows2][BINSIZE+CHKCHAR] = '\0';
					_rows2++;
				}
				else{
					if (ar[0].ar2[index2][BINSIZE] != 't')
						ar[0].ar2[index2][BINSIZE] = '*'; 
					ar[0].ar2[index2][BINSIZE+CHKCHAR] = '\0';
					if (ar[0].ar3[index][BINSIZE] != 't')
						ar[0].ar3[index][BINSIZE] = '*';
					ar[0].ar3[index][BINSIZE+CHKCHAR] = '\0';
				}
			}
		}
	}
	else if (rows2 > 0 && !rows1 && !rows3){
		for (index = 0; index < rows2; index++){
			ar[0].ar2[index][BINSIZE] = '*';
			ar[0].ar2[index][BINSIZE+CHKCHAR] = '\0';
		}
	}
	else if (rows3 > 0 && !rows2){
		ar[0].ar3[0][BINSIZE] = '*'; 
		ar[0].ar3[0][BINSIZE+CHKCHAR] = '\0';
	}

	_rows2 = EatReapetedTerms(ar[1].ar2, ar[1].ar2, _rows2);

/* ============================ Finding the prime implicants in list 1 ================================== */

	if (strchr(ar[0].ar0[0], '*') != NULL){
		for (j = 0; j < BINSIZE; j++)
			prime_imp[k][j] = ar[0].ar0[0][j];
		prime_imp[k++][BINSIZE] = '\0';
	}
	for (index = 0; index < rows1; index++){
		if (strchr(ar[0].ar1[index], '*') != NULL){
			for (j = 0; j < BINSIZE; j++)
				prime_imp[k][j] = ar[0].ar1[index][j];
			prime_imp[k++][BINSIZE] = '\0';
		}
	}
	for (index = 0; index < rows2; index++){
		if (strchr(ar[0].ar2[index], '*') != NULL)
		{
			for (j = 0; j < BINSIZE; j++)
				prime_imp[k][j] = ar[0].ar2[index][j];
			prime_imp[k++][BINSIZE] = '\0';
		}
	}
	if (strchr(ar[0].ar3[0], '*') != NULL){
		for (j = 0; j < BINSIZE; j++)
			prime_imp[k][j] = ar[0].ar3[0][j];
		prime_imp[k++][BINSIZE] = '\0';
	}
	
/* ============================ List 2 ================================================================== */
/* ============= Combining first group with second group ================================================ */
	if (_rows0 > 0 && _rows1 > 0){
		for (index2 = 0; index2 < _rows0; index2++){
			for (index = 0; index < _rows1; index++ ){
				bit_pos = CompareTerms(ar[1].ar0[index2], ar[1].ar1[index], BINSIZE);
				if (bit_pos != -1){
					for (j = 0; j < BINSIZE; j++){
						if (j == bit_pos)
							ar[2].ar0[__rows0][j] = '-';
						else
							ar[2].ar0[__rows0][j] = ar[1].ar1[index][j];
					}
					ar[1].ar0[index2][BINSIZE] = 't'; 
					ar[1].ar0[index2][BINSIZE+CHKCHAR] = '\0';
					ar[1].ar1[index][BINSIZE] = 't';
					ar[1].ar1[index][BINSIZE+CHKCHAR] = '\0';
					ar[2].ar0[__rows0][BINSIZE+CHKCHAR] = '\0';
					__rows0++;
				}
				else{
					if (ar[1].ar0[index2][BINSIZE] != 't')
						ar[1].ar0[index2][BINSIZE] = '*'; 
					ar[1].ar0[index2][BINSIZE+CHKCHAR] = '\0';
					if (ar[1].ar1[index][BINSIZE] != 't')
						ar[1].ar1[index][BINSIZE] = '*';
					ar[1].ar1[index][BINSIZE+CHKCHAR] = '\0';
				}
			}
		}
	}
	else if (_rows0 > 0 && !_rows1){
		for (index = 0; index < _rows0; index++){
			ar[1].ar0[index][BINSIZE] = '*'; 
			ar[1].ar0[index][BINSIZE+CHKCHAR] = '\0';
		}
	}
	
	__rows0 = EatReapetedTerms(ar[2].ar0, ar[2].ar0, __rows0);

/* ============= Combining second group with third group ================ */
	if (_rows1 > 0 && _rows2 > 0){
		for (index2 = 0; index2 < _rows1; index2++){
			for (index = 0; index < _rows2; index++ ){
				bit_pos = CompareTerms(ar[1].ar1[index2], ar[1].ar2[index], BINSIZE);
				if (bit_pos != -1){
					for (j = 0; j < BINSIZE; j++){
						if (j == bit_pos)
							ar[2].ar1[__rows1][j] = '-';
						else
							ar[2].ar1[__rows1][j] = ar[1].ar2[index][j];
					}
					ar[1].ar1[index2][BINSIZE] = 't';
					ar[1].ar1[index2][BINSIZE+CHKCHAR] = '\0';
					ar[1].ar2[index][BINSIZE] = 't';
					ar[1].ar2[index][BINSIZE+CHKCHAR] = '\0';
					ar[2].ar1[__rows1][BINSIZE] = '\0';
					__rows1++;
				}
				else{
					if (ar[1].ar1[index2][BINSIZE] != 't')
						ar[1].ar1[index2][BINSIZE] = '*';
					ar[1].ar1[index2][BINSIZE+CHKCHAR] = '\0';
					if (ar[1].ar2[index][BINSIZE] != 't')
						ar[1].ar2[index][BINSIZE] = '*';
					ar[1].ar2[index][BINSIZE+CHKCHAR] = '\0';
				}
			}
		}
	}
	else if (_rows1 > 0 && !_rows2 && !_rows0){
		for (index = 0; index < _rows1; index++){
			ar[1].ar1[index][BINSIZE] = '*'; 
			ar[1].ar1[index][BINSIZE+CHKCHAR] = '\0';
		}
	}
	else if (_rows2 > 0 && !_rows1){
		for (index = 0; index < _rows2; index++){
			ar[1].ar2[index][BINSIZE] = '*'; 
			ar[1].ar2[index][BINSIZE+CHKCHAR] = '\0';
		}
	}

	__rows1 = EatReapetedTerms(ar[2].ar1, ar[2].ar1, __rows1);

/* ============================ Finding the prime implicants in list 2 ================================== */
	
		for (index = 0; index < _rows0; index++){
			if (strchr(ar[1].ar0[index], '*') != NULL){
				for (j = 0; j < BINSIZE; j++)
					prime_imp[k][j] = ar[1].ar0[index][j];
				prime_imp[k++][BINSIZE] = '\0';
			}
		}
		for (index = 0; index < _rows1; index++){
			if (strchr(ar[1].ar1[index], '*') != NULL){
				for (j = 0; j < BINSIZE; j++)
					prime_imp[k][j] = ar[1].ar1[index][j];
				prime_imp[k++][BINSIZE] = '\0';
			}
		}
		for (index = 0; index < _rows2; index++){
			if (strchr(ar[1].ar2[index], '*') != NULL){
				for (j = 0; j < BINSIZE; j++)
					prime_imp[k][j] = ar[1].ar2[index][j];
				prime_imp[k++][BINSIZE] = '\0';
			}
		}

/* ================================ Finding the prime implicants in list 3 ==================================== */	
	for (index = 0; index < __rows0; index++){
		for (j = 0; j < BINSIZE; j++)
			prime_imp[k][j] = ar[2].ar0[index][j];
		prime_imp[k++][BINSIZE] = '\0';
	}
	for (index = 0; index < __rows1; index++){
		for (j = 0; j < BINSIZE; j++)
			prime_imp[k][j] = ar[2].ar1[index][j];
		prime_imp[k++][BINSIZE] = '\0';
	}

/* ============================ Finding the eseential prime implicants  ======================================= */
	for (index = 0; index < n; index++){
		for (index2 = 0; index2 < i2; index2++){
			if (strcmp(store_inputs[index], dont_care[index2]) == 0)
				strcpy(store_inputs[index], ""); 
		}
	}

	for (index = 0; index < k; index++){
		strcpy(prime_imp_bin, prime_imp[index]);
		for (j = 0; j < BINSIZE; j++){
			if (prime_imp_bin[j] == '-')
				dashes++;
		}

		if (dashes > 1){
			//--------------------------------------- state 1
			for (j = 0; j < BINSIZE; j++)
				if (prime_imp_bin[j] == '-')
					prime_imp_bin[j] = '0';
			for ( m = 0; m < n; m++)
				if (strcmp(store_inputs[m],prime_imp_bin) == 0)
					store_index[l++] = m;
			//--------------------------------------- state 2
			strcpy(prime_imp_bin, prime_imp[index]);
			for (j = 0; j < BINSIZE; j++){
				if (prime_imp_bin[j] == '-' && !check){
					prime_imp_bin[j] = '0';
					check = true;
				}
				if (prime_imp_bin[j] == '-' && check)
					prime_imp_bin[j] = '1';
			}
			for ( m = 0; m < n; m++)
				if (strcmp(store_inputs[m],prime_imp_bin) == 0)
					store_index[l++] = m;
			//--------------------------------------- state 3
			check = false;
			strcpy(prime_imp_bin, prime_imp[index]);
			for (j = 0; j < BINSIZE; j++){
				if (prime_imp_bin[j] == '-' && !check){
					prime_imp_bin[j] = '1';
					check = true;
				}
				if (prime_imp_bin[j] == '-' && check)
					prime_imp_bin[j] = '0';
			}
			for ( m = 0; m < n; m++)
				if (strcmp(store_inputs[m],prime_imp_bin) == 0)
					store_index[l++] = m;
			//--------------------------------------- state 4
			strcpy(prime_imp_bin, prime_imp[index]);
			for (j = 0; j < BINSIZE; j++)
				if (prime_imp_bin[j] == '-')
					prime_imp_bin[j] = '1';
			for ( m = 0; m < n; m++)
				if (strcmp(store_inputs[m],prime_imp_bin) == 0)
					store_index[l++] = m;
			//---------------------------------------
		}
		else{
			strcpy(prime_imp_bin, prime_imp[index]);
			for (j = 0; j < BINSIZE; j++){
				if (prime_imp_bin[j] == '-'){
					//-------------------------------------- state 1
					prime_imp_bin[j] = '0';
					for ( m = 0; m < n; m++)
						if (strcmp(store_inputs[m],prime_imp_bin) == 0)
							store_index[l++] = m;
					//-------------------------------------- state 2
					prime_imp_bin[j] = '1';
					for ( m = 0; m < n; m++)
						if (strcmp(store_inputs[m],prime_imp_bin) == 0)
							store_index[l++] = m;
				}
			}
		}
		check = false;
		dashes = 0;
	}

	qsort(store_index, l, sizeof(int), mycomp);
	
	j = 0;
	for (m = 0; m < l; m++){
		if (store_index[m] == store_index[m+1])
			continue;
		else if (store_index[m] != store_index[m+1] && store_index[m] == store_index[m-1])
			continue;
		else
			store_index2[j++] = store_index[m];
	}

	unrepeated_terms = j;
	check = false;

	for (index = 0; index < k; index++){

		for (j = 0; j < BINSIZE; j++)
			prime_imp_bin[j] = prime_imp[index][j];
		prime_imp_bin[BINSIZE] = '\0';

		for (j = 0; j < BINSIZE; j++){
			if (prime_imp_bin[j] == '-')
				dashes++;
		}

		if (dashes > 1){
			//--------------------------------------- state 1
			for (j = 0; j < BINSIZE; j++)
				if (prime_imp_bin[j] == '-')
					prime_imp_bin[j] = '0';
			for ( m = 0; m < unrepeated_terms; m++){
				if (strcmp(store_inputs[store_index2[m]],prime_imp_bin) == 0){
					prime_imp[index][BINSIZE] = '*';
					prime_imp[index][BINSIZE+CHKCHAR] = '\0';
					strncpy(ess_pri_imp[p++], prime_imp[index], BINSIZE);
				}
			}
			//--------------------------------------- state 2
			for (j = 0; j < BINSIZE; j++)
				prime_imp_bin[j] = prime_imp[index][j];
			prime_imp_bin[BINSIZE] = '\0';
			for (j = 0; j < BINSIZE; j++){
				if (prime_imp_bin[j] == '-' && !check){
					prime_imp_bin[j] = '0';
					check = true;
				}
				if (prime_imp_bin[j] == '-' && check)
					prime_imp_bin[j] = '1';
			}
			for ( m = 0; m < unrepeated_terms; m++){
				if (strcmp(store_inputs[store_index2[m]],prime_imp_bin) == 0){
					prime_imp[index][BINSIZE] = '*';
					prime_imp[index][BINSIZE+CHKCHAR] = '\0';
					strncpy(ess_pri_imp[p++], prime_imp[index], BINSIZE);
				}
			}
			//--------------------------------------- state 3
			check = false;
			for (j = 0; j < BINSIZE; j++)
				prime_imp_bin[j] = prime_imp[index][j];
			prime_imp_bin[BINSIZE] = '\0';
			for (j = 0; j < BINSIZE; j++){
				if (prime_imp_bin[j] == '-' && !check)
				{
					prime_imp_bin[j] = '1';
					check = true;
				}
				if (prime_imp_bin[j] == '-' && check)
					prime_imp_bin[j] = '0';
			}
			for ( m = 0; m < unrepeated_terms; m++){
				if (strcmp(store_inputs[store_index2[m]],prime_imp_bin) == 0){
					prime_imp[index][BINSIZE] = '*';
					prime_imp[index][BINSIZE+CHKCHAR] = '\0';
					strncpy(ess_pri_imp[p++], prime_imp[index], BINSIZE);
				}
			}
			//--------------------------------------- state 4
			for (j = 0; j < BINSIZE; j++)
				prime_imp_bin[j] = prime_imp[index][j];
			prime_imp_bin[BINSIZE] = '\0';
			for (j = 0; j < BINSIZE; j++)
				if (prime_imp_bin[j] == '-')
					prime_imp_bin[j] = '1';
			for ( m = 0; m < unrepeated_terms; m++){
				if (strcmp(store_inputs[store_index2[m]],prime_imp_bin) == 0){
					prime_imp[index][BINSIZE] = '*';
					prime_imp[index][BINSIZE+CHKCHAR] = '\0';
					strncpy(ess_pri_imp[p++], prime_imp[index], BINSIZE);
				}
			}
		}
		else if (dashes == 1){
			for (j = 0; j < BINSIZE; j++)
				prime_imp_bin[j] = prime_imp[index][j];
			prime_imp_bin[BINSIZE] = '\0';
			for (j = 0; j < BINSIZE; j++){
				if (prime_imp_bin[j] == '-'){
					prime_imp_bin[j] = '0';
					for ( m = 0; m < unrepeated_terms; m++){
						if (strcmp(store_inputs[store_index2[m]],prime_imp_bin) == 0){
							prime_imp[index][BINSIZE] = '*';
							prime_imp[index][BINSIZE+CHKCHAR] = '\0';
							strncpy(ess_pri_imp[p++], prime_imp[index], BINSIZE);
						}
					}
					prime_imp_bin[j] = '1';
					for ( m = 0; m < unrepeated_terms; m++){
						if (strcmp(store_inputs[store_index2[m]],prime_imp_bin) == 0){
							prime_imp[index][BINSIZE] = '*';
							prime_imp[index][BINSIZE+CHKCHAR] = '\0';
							strncpy(ess_pri_imp[p++], prime_imp[index], BINSIZE);
						}
					}
				}
			}
		}
		else{
			prime_imp[index][BINSIZE] = '*';
			prime_imp[index][BINSIZE+CHKCHAR] = '\0';
			strncpy(ess_pri_imp[p++], prime_imp[index], BINSIZE);
			p2++;
		}
		check = false;
		dashes = 0;
	}

	unrepeated_terms += p2;

	//Coping the content of ess_pri_imp array to a new array ess_pri_imp2 to avoid stack problems
	for (index = 0; index < unrepeated_terms; index++)
		strcpy(ess_pri_imp2[index], ess_pri_imp[index]);

	unrepeated_terms2 = EatReapetedTerms(ess_pri_imp2, ess_pri_imp2, unrepeated_terms);

	//======================== Petrick's method =============================
	// Step 1 : pick up the rest of prime implicants in the coverage table and marking them with characters (a,b,c,....)
	l = 0;
	check = false;

	for (index = 0; index < k; index++){
		if (strchr(prime_imp[index], '*') != NULL)
			continue;
		else{
			prime_imp[index][BINSIZE] = ch;
			prime_imp[index][BINSIZE+CHKCHAR] = '\0';
			strncpy(prime_imp_bin, prime_imp[index], BINSIZE);
			for (j = 0; j < BINSIZE; j++){
				if (prime_imp_bin[j] == '-')
					dashes++;
			}

			if (dashes > 1){
				//--------------------------------------- state 1
				for (j = 0; j < BINSIZE; j++)
					if (prime_imp_bin[j] == '-')
						prime_imp_bin[j] = '0';
				strcpy(prime_imp2[l], prime_imp_bin);
				prime_imp2[l][BINSIZE] = ch;
				prime_imp2[l++][BINSIZE+CHKCHAR] = '\0';
				//--------------------------------------- state 2
				strncpy(prime_imp_bin, prime_imp[index], BINSIZE);
				for (j = 0; j < BINSIZE; j++){
					if (prime_imp_bin[j] == '-' && !check){
						prime_imp_bin[j] = '0';
						check = true;
					}
					if (prime_imp_bin[j] == '-' && check)
						prime_imp_bin[j] = '1';
				}
				strcpy(prime_imp2[l], prime_imp_bin);
				prime_imp2[l][BINSIZE] = ch;
				prime_imp2[l++][BINSIZE+CHKCHAR] = '\0';
				//--------------------------------------- state 3
				check = false;
				strncpy(prime_imp_bin, prime_imp[index], BINSIZE);
				for (j = 0; j < BINSIZE; j++){
					if (prime_imp_bin[j] == '-' && !check){
						prime_imp_bin[j] = '1';
						check = true;
					}
					if (prime_imp_bin[j] == '-' && check)
						prime_imp_bin[j] = '0';
				}
				strcpy(prime_imp2[l], prime_imp_bin);
				prime_imp2[l][BINSIZE] = ch;
				prime_imp2[l++][BINSIZE+CHKCHAR] = '\0';
				//--------------------------------------- state 4
				strncpy(prime_imp_bin, prime_imp[index], BINSIZE);
				for (j = 0; j < BINSIZE; j++)
					if (prime_imp_bin[j] == '-')
						prime_imp_bin[j] = '1';
				strcpy(prime_imp2[l], prime_imp_bin);
				prime_imp2[l][BINSIZE] = ch;
				prime_imp2[l++][BINSIZE+CHKCHAR] = '\0';
				//---------------------------------------
			}
			else{
				for (j = 0; j < BINSIZE; j++){
					if (prime_imp_bin[j] == '-'){
						//-------------------------------------- state 1
						prime_imp_bin[j] = '0';
						strcpy(prime_imp2[l], prime_imp_bin);
						prime_imp2[l][BINSIZE] = ch;
						prime_imp2[l++][BINSIZE+CHKCHAR] = '\0';
						//-------------------------------------- state 2
						prime_imp_bin[j] = '1';
						strcpy(prime_imp2[l], prime_imp_bin);
						prime_imp2[l][BINSIZE] = ch;
						prime_imp2[l++][BINSIZE+CHKCHAR] = '\0';
					}
				}
			}
			check = false;
			dashes = 0;
			ch++;
		}
	}
	// Step 2 : forming the POS terms using the characters (a,b,c.......)
	for (index = 0; index < l - 1; index++){
		for (index2 = index+1; index2 < l; index2++){
			if (strncmp(prime_imp2[index], prime_imp2[index2], BINSIZE) == 0){
				POS[q][0] = prime_imp2[index][BINSIZE];
				POS[q][1] = '+';
				POS[q][2] = prime_imp2[index2][BINSIZE];
				POS[q++][3] = '\0';
			}
		}
	}
	// Step 3 : multipling the POS terms using this equation (X + Y)(X + Z) = X + YZ
	if (q == 1){
		for (j = 0; j <= BINSIZE; j++){
			ch = POS[0][j];
			if (ch >= 'a' && ch <= 'z'){
				for (index = 0; index < l; index++){
					if (strchr(prime_imp[index], ch) != NULL)
						strncpy(ess_pri_imp3[unrepeated_terms3++], prime_imp[index], BINSIZE);
				}
			}
		}
	}
	else if (q > 1){
		check = false;
		for (index = 0; index < q - 1; index++){
			if (strchr(POS[index], tempchr) != NULL)
				continue;
			for (index2 = index+1; index2 < q; index2++){
				if (strchr(POS[index2], tempchr) != NULL)
					continue;
				for (j = 0; j < POSLEN-1; j++){
					ch = POS[index][j];
					if (ch >= 'a' && ch <= 'z')
						if (strchr(POS[index2], ch) != NULL){
							tempchr = ch;
							POS2[q2][0] = ch;
							POS2[q2][1] = '+';
							if (ch == POS[index][0])
								POS2[q2][2] = POS[index][2];
							else if (ch == POS[index][2])
								POS2[q2][2] = POS[index][0];
							if (ch == POS[index2][0])
								POS2[q2][3] = POS[index2][2];
							else if (ch == POS[index][2])
								POS2[q2][3] = POS[index2][0];
							POS2[q2++][4] = '\0';
							check = true;
						}
				}
				if (check){
					check = false;
					break;
				}
			}
		}
	}
	// Step 4 : Multipling the POS2 terms to form the SOP terms ------
	if (q2 == 1){
		ch = POS2[0][0];
		for (index = 0; index < l; index++){
			if (strchr(prime_imp[index], ch) != NULL)
				strncpy(ess_pri_imp3[unrepeated_terms3++], prime_imp[index], BINSIZE);
		}
	}
	else if (q2 > 1){
		m = 0;
		for (index = 0; index < q2 - 1; index++){
			if (strchr(POS2[index], tempchr) != NULL)
				continue; 
			for (index2 = index+1; index2 < q2; index2++){
				for (j = 2; j < POSLEN; j++){
					ch = POS2[index][j];
					if (strchr(POS2[index2], ch) != NULL){
						l = 0;
						tempchr = ch;
						POS3[q3][m++] = POS2[index][0];
						POS3[q3][m++] = POS2[index2][0];
						POS3[q3][m++] = '+';
						POS3[q3][m++] = ch;
						if (ch == POS2[index][2])
							POS3[q3][l++] = POS2[index][3];
						else if (ch == POS2[index][3])
							POS3[q3][l++] = POS2[index][2];
						if (ch == POS2[index2][2])
							POS3[q3][l++] = POS2[index2][3];
						else if (ch == POS2[index2][3])
							POS3[q3][l++] = POS2[index2][2];
						POS3[q3][m++] = '+';
						POS3[q3][m++] = POS2[index][0];
						POS3[q3][m++] = POS2[index2][2];
						POS3[q3][m++] = POS2[index2][3];
						POS3[q3][m++] = '+';
						POS3[q3][m++] = POS2[index2][0];
						POS3[q3][m++] = POS2[index][2];
						POS3[q3][m++] = POS2[index][3];
						POS3[q3++][(POSLEN+3)*2] = '\0';
						check = true;
					}
				}
				if (check){
					check = false;
					break;
				}
			}
		}
		count = 0;
		for (index = 0; index < q2; index++){
			for (index2 = 0; index2 < q3; index2++){
				if (POS2[index][0] == POS3[index2][0] || POS2[index][0] == POS3[index2][1])
					break;
				else
					count++;
			}
			if (count == q3){
				strcpy(POS3[q3++], POS2[index]);
				break;
			}
			count = 0;
		}
	}

	if (q3 == 1){
		check = false;
		count = 0;
		for (j = 0; j <= strlen(POS3[0]); j++){
			ch = POS3[0][j];
			if (ch >= 'a' && ch <= 'z')
				if (!check)
					count++;
			if (ch == '+')
				check = true;
			if (ch >= 'a' && ch <= 'z')
				if (check)
					count2++;
		}
		if (count < count2){
			for (j = 0; j <= strlen(POS3[0]); j++){
				ch = POS3[0][j];
				if (ch >= 'a' && ch <= 'z'){
					for (index = 0; index < l; index++){
						if (strchr(prime_imp[index], ch) != NULL)
							strncpy(ess_pri_imp3[unrepeated_terms3++], prime_imp[index], BINSIZE);
					}
				}
				if (ch == '+')
					break;
			}
		}
		else{
			check = false;
			for (j = 0; j <= strlen(POS3[0]); j++){
				ch = POS3[0][j];
				if (check){
					if (ch >= 'a' && ch <= 'z'){
						for (index = 0; index < l; index++){
							if (strchr(prime_imp[index], ch) != NULL)
								strncpy(ess_pri_imp3[unrepeated_terms3++], prime_imp[index], BINSIZE);
						}
					}
				}
				if (ch == '+')
					check = true;
			}
		}
	}
	
/* ================================ Diplaying the function ==================================================== */

	if (n == MAX_MINTERMS){
		puts("\n\n   F = 1\n");
		exit(EXIT_SUCCESS);
	}
	else if (n == 0){
		puts("Nothing to display !!!\n");
		exit(EXIT_FAILURE);
	}

	if (unrepeated_terms3 <= 1){
		printf("\n\n   F = ");
		for (index2 = 0; index2 < unrepeated_terms2; index2++){
			for (j = 0; j < BINSIZE; j++){
				switch (j){
				case 0:
					if (ess_pri_imp2[index2][j] == '0')
						printf("(~A)");
					else if (ess_pri_imp2[index2][j] == '1')
						putchar('A');
					break;
				case 1:
					if (ess_pri_imp2[index2][j] == '0')
						printf("(~B)");
					else if (ess_pri_imp2[index2][j] == '1')
						putchar('B');
					break;
				case 2:
					if (ess_pri_imp2[index2][j] == '0')
						printf("(~C)");
					else if (ess_pri_imp2[index2][j] == '1')
						putchar('C');
					break;
				}
			}
			if (index2 % unrepeated_terms2 == index2 && (unrepeated_terms2 - index2) > 1){
				putchar(' ');putchar('+');putchar(' ');
			}
		}
		putchar('\n');
	}	
	else {
		for (index = 0; index < unrepeated_terms3; index++){
			strcpy(ess_pri_imp2[unrepeated_terms2], ess_pri_imp3[index]);
			printf("\n\n   F%d = ",index+1);
			for (index2 = 0; index2 < (unrepeated_terms2 + 1); index2++){
				for (j = 0; j < BINSIZE; j++){
					switch (j){
					case 0:
						if (ess_pri_imp2[index2][j] == '0')
							printf("(~A)");
						else if (ess_pri_imp2[index2][j] == '1')
							putchar('A');
						break;
					case 1:
						if (ess_pri_imp2[index2][j] == '0')
							printf("(~B)");
						else if (ess_pri_imp2[index2][j] == '1')
							putchar('B');
						break;
					case 2:
						if (ess_pri_imp2[index2][j] == '0')
							printf("(~C)");
						else if (ess_pri_imp2[index2][j] == '1')
							putchar('C');
						break;
					}
				}
				if (index2 % (unrepeated_terms2 + 1) == index2 && ((unrepeated_terms2 + 1) - index2) > 1){
					putchar(' ');putchar('+');putchar(' ');
				}
			}
			putchar('\n');
		}
	}
	putchar('\n');putchar('\n');
}