#include<stdio.h>
#include<math.h>
int main()
{
	unsigned int a,b,c,CV;
	float p,s;
	printf("Nhap a: ");
	scanf("%u",&a);
	
	printf("Nhap b: ");
	scanf("%u",&b);
	
	printf("Nhap c: ");
	scanf("%u",&c);
	
	if (a+b>c && a+c>b && b+c>a)
		CV= a+b+c;
		printf("Chu vi HCN la %u\n",CV);
		p=(a+b+c)/2;
		s= sqrt(p*(p-a)*(p-b)*(p-c));
		printf("Dien tich HCn la %f", s);
	return 0;
}
