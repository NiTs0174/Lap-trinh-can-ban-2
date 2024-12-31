#include<stdio.h>
#include<math.h>
int main()
{
	unsigned int a,b,c;
	printf("Nhap a: ");	
	scanf("%u",&a);
	printf("Nhap b: ");
	scanf("%u",&b);
	printf("Nhap c: ");
	scanf("%u",&c);
	unsigned int CV = a+b+c;
	float p = CV/2;
	float S = sqrt(p*(p-a)*(p-b)*(p-c));
	if(a+b>c && a+c>b && b+c>a){
		printf("Dien tich hinh tam giac la %f",S);
		printf("\nChu vi hinh tam giac la %u",CV);
	}
	return 0;
}
