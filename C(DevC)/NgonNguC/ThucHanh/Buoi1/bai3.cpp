#include<stdio.h>
int main()
{
	int a;
	float b;
	char z;
	printf("Nhap so nguyen: ");
	scanf("%d",&a);
	
	printf("Nhap so thuc: ");
	scanf("%f",&b);
	
	fflush(stdin);
	printf("Nhap ky tu: ");
	scanf("%c",&z);
	printf("So nguyen: %d, So thuc: %f, Ky tu: %c",a,b,z);
	
	
	int x,y;
	printf("\nNhap x: ",x);
	scanf("%d",&x);
	printf("Nhap y: ",y);
	scanf("%d",&y);
	
	printf("Tong la: %d",x+y);
	printf("\nHieu la: %d",x-y);
	printf("\nTich la: %d",x*y);
	printf("\nThuong la: %d",x/y);
	return 0;
}
