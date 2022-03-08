#include <stdio.h>
#include <stdlib.h>

void print_binary(int number, int nr_bits)
{	
	printf("0b");
	int u[100];
	int i = 0;
	while( number ) {
		u[i] = number % 2;
		number = number / 2;
		i++;
	}
	int j = i;
	int a = nr_bits;	
       	while ( a > i) {
 		printf("0");
		a--;
	}
	for(j = i-1; j >= 0; j--) {
		printf("%d",u[j]);
	}
	printf("\n");	
}

void check_parity(int *numbers, int n)
{	
	int i = 0;
	int maxx = 0;
	int v[100];
	while( i < n ) {
		int count = 0;
		int c = *(numbers+i);
		if(*(numbers+i) % 2 == 0 ) {
			while ( c ) {
				c = c/2;
				count++;
			}
		v[i] = count;
		} else {
			while ( c ) {
				c = c /16;
				count++;
			}
		v[i] = count;
		}
		if ( count > maxx ) maxx = count;
		i++;
		}
	printf("%d\n", maxx);
	for(i = 0 ; i < n ; i++ ) {
		if ( *(numbers + i) % 2 == 1 ) {
			int c = *(numbers + i);
			printf("0x");
			for(int j = maxx - v[i];  j > 0; j--) {
				printf("0");
			}
			printf("%x\n", c);
		} else {
		       print_binary(*(numbers + i), maxx);	       
		}	
	}
}


//pentru aceasta problema voi presupune ca nu primim numere neative la intrare
//(ar fi prea lungi numerele negative scrise pe 32 biti)
int main()
{
	int v[5] = {214, 71, 84 ,134, 86}; 

	check_parity( v, 5);	
	 
	return 0;
} 

