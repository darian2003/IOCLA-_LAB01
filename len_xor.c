#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(const char *str)
{
	int i = 0;
	while( *str !=  '\0') {
		i++;
		str++;
	}
	return i;
}

void equality_check(const char *str)
{	
	int i = 0;
	int len = my_strlen(str);
	printf("%d\n", len);
	while( *(str+i) != '\0') {
	int a = i + (1 << i);
	if ( a >= len ) { 
		a = a % len;
	} 
	if (!( *(str+i) ^ *(str + a ))) {
		printf("%p\n", str+i);
	} 
	i++;
	}
}

int main(void)
{
/*	char *sir = "dadaffa";
	int lungime = my_strlen(sir);
	printf("%d\n", lungime);	
*/
	char *sir = "aac";
//	char *str = "ababababacccbacbacbacbacbabc";
 	equality_check(sir);
 
	return 0;
}

