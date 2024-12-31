#include<stdio.h>
#include<string.h>
#define MAX 100
struct DATE{
	int ngay,thang,nam;
};
void NhapDATE(DATE &x){
	scanf("%d%*c%d%*c%d",&x.ngay,&x.thang,&x.nam);
}
void XuatDATE(DATE x){
	printf("	%02d/%02d/%4d		",x.ngay,x.thang,x.nam);
}
typedef struct BuuKien{
	char mabk[5];
	char tengui[15];
	char tennhan[15];
	float trongluong;
	DATE ngaygui;
	int dongia; 	
}BK;
//e Gia tri moi buu kien
float giatri1bk(BK a){
	return a.trongluong * a.dongia;
}
void Nhap1bk(BK &a){
	printf("\nMa BK: ");	scanf("%s",&a.mabk);
	fflush(stdin);	printf("Ten nguoi gui: ");	gets(a.tengui);
	fflush(stdin);	printf("Ten nguoi nhan: ");	gets(a.tennhan);
	printf("Trong luong: ");	scanf("%f",&a.trongluong);
	printf("Nhap ngay(d/m/yyyy): ");	NhapDATE(a.ngaygui);
	printf("Don gia: ");	scanf("%d",&a.dongia);
}
void Xuat1bk(BK &a){
	printf("\n%-5s%-16s%-16s%8.1f%12d%12.1f",a.mabk,a.tengui,a.tennhan,a.trongluong,a.dongia,giatri1bk(a));
	XuatDATE(a.ngaygui);
}
void Nhapsl(int &n){
	do{
		printf("\nNhap so luong buu kien: ");	scanf("%d",&n);
		if(n <= 0)
			printf("\nSo luong khong phu hop, yeu cau nhap lai");
	}while(n <= 0);
}
//a Nhap thong tin cac buu kien
void Nhapds(BK a[],int n){
	for(int i=0; i<n; i++){
		printf("\n\tNhap buu kien thu %d",i+1);
		Nhap1bk(a[i]);
	}
}
//b Xuat thong tin cac buu kien
void Xuatds(BK a[],int n){
	for(int i=0; i<n; i++){
		Xuat1bk(a[i]);
	}
}
//c Them 1 buu kien vao danh sach
void thembk(BK a[],int &n){
	printf("\n\tNhap buu kien muon them: ");
	Nhap1bk(a[n]);
	n++;
}
//d Sap xep giam dan theo ma buu kien
void sxbk(BK a[],int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(stricmp(a[i].mabk,a[j].mabk) < 0){
				BK tam;
				tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
	}
}
//f Dem so luong buu kien co trong luong lon nhat
int tlmax(BK a[],int n){
	int max = a[0].trongluong;
	for(int i=0; i<n;i++){
		if(max < a[i].trongluong){
			max = a[i].trongluong;
		}
	}
	return max;
}
int demtlmax(BK a[],int n){
	int dem = 0;
	float max = tlmax(a,n);
	for(int i=0; i<n; i++){
		if(a[i].trongluong == max){
			dem++;
		}
	}
	return dem;
}
//g Tim theo ten nguoi gui buu kien
void timbk(BK a[],int n,char x[]){
	for(int i=0; i<n; i++){
		if(stricmp(a[i].tengui,x) == 0){
			Xuat1bk(a[i]);
		}
	}
}
//h Cac buu kien gui vao thang 04/2014
void bkvao42014(BK a[],int n){
	for(int i=0; i<n; i++){
		if(a[i].ngaygui.thang==4 && a[i].ngaygui.nam==2014){
			Xuat1bk(a[i]);
		}
	}
}

int main()
{
	BK a[MAX];
	int n;
	Nhapsl(n);
	Nhapds(a,n);
	printf("\n\tDanh sach buu kien:");
	Xuatds(a,n);
	thembk(a,n);
	printf("\n\tDanh sach buu kien sau khi them:");
	Xuatds(a,n);
	sxbk(a,n);
	printf("\n\tDanh sach sap xep giam dan theo ma buu kien:");
	Xuatds(a,n);
	printf("\n\tDanh sach co %d buu kien co trong luong lon nhat",demtlmax(a,n));
	char x[15];
	fflush(stdin);	printf("\n\tNhap ten nguoi gui muon tim: "); gets(x);
	printf("\n\tThong tin buu kien cua nguoi gui ten %s",x);
	timbk(a,n,x);
	printf("\n\tCac buu kien gui vao thang 04/2014:");
	bkvao42014(a,n);
	return 0;
}
