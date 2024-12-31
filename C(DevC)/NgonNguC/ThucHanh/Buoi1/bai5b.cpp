#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("Nhap a: ");
	scanf("%d",&a);
	printf("Nhap b: ");
	scanf("%d",&b);
	printf("Nhap c: ");
	scanf("%d",&c);
	printf("Nhap d: ");
	scanf("%d",&d);
	
	if (a>b && a>c && a>d)
		printf("So lon nhat la a: %d",a);
	if (b>a && b>c && b>d)
		printf("So lon nhat la b: %d",b);
	if (c>b && c>a && c>d)
		printf("So lon nhat la c: %d",c);
	if (d>b && d>c && d>a)
		printf("So lon nhat la d: %d",d);
	return 0;
}
