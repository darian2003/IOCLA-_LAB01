#include <stdio.h>

void rotate_left(int *number, int bits)
{
	int msb;
	bits = bits % 32;
	while(bits) {
		msb = 	*number >> 31;
		msb = msb & 1;
		*number = *number << 1;
		*number = *number | msb;
		bits--;
	}
		printf("%d\n", *number);
}

//la rotatia spre drepata este diferit intrucat daca shiftam spre drepata un numar 
//lucrurile depinde de msb

void rotate_right(int *number, int bits)
{
	int lsb;
	bits = bits % 32;
	while(bits) {
// retin lsb-ulcd
		lsb = *number & 1;

//shiftez numarul la dreapta, insa aceasta operatie depinde de valorea lui msb
		*number = *number >> 1;

//pentru a sumariza, vom numerota bitii de la 0 la 31
//in acest moment, bitii de pe pozitiile 1-30 se muta la dreapta, deci noul numar 
//va avea bitii 0-29 deja stabiliti
//bitul de pe pozitia 0 (lsb) dispare
//bitul de pe poz 31 (msb) isi pastreaza valoarea
//iar in urma shiftarii, pe pozitia 30 va aparea 0 daca initial numarul era > 0
//si 1 daca numarul initial era < 0
//asadar, trebuie doar sa asezam lsb pe pozitia 31 (sa schimbam bitul de semn) 
//pentru ca am stabilit mai sus ca bitul 30 preia valoarea bitului de semn
		int mask;
		mask = lsb << 31;
		*number = *number & ( ~ ( 1 << 31 )); 
		mask = mask | *number;
		*number = mask;
		bits--;
	}
	printf("%d\n", *number);
}

//deoarece lucrez intr un caz general si nu pot sti valorea lui msb si lsb initial
//nu ma pot folosi de operatori bitwise pentru a schimba valorea bitului de semn
//asa ca ma folosesc de o masca unde pun pe  poz 31 lsb-ul, si apoi copiez restul numarului

int main()
{	
	int a = 0x80000000;
	int b = 0x00000001;
	rotate_left(&a, 1);
	rotate_right(&b, 16);
	return 0; 
}


