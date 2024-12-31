#include<stdio.h>
void NhapSL(int &n){
	do{
		printf("So phan tu: ");
		scanf("%d",&n);
	} while(n<=0 || n>=10);
}
//1a Nhap mang
void NhapMang(float a[], int n){
	printf("1a. ");
	for(int i=0; i<n; i++){
		printf("Phan tu a[%d]: ",i);
		scanf("%f",&a[i]);
	}
}
//1b Xuat mang
void XuatMang(float a[],int n){
	printf("1b. ");
	printf("Mang gom cac phan tu: ");
	for(int i=0; i<n; i++)
		printf("%f\t",a[i]);
}
//1d So luong so am
float SLSoAm(float a[], int n){
	int s = 0;
	for(int i=0; i<n; i++)
		if(a[i] < 0)
			s = s + 1;
	return s;
}
//1e Tong cac so
float TongCacSo(float a[],int n){
	float s = 0;
	for(int i=0; i<n; i++)
		s = s + a[i];
	return s;
}
//1f Trung binh cong
float TBC(float a[], int n){
	float s = 0;
	for(int i=0; i<n; i++)
		s = s + a[i];
	return s/n;
}
//1g Trung binh cong so duong
float TBCSoDuong(float a[], int n){
	float s = 0;
	int dem = 0;
	for(int i=0; i<n; i++)
		if(a[i] > 0){
			s = s + a[i];
			dem++;
		}
	return s/dem++;
}

int main()
{
	float a[50];
	int  n;
	NhapSL(n);
//1a
	NhapMang(a,n);
//1b	
	XuatMang(a,n);
//1d
	int sl = SLSoAm(a,n);
	printf("\n1d. So luong so am trong mang: %d",sl);
//1e
	float s = TongCacSo(a,n);
	printf("\n1e. Tong cac so trong mang: %f",s);
//1f
	float avg = TBC(a,n);
	printf("\n1f. Trung binh cong cac so trong mang: %f",avg);
//1g
	float avgduong = TBCSoDuong(a,n);
	printf("\n1g. Trung binh cong cac so duong co trong mang: %f",avgduong);
	return 0;
}
