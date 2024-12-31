#include<stdio.h>
void NhapSL(int &n){
	do{
		printf("So phan tu: ");
		scanf("%d",&n);
	} while(n<=0 || n>=10);
}
//1a Nhap mang
void NhapMang(int a[], int n){
	printf("1a. ");
	for(int i=0; i<n; i++){
		printf("Phan tu a[%d]: ",i);
		scanf("%d",&a[i]);
	}
}
//1b Xuat mang
void XuatMang(int a[],int n){
	printf("1b. ");
	printf("Mang gom cac phan tu: ");
	for(int i=0; i<n; i++)
		printf("%d\t",a[i]);
}
//1c Chia het cho 3
void ChiaHet3(int a[],int n){
	for(int i=0; i<n; i++)
		if(a[i] % 3 == 0)
			printf("%d\t",a[i]);
}
//1d So luong so am
int SLSoAm(int a[], int n){
	long s = 0;
	for(int i=0; i<n; i++)
		if(a[i] < 0)
			s = s + 1;
	return s;
}
//1e Tong cac so
int TongCacSo(int a[],int n){
	long s = 0;
	for(int i=0; i<n; i++)
		s = s + a[i];
	return s;
}
//1f Trung binh cong
float TBC(int a[], int n){
	long s = 0;
	for(int i=0; i<n; i++)
		s = s + a[i];
	return (float)s/n;
}
//1g Trung binh cong so duong
float TBCSoDuong(int a[], int n){
	long s = 0;
	int dem = 0;
	for(int i=0; i<n; i++)
		if(a[i] > 0){
			s = s + a[i];
			dem++;
		}
	return (float)s/dem++;
}
//1h Xuat cac so nguyen to
int KTNT(int n){
	if(n<2)
		return 0;
	for(int i=2; i<n; i++)
		if(n % i == 0)
			return 0;
	return 1;
}
int XuatSNT(int a[], int n){
	for(int i=0; i<n; i++)
		if(KTNT(a[i]) == 1)
			printf("%d\t",a[i]);
}
//1i Dem so nguyen to
int DemSNT(int a[], int n){
	int dem = 0;
	for(int i=0; i<n; i++)
		if(KTNT(a[i]) == 1)
			dem++;
	return dem;
}
//1j Tong cac so nguyen to
int TongNT(int a[], int n){
	int s = 0;
	for(int i=0; i<n; i++)
		if(KTNT(a[i]) == 1)
			s = s + a[i];
	return s;
}
//1k trung binh cong cac so nguyen to
float TbcNT(int a[], int n){
	int s = 0;
	int dem = 0;
	for(int i=0; i<n; i++)
		if(KTNT(a[i])==1){
			dem++;
			s = s + a[i];
		}
	return (float)s/dem++;
}
//1l Pt duong dau tien
int DuongDau(int a[], int n){
	for(int i=0; i<n; i++)
		if(a[i] > 0)
			return a[i];
	return -1;
}
//1m Pt duong cuoi cung
int DuongCuoi(int a[], int n){
	for(int i=n-1; i>0; i--)
		if(a[i] > 0)
			return a[i];
	return -1;
}
//1n Gia tri lon nhat
int GTLN(int a[], int n){
	int max = a[0];
	for(int i=0; i<n; i++)
		if(max < a[i])
			max = a[i];
	return max;
}
//1n Gia tri nho nhat
int GTNN(int a[], int n){
	int i, min = 0;
	for(int i=0; i<n; i++)
		if(a[i] > 0)
			min = a[i];
	for(i=0; i<n; i++)
		if(a[i]>0 && a[i]<min)
			min = a[i];
	return min;
}
//1o Phan tu am lon nhat
int AmLN(int a[], int n){
	int i, max = 0;
	for(int i=0; i<n; i++)
		if(a[i] < 0)
			max = a[i];
	for(i=0; i<n; i++)
		if(a[i]<0 && a[i]>max)
			max = a[i];
	return max;
}
//1o Phan tu duong nho nhat
int DuongNN(int a[], int n){
	int min = a[0];
	for(int i=0; i<n; i++)
		if(a[i] > 0)
			if(min > a[i])
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
//1c
	printf("\n1c. Cac so chia het cho 3: ");
	ChiaHet3(a,n);
//1d
	long sl = SLSoAm(a,n);
	printf("\n1d. So luong so am trong mang: %ld",sl);
//1e
	long s = TongCacSo(a,n);
	printf("\n1e. Tong cac so trong mang: %ld",s);
//1f
	float avg = TBC(a,n);
	printf("\n1f. Trung binh cong cac so trong mang: %f",avg);
//1g
	float avgduong = TBCSoDuong(a,n);
	printf("\n1g. Trung binh cong cac so duong co trong mang: %f",avgduong);
//1h
	int Ktnt = KTNT(n);
	printf("\n1h. Cac so nguyen to trong mang: ");
	int kt = XuatSNT(a,n);
//1i
	int DemNT = DemSNT(a,n);
	printf("\n1i. Dem cac so nguyen to trong mang %d",DemNT);
//1j
	int SumNT = TongNT(a,n);
	printf("\n1j. Tong cac so nguyen to trong mang %d",SumNT);
//1k
	float TbNt = TbcNT(a,n);
	printf("\n1k. Trung binh cac so nguyen to trong mang: %f",TbNt);
//1l
	int x = DuongDau(a,n);
	printf("\n1l. Phan tu duong dau tien co gia tri %d",x);
//1m
	int y = DuongCuoi(a,n);
	printf("\n1m. Phan tu duong cuoi cung co gia tri %d",y);
//1n
	int max = GTLN(a,n);
	printf("\n1n. Gia tri pt lon nhat la %d",max);
//1n
	int min = GTNN(a,n);
	printf("\n    Gia tri pt nho nhat la %d",min);
//1o
	int AmMax = AmLN(a,n);
	printf("\n1o. Phan tu am lon nhat la %d", AmMax);
//1o
	int DuongMin = DuongNN(a,n);
	printf("\n    Phan tu duong nho nhat la %d", DuongMin);
	return 0;
}
