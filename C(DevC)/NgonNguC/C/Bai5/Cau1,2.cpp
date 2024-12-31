#include<stdio.h>
void NhapSL(int &n){
	do{
		printf("Nhap so phan tu: ");
		scanf("%d",&n);	
	} while(n<=0 || n>=10);
}
//1a Nhap mang
void NhapMang(int a[], int n){
	printf("1a.");
	for(int i=0; i<n; i++){
		printf("\tPhan tu a[%d]: ",i);
		scanf("%d",&a[i]);
	}
}
//1b Xuat mang
void XuatMang(int a[],int n){
	printf("1b. Cac phan tu trong mang: ");	
	for(int i=0; i<n; i++)
		printf("%d\t",a[i]);
}
//2a Chia het cho 3
void Cau2a(int a[],int n){
	for(int i=0; i<n; i++)	
		if(a[i] % 3 == 0)
			printf("%d\t",a[i]);
}
//2b So luong so duong
int Cau2b(int a[], int n){	
	long s = 0;	
	for(int i=0; i<n; i++)	
		if(a[i] > 0)
			s = s + 1;
	return s;
}
//2c Tong cac so
int Cau2c(int a[],int n){
	long s = 0;
	for(int i=0; i<n; i++)
		s = s + a[i];
	return s;
}
//2d Trung binh cong
float Cau2d(int a[], int n){
	long s = 0;	
	for(int i=0; i<n; i++)
		s = s + a[i];
	return (float)s/n; 
}
//2e Trung binh cong so duong
float Cau2e(int a[],int n){
	long s = 0;
	int d = 0;	
	for(int i=0; i<n; i++)
		if(a[i] > 0){
			s = s + a[i];
			d = d + 1;
		}
	return (float)s/d;
}
//Kiem tra nguyen to
int KTNT(int n){
	if(n<2)
		return 0;
	for(int i=2; i<n; i++)
		if(n % i == 0)
			return 0;
	return 1;
}
//2f Xuat cac so nguyen to
int Cau2f(int a[], int n){
	for(int i=0; i<n; i++)	
		if(KTNT(a[i]) == 1)
			printf("%d\t",a[i]);
}
//2g Dem so nguyen to
int Cau2g(int a[], int n){
	int d = 0;	
	for(int i=0; i<n; i++)
		if(KTNT(a[i]) == 1)
			d = d + 1;
	return d;
}
//2h Tong cac so nguyen to
int Cau2h(int a[], int n){	
	int s = 0;	
	for(int i=0; i<n; i++)
		if(KTNT(a[i]) == 1)
			s = s + a[i];
	return s;
}
//2i trung binh cong cac so nguyen to
float Cau2i(int a[], int n){
	long s = 0;
	int d = 0;
	for(int i=0; i<n; i++)	
		if(KTNT(a[i])==1){
			d = d + 1;
			s = s + a[i];
		}
	return (float)s/d;
}
//2j Pt duong dau tien
int Cau2j(int a[], int n){	
	for(int i=0; i<n; i++)	
		if(a[i] > 0)
			return a[i];
	return -1;
}
//2k Pt duong cuoi cung
int Cau2k(int a[], int n){	
	for(int i=n-1; i>0; i--)
		if(a[i] > 0)
			return a[i];	
	return -1;	
}
//2l Gia tri lon nhat
int Cau2l1(int a[], int n){	
	int max = a[0];
	for(int i=0; i<n; i++)
		if(max < a[i])
			max = a[i];
	return max;	
}
//	Gia tri nho nhat
int Cau2l2(int a[], int n){	
	int min = a[0];	
	for(int i=0; i<n; i++)	
		if(a[i] < min)
			min = a[i];
	return min;
}

int main()
{
	int a[50], n;
	NhapSL(n);
//1a
	NhapMang(a,n);	
//1b	
	XuatMang(a,n);
//2a
	printf("\n2a. Cac so chia het cho 3: ");
	Cau2a(a,n);
//2b
	long sl = Cau2b(a,n);	
	printf("\n2b. So luong so duong trong mang: %ld",sl);
//2c
	long tong = Cau2c(a,n);	
	printf("\n2c. Tong cac so trong mang: %ld",tong);
//2d
	float tbc = Cau2d(a,n);
	printf("\n2d. Trung binh cong cac so trong mang: %f",tbc);
//2e
	float tbcduong = Cau2e(a,n);
	printf("\n2e. Trung binh cong cac so duong co trong mang: %f",tbcduong);
//2f
	printf("\n2f. Cac so nguyen to trong mang: ");
	Cau2f(a,n);
//2g
	int demnt = Cau2g(a,n);
	printf("\n2g. Dem cac so nguyen to trong mang %d",demnt);
//2h
	int tongnt = Cau2h(a,n);
	printf("\n2h. Tong cac so nguyen to trong mang %d",tongnt);
//2i
	float tbnt = Cau2i(a,n);
	printf("\n2i. Trung binh cac so nguyen to trong mang: %f",tbnt);
//2j
	int x = Cau2j(a,n);
	printf("\n2j. Phan tu duong dau tien co gia tri %d",x);
//2k
	int y = Cau2k(a,n);
	printf("\n2k. Phan tu duong cuoi cung co gia tri %d",y);
//2l
	int max = Cau2l1(a,n);
	printf("\n2l. Gia tri pt lon nhat la %d",max);
//
	int min = Cau2l2(a,n);
	printf("\n    Gia tri pt nho nhat la %d",min);
	return 0;
}
