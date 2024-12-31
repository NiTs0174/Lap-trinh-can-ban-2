#include<stdio.h>
#include <stdlib.h>
void Nhapsl(int &n){
	do{
		printf("Nhap so phan tu: ");	scanf("%d",&n);
		if(n <= 0 || n >= 100)
			printf("\nNhap khong hop le, Nhap lai");
	}while(n <= 0 || n >= 100);
}
//a Nhap mang 
void Nhapmang(int *a,int n){
	for(int i=0; i<n; i++){
		printf("Nhap a[%d]: ",i);
		scanf("%d",(a+i));
	}
}
//b Xuat mang
void Xuatmang(int *a,int n){
	for(int i=0; i<n; i++){
		printf("\t%d",*(a+i));
	}
}
//c Tinh tong cac pt
int tongmang(int *a,int n){
	int tong = 0;
	for(int i=0; i<n; i++){
		tong += *(a+i);
	}
	return tong;
}

int main()
{
	int *a;
	int n;
	Nhapsl(n);
	a = (int*)malloc(n*sizeof(int));	//Cap phat bo nho
	Nhapmang(a,n);
	Xuatmang(a,n);
	int tong = tongmang(a,n);
	printf("\nTong cac phan tu co trong mang = %d",tong);
	free(a);	//Giai phong vung nho
	return 0;
}
