#include<stdio.h>
#include<math.h>
typedef struct PHANSO
{
	int tu,mau;
}PS;
//1a Nhap 1 phan so
void NhapPS(PS &x){
		printf("\nNhap tu so: ");
		scanf("%d",&x.tu);
	do{
		printf("Nhap mau so (khac 0): ");
		scanf("%d",&x.mau);
		if(x.mau == 0)
			printf("Nhap sai, nhap lai");
	} while(x.mau == 0);
	if(x.mau < 0){
		x.tu = -x.tu;
		x.mau = -x.mau;
	}
}
//1b Xuat 1 phan so
void XuatPS(PS x){	
	printf("%d/%d\t",x.tu,x.mau);
}
//Tim Uoc chung lon nhat
int UCLN(int a, int b){
	a = abs(a);
	b = abs(b);	
	while(a != b){
		if(a > b)
			a = a - b;
		else
			b = b - a;
	return a;
	}
}
//1c Rut gon phan so
void RutGon(PS x){
	if(x.tu == 0)
		return;
	int z = UCLN(x.tu,x.mau);
	if(x.tu != 0){
	x.tu = x.tu/z;
	x.mau = x.mau/z;
	}
	printf("\tRut gon phan so: %d/%d",x.tu,x.mau);
}
//1d Tinh tong hai phan so
PS Cong(PS x,PS y){
	PS tong;	
	tong.tu = x.tu*y.mau + y.tu*x.mau;
    tong.mau = x.mau*y.mau;
//	RutGon(tong);
	return tong;
}
//1e So sanh hai phan so
int SoSanh(PS x, PS y){	
	return x.tu * y.mau - y.tu * x.mau;
}
//2a Nhap day phan so
void NhapDPS(PS a[],int &n){
	for(int i=0; i<n; i++){
		printf("Nhap phan so thu %d: ",i+1);
		NhapPS(a[i]);
	}
}
//2b Xuat day phan so
void XuatDPS(PS a[],int n){
	printf("Cac phan so: ");
	for(int i=0; i<n; i++)
		XuatPS(a[i]);
}
//2c Tinh tong day phan so
PS TongDPS(PS a[],int n){
	PS s;
	s.mau = 1; 
	s.tu = 0;
	for(int i=0; i<n; i++)
		s = Cong(a[i],s);
//	RutGon(s);
	return s;
}
//2d Tim phan so lon nhat
PS PSLN(PS a[],int n){
	int b,c;
	PS max = a[0];
	for(int i=0; i<n; i++){
		c = max.tu*a[i].mau;
		b = a[i].tu *max.mau;
			if(c<b){
				max = a[i];
			}
	}
	return max;
}
//2e Sap xep day phan so tang dan

void SXPS(PS a[],int n);
/*void SXPS(PS a[],int n){
	PS mid;
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if((a[j].tu/a[j].mau) < (a[i].tu/a[i].mau)){
				mid = a[i];
				a[i] = a[j];
				a[j] = mid;
			}
	XuatDPS(a,n);
}*/

int main()
{	
	PS x,y;
//1a,b,c
	printf("Nhap phan so thu 1: ");
	NhapPS(x);
	XuatPS(x);
	RutGon(x);
	printf("\nNhap phan so thu 2: ");
	NhapPS(y);
	XuatPS(y);
	RutGon(y);
//1d
	PS tong = Cong(x,y);
	printf("\nTong cua hai phan so la: ",tong);
	XuatPS(tong);
//1e
	int kq = SoSanh(x,y);
	if(kq == 0){
		printf("\nps1 bang ps2");
	}
	else if(kq > 0){
		printf("\nps1 lon hon ps2");
	}
	else{
		printf("\nps1 nho hon ps2");
	}
//2a,b
	int n;
	PS a[50];
	printf("\nNhap so luong phan so: ");
	scanf("%d",&n);
	NhapDPS(a,n);
	XuatDPS(a,n);
//2c
	PS tong2 = TongDPS(a,n);
	printf("\nTong cac phan so trong day: ");
	XuatPS(tong2);
//2d
	PS max = PSLN(a,n);
	printf("\n Phan so lon nhat la ");
	XuatPS(max);
//2e
//	printf("\n Phan so tang dan: ");
//	SXPS(a,n);
	return 0;
}
