#include<stdio.h>
int main()
{
	unsigned int a,b;
	printf("Nhap so nguyen duong co 3 chu so: ");
	scanf("%u",&a);
	b = a%10;
	a = a/10;
	printf("Dao nguoc 3 so la: %u",b);
	b = a%10;
	a = a/10;
	printf("%u",b);
	b = a%10;
	a = a/10;
	printf("%u",b);
	return 0;
}
