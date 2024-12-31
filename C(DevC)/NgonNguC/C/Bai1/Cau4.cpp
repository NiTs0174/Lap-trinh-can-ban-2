#include<stdio.h>
#define PI 3.14
int main()
{
	float r;
	printf("Nhap ban kinh hinh tron: ");
	scanf("%f",&r);
	float CV = 2*PI*r; 
	float S = PI *r*r; 
	printf("Chu vi hinh tron la %f",CV);
	printf("\nDien tich hinh tron la %f",S);
	return 0;
}
