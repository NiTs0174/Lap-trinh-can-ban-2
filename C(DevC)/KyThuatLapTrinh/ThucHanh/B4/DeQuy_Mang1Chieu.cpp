#include<stdio.h>
//Nhap n pt
void Nhapn(int &n){
	do{
		printf("Nhap so luong phan tu: ");	scanf("%d",&n);
	}while(n < 0);
}
//a Nhap mang
void Nhapmang(int a[],int n){
	if(n > 0){
		Nhapmang(a,n-1);
		printf("Nhap pt a[%d]: ",n-1);
		scanf("%d",&a[n-1]);
	}
}
//b Xuat mang
void Xuatmang(int a[],int n){
	if(n > 0){
		Xuatmang(a,n-1);
		printf("\t%d",a[n-1]);
	}
}
//c Tong cac pt trong mang
int tongmang(int a[],int n){
	if(n == 0)	return 0;
	return a[n-1] + tongmang(a,n-1);
}
//d Tong cac pt chan trong mang
int tongchan(int a[],int n){
	if(n == 0)	return 0;
	int s = tongchan(a,n-1);
	if(a[n-1] % 2 ==0)	s+= a[n-1];
	return s;
}
//e Dem so duong co trong mnang
int demduong(int a[],int n){
	if(n == 0)	return 0;
	int dem  = demduong(a,n-1);
	if(a[n-1] > 0)	dem++;
	return dem;
}
//f Tim pt lon nhat trong mang
int timmax(int a[],int n){
	if(n == 1)	return a[0];
	int max = timmax(a,n-1);
	if(a[n-1] > max)	max = a[n-1];
	return max;
}
//Tim pt nho nhat trong mang
int timmin(int a[],int n){
	if(n == 1)	return a[0];
	int min = timmin(a,n-1);
	if(a[n-1] < min)	min = a[n-1];
	return min;
}
//g Tim pt chan cuoi mang
int chancuoi(int a[],int n){
	if(n == 0)	return -1;
	int cc = chancuoi(a,n-1);
	if(a[n-1] %2 ==0)	cc = a[n-1];
	return cc;
}
//h Tim vi tri x cuoi trong mang
int vtxcuoi(int a[],int n,int x){
	if(n == 0)	return -1;
	int vt = vtxcuoi(a,n-1,x);
	if(a[n-1] == x)	vt = n-1;
	return vt;
}

int main()
{
	int a[100],n;
	Nhapn(n);
	Nhapmang(a,n);
	printf("\nMang vua nhap:");
	Xuatmang(a,n);
	printf("\nTong cac phan tu cua mang = %d",tongmang(a,n));
	printf("\nTong cac phan tu chan trong mang = %d",tongchan(a,n));
	printf("\nCo %d so duong trong mang",demduong(a,n));
	printf("\nPhan tu lon nhat trong mang = %d",timmax(a,n));
	printf("\nPhan tu nho nhat trong mang = %d",timmin(a,n));
	int cc = chancuoi(a,n);
	if(cc == -1)	printf("\nMang khong co phan tu chan!");
	else			printf("\nPhan tu chan cuoi cua mang = %d",cc);
	int x;
	printf("\nNhap gia tri muon tim: ");	scanf("%d",&x);
	int vt = vtxcuoi(a,n,x);
	if(vt == -1)	printf("\nTrong mang khong co phan tu nay!");
	else			printf("\nGia tri phan tu %d cuoi tai vi tri %d",x,vt);
	return 0;
}
