#include<stdio.h>
int main()
{
	unsigned int n,tam,tong;
	printf("Nhap so nguyen duong co 3 chu so: ");
	scanf("%u",&n);
	tong = 0;
	tam = n%10;
	tong = tong + tam;
	n = n/10;
	tam = n%10;
	tong = tong*10 + tam;
	n = n/10;
	tam = n%10;
	tong = tong*10 + tam;
	printf("Dao nguoc 3 chu so la: %u",tong);
	return 0;
}
