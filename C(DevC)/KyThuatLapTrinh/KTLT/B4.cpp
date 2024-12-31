#include<stdio.h>
#include <stdlib.h>
typedef struct SinhVien{
	char msv[6];
	char hoten[16];
	float dtb;
}SV;
void Nhap1sv(SV *a){
	printf("\nMa sinh vien: ");	scanf("%s",&a->msv);
	fflush(stdin);	printf("Ho ten: ");	gets(a->hoten);
	printf("Diem trung binh: ");	scanf("%f",&a->dtb);
}
void Xuat1sv(SV *a){
	printf("\n%-6s%-16s%3.1f",a->msv,a->hoten,a->dtb);
}
void Nhapsl(int &n){
	do{
		printf("Nhap so luong sinh vien: ");	scanf("%d",&n);
		if(n < 0)
			printf("\nNhap khong hop le, Nhap lai");
	}while(n < 0);
}
void Nhapds(SV *a,int n){
	for(int i=0; i<n; i++){
		printf("\n\tNhap SV thu %d",i+1);
		Nhap1sv(a+i);
	}
}
void Xuatds(SV *a,int n){
	for(int i=0; i<n; i++){
		Xuat1sv(a+i);
	}
}

int main()
{
	SV *a;
	int n;
	Nhapsl(n);
	a = (SV*)malloc(n*sizeof(SV));
	Nhapds(a,n);
	printf("\n\tDanh sach sinh vien:");
	Xuatds(a,n);
	free(a);
	return 0;
}
