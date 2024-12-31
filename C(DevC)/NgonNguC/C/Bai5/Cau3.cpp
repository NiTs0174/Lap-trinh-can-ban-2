#include<stdio.h>
void NhapSL(int &n){
	do{
		printf("Nhap so phan tu 0<sl<100: ");
		scanf("%d",&n);
	} while(n<=0 || n>100);
}
//3a Nhap mang
void NhapMang(float a[], int n){
	for(int i=0; i<n; i++){	
		printf("\ta[%d]  ",i);
		scanf("%f",&a[i]);
	}
}
//3b Xuat mang
void XuatMang(float a[],int n){	
	for(int i=0; i<n; i++)
		printf("%8.2f\t",a[i]);
}

int main()
{
	float a[100];
	int n;
	NhapSL(n);
//3a
	NhapMang(a,n);
//3b
	XuatMang(a,n);
	return 0;
}
