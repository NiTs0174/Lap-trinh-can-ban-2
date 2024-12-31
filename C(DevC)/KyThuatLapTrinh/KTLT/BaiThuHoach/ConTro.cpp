#include<stdio.h>
#include<stdlib.h>
#define MAX 100
//	Dong so dong, so cot
void Nhapdong_cot(int &m,int &n)
{
	do{
		printf("Nhap so dong: ");	scanf("%d",&m);
		printf("Nhap so cot: ");	scanf("%d",&n);
	}while(m <= 0 || n <= 0);
}
//	Nhap ma tran
void NhapMT(int *a,int m,int n)
{
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("a[%d][%d]: ",i,j);
			scanf("%d",(a + i*n + j));
		}
	}
}
//	Xuat ma tran
void XuatMT(int *a,int m,int n)
{
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("\t%d",*(a + i*n +j));
		}
		printf("\n");
	}
}
//a	Tong ma tran
int TongMT(int *a,int m,int n)
{
	int s = 0;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			s += *(a + i*n + j);
		}
	}
	return s;
}
//b	Tim pt lon nhat
int TimMax(int *a,int m,int n)
{
	int max = *a;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(*(a + i*n + j) > max){
				max = *(a + i*n + j);
			}
		}
	}
	return max;
}

int main()
{
	int *a;
	int m,n;
	a = (int*)malloc(m*n);
	Nhapdong_cot(m,n);
	NhapMT(a,m,n);
	XuatMT(a,m,n);
	printf("\nTong cac phan tu tren moi cot: %d",TongMT(a,m,n));
	printf("\nPhan tu lon nhat cua ma tran: %d",TimMax(a,m,n));
	free(a);
	return 0;
}
