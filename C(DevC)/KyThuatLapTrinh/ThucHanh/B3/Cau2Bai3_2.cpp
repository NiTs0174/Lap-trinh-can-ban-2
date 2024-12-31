#include<stdio.h>
#include <stdlib.h>
//#define MAX 100
void Nhapsl(int &m,int &n){
	do{
		printf("Nhap so dong: ");	scanf("%d",&m);
		printf("Nhap so cot: ");	scanf("%d",&n);
	}while(m,n <= 0 || m,n >= 100);
}
//a Nhap ma tran
void Nhapmt(int *a,int m,int n){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("Nhap a[%d][%d]: ",i,j);
			scanf("%d",(a + n*i + j));
		}
	}
}
//b Xuat ma tran
void Xuatmt(int *a,int m,int n){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("\t%d",*(a+ i*n + j));
		}
	printf("\n");
	}
}
//c Tinh tong cac pt
int tongmt(int *a,int m,int n){
	int tong = 0;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			tong += *(a+ i*n +j);
		}
	}
	return tong;
}

int main()
{
	int *a;
	int m,n;
	Nhapsl(m,n);
	a = (int*)malloc(n*sizeof(int));	//Cap phat bo nho
	Nhapmt(a,m,n);
	Xuatmt(a,m,n);
	int tong = tongmt(a,m,n);
	printf("\nTong cac phan tu co trong ma tran = %d",tong);
	free(a);	//Giai phong vung nho
	return 0;
}
