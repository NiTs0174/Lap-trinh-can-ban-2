#include<stdio.h>
int main()
{
//Cau a
	int a;
	printf("Moi nhap 1 so nguyen: ");
	scanf("%d",&a);
	printf("So nguyen da nhap la %d",a);
//Cau b
	float b;
	printf("\nMoi nhap 1 so thuc: ");
	scanf("%f",&b);
	printf("So thuc da nhap la %f",b);
//Cau c
	char z;
	printf("\nMoi nhap 1 ky tu: ");
	fflush(stdin);
	scanf("%c",&z);
	printf("Ky tu da nhap la %c",z);
//Cau d
	int x,y;
	printf("\nMoi nhap hai so nguyen thuc hien phep tinh: ");
	scanf("%d%d",&x,&y);
	printf("\nTong hai so la: %d",x+y);
	printf("\nHieu hai so la: %d",x-y);
	printf("\nTich hai so la: %d",x*y);
	printf("\nThuong hai so la: %f",(float)x/y);
	return 0;
}
