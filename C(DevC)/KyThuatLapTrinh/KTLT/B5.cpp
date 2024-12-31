#include<stdio.h>
#define MAX 100
//Nhap so luong phan tu
void Nhapsl(int &n){
	do{
		printf("Nhap so luong phan tu: ");	scanf("%d",&n);
	}while(n <= 0);
}
//a Nhap mang DE QUY
void NhapMang(int a[],int n){
	if(n > 0){
		NhapMang(a,n-1);
		printf("Nhap a[%d]: ",n-1);
		scanf("%d",&a[n-1]);
	}
}
//b Xuat mang
void XuatMang(int a[],int n){
	if(n > 0){
		XuatMang(a,n-1);
		printf("\t%d",a[n-1]);
	}
}
//c Tong cac pt trong mang
int tongmang(int a[],int n){
	if(n == 0){
		return 0;
	}
	return a[n-1] + tongmang(a,n-1);	
}
//  Pt chan cuoi mang
int timchancuoi(int a[],int n){
	if(n == 0)	return -1;
	int tim = timchancuoi(a,n-1);
	if(a[n-1] % 2 == 0)	return tim = a[n-1];
	return tim;
}

int timchandau(int a[],int n, int i =0){
	if(n == 0)	return -1;
	int tim = timchandau(a,x+1);
	if(a[x+1] % 2 == 0)	return tim = a[x+1];
	return tim;
}
//e Tim pt lon nhat
int timmax(int a[],int n){
	if(n == 1){
		return a[0];
	}
	int max = timmax(a,n-1);
	if(a[n-1] > max){
		max = a[n-1];
	}
	return max;
}

int main()
{
	int a[MAX];
	int n;
	Nhapsl(n);
	NhapMang(a,n);
	printf("\nMang vua nhap: ");
	XuatMang(a,n);
	printf("\nTong cac phan tu co trong mang: %d",tongmang(a,n));
	int tim = timchancuoi(a,n);
	if(tim == -1){
		printf("\nKhong co pt chan trong mang!");
	}
	else{
		printf("\nPhan tu chan cuoi cung co trong mang: %d",tim);
	}
	int x = 0;
	printf("%d",timchandau(a,n));
	printf("\nPhan tu lon nhat co trong mang: %d",timmax(a,n));
	return 0;
}
