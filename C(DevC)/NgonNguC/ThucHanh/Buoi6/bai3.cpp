//bai 3
#include<stdio.h>
void NhapMang(int a[],int &n){
	for(int i=0; i<n; i++){
		printf("Phan tu a[%d]: ",i);
		scanf("%d",&a[i]);
	}
}
void XuatMang(int a[], int n){
	printf("Cac phan tu cua mang: ");
	for(int i=0; i<n; i++)
		printf("%d\t",a[i]);
}
int KtHoanThien(int n){
	int s = 0;
	for(int i=0; i<n; i++){
		if(n % i == 0)
			s = s + i;
	}
	if (s == n)
		return 1;
	return 0;
}
void XuatSoHoanThien(int a[],int n){
	printf("\nCac so hoan thien la: ");
	for(int i=0; i<n; i++)
		if(KtHoanThien(a[i]) == 1)
			printf("%d\t",a[i]);
}

int main()
{
	int a[100],n;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	NhapMang(a,n);
	XuatMang(a,n);
	XuatSoHoanThien(a,n);
	XuatMang(a,n);
	return 0;
}
