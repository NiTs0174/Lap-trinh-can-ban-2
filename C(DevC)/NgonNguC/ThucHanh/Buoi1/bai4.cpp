#include<stdio.h>
int main()
{
	float r;
	printf("Nhap ban kinh hinh tron: ");
	scanf("%f", &r);
	
	printf("Chu vi hinh tron la %f", 2*r*3.14);
	printf("\nDien tich hinh tron la %f", r*r*3.14);
	return 0;
}
