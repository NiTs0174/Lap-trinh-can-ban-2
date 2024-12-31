#include<stdio.h>
#include<stdlib.h>
struct PS{
	int tu,mau;
};
//	Nhap 1 Phan So
void Nhap1ps(PS *x){
	printf("\nTu so: ");	scanf("%d",&x->tu);
	do{
		printf("Mau so: ");	scanf("%d",&x->mau);
	}while(x->mau == 0);
	if(x->mau < 0){
		x->tu = -x->tu;
		x->mau = -x->mau;
	}
}
//Xuat 1 PS
void Xuat1ps(PS x){
	printf("\t%d/%d",x.tu,x.mau);
}
//	Nhap so luong PS
void Nhappt(int &n){
	do{
		printf("Nhap so phan tu: ");	scanf("%d",&n);
	}while(n<=0);
}
//Nhap day PS
void Nhapdayps(PS *a,int n){
	for(int i=0; i<n; i++){
		printf("\n\tNhap phan so thu %d: ",i+1);
		Nhap1ps((a+i));
	}
}
//Xuat day PS
void Xuatdayps(PS *a, int n){
	for(int i = 0; i<n; i++){
		Xuat1ps(*(a+i));
	}
}
//So sanh 2 PS
int Sosanh2ps(PS x1, PS x2){
	return (x1.tu*x2.mau - x2.tu*x1.mau);
}
//Tim PS lon nhat
PS timmax(PS *x, int n){
	PS max = *x;
	for(int i = 1; i<n; i++){
		if(Sosanh2ps(*(x+i),max) > 0){
			max = *(x+i);
		}
	}
	return max;
}
//Tim Uoc chung lon nhat
int UCLN(int a, int b){
	a = abs(a);	b = abs(b);
	if(a * b == 0)	return 0;
	while(a*b != 0){
		if(a > b)	a = a%b;
		else		b = b%a;
	}
	return (a+b);
}
//Rut Gon PS
PS rutgonPS(PS x){
	int uc = UCLN(x.tu,x.mau);
	x.tu = x.tu/uc;
	x.mau = x.mau/uc;
	return x;
}
//COng 2 PS
PS cong2ps(PS x1, PS x2){
	PS cong;
	cong.tu = (x1.tu*x2.mau + x2.tu*x1.mau);
	cong.mau = (x1.mau * x2.mau);
	return cong;
}
//Cong day PS
PS congdayps(PS *a, int n){
	PS tong = *(a);
	for(int i=1; i<n; i++){
		tong = cong2ps(tong,*(a+i));
	}
	tong = rutgonPS(tong);
	return tong;
}

int main()
{
	int n;
	Nhappt(n);
	PS *a;
	a = (PS*)malloc(n*sizeof(PS));
	Nhapdayps(a,n);
	printf("\n\tDay phan so vua nhap: ");
	Xuatdayps(a,n);
	printf("\n\tPhan so co gia tri lon nhat: ");
	Xuat1ps(timmax(a,n));
	printf("\n\tTong cac phan so trong day so");
	Xuat1ps(congdayps(a,n));
	free(a);
	return 0;
}
