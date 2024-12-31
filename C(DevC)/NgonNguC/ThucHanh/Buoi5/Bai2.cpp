#include<stdio.h>
void NhapSL(int &n){
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
}
//2a Nhap mang
void NhapMang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("Phan tu a[%d]: ",i);
		scanf("%d",&a[i]);
		for(int j=0; j<i; j++){
			while(a[i] == a[j]){
				printf("Nhap lai phan tu a[%d]: ",i);
				scanf("%d",&a[i]);
			}
		}
	}
}
//2b Xuat mang
void XuatMang(int a[], int n){
	printf("Cac phan tu cua mang: ");
	for(int i=0; i<n; i++){
		printf("%d\t",a[i]);
	}
}
//2c So chinh phuong tai vi tri le
int SoChinhPhuong(int n){
	for(int i=0; i<n; i++)
		if(i*i==n)
			return 1;
	return 0;
}
void ViTriLe(int a[], int n){
	for(int i=0; i<n; i++)
		if(SoChinhPhuong(a[i])==1  && (i % 2 != 0))
			printf("%d\t",a[i]);
}
//2d Vi tri co phan tu lon nhat
int ViTriMax(int a[], int n){
	int VtMax = 0;
	int max = a[0];
	for(int i=0; i<n; i++)
		if(max < a[i]){
			max = a[i];
			VtMax = i;
		}
	return VtMax;
}
//2e tong cac phan tu o vi tri chan
int TongVTChan(int a[],int n){
	long s = 0;
	for(int i=0; i<n; i++)
		if(i%2==0)
			s = s + a[i];
	return s;
}
//2f sap xep theo thu tu tang dan
void SxTangDan(int a[], int n){
	int mid;
	for(int i=0; i<n; i++)
		for(int j=0; j<=i; j++){
			if(a[j]>a[i]){
				mid = a[i];
				a[i] = a[j];
				a[j] = mid;
			}
		}
	XuatMang(a,n);
}

int main(){
	int a[100], n, chon;
	printf("1. Nhap mang");
	printf("\n2. Xuat mang");
	printf("\n3. Cac so chinh phuong tai vi tri le");
	printf("\n4. Vi tri cua phan tu co gia tri lon nhat");
	printf("\n5. Tong cac phan tu nam o vi tri chan");
	printf("\n6. Sap xep mang theo thu tu tang dan");
	printf("\n0. Thoat");
	printf("\nChon: ");
	scanf("%d",&chon);
	switch(chon){
		case 1:
		NhapSL(n);
			NhapMang(a,n);
			break;
		case 2:
			NhapSL(n);
			NhapMang(a,n);
			XuatMang(a,n);
			break;
		case 3:
			NhapSL(n);
			NhapMang(a,n);
			printf("\n2c. So chinh phuong tai vi tri le: ");
			ViTriLe(a,n);
			break;
		case 4:
			NhapSL(n);
			NhapMang(a,n);
			printf("\n2d. Vi tri co gia tri lon nhat la %d",ViTriMax(a,n));
			break;
		case 5:
			NhapSL(n);
			NhapMang(a,n);
			printf("\n2e. Tong cac so o vi tri chan %ld",TongVTChan(a,n));
			break;
		case 6:
			NhapSL(n);
			NhapMang(a,n);
			printf("\n2f. Thu tu tang dan cua cac phan tu trong mang");
			SxTangDan(a,n);
			break;
		default: 
			printf("\nThoat");
	}
	return 0;
}
