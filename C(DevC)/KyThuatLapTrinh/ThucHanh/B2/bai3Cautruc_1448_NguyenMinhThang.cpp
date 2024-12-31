#include<stdio.h>
#include<string.h>
#define MAX 100
struct DATE{
	int ngay,thang,nam;
};
void NhapDATE(DATE &a){	
	scanf("%d%*c%d%*c%d",&a.ngay,&a.thang,&a.nam);
}
void XuatDATE(DATE a){
	printf("	%02d/%02d/%4d	",a.ngay,a.thang,a.nam);
}
typedef struct ThueBaoDienThoai{
	char matb[5];
	char tenchutb[15];
	DATE ngaydk;
	char sdt[12];
	char loaitb[3];
	int tgnoi, tgngoai;
}TBDT;
long cuocphi(TBDT x);	//khai bao h
void Nhap1tb(TBDT &a){
	printf("\nMa thue bao: ");	scanf("%s",&a.matb);
	fflush(stdin);	printf("Ten chu thue bao: ");	gets(a.tenchutb);
	printf("Ngay dang ky: ");	NhapDATE(a.ngaydk);
	fflush(stdin);	printf("So dien thoai: ");	gets(a.sdt);
	do{
		fflush(stdin);	printf("Loai thue bao: ");	scanf("%s",&a.loaitb);
	}while(stricmp(a.loaitb,"TT")!=0 && stricmp(a.loaitb,"TS")!=0);
		printf("Thoi gian goi noi mang: ");	scanf("%d",&a.tgnoi);
		printf("Thoi gian goi ngoai mang: ");	scanf("%d",&a.tgngoai);
}
void Xuat1tb(TBDT &a){
	printf("\n%-5s%-15s",a.matb,a.tenchutb);
	XuatDATE(a.ngaydk);
	printf("%-12s%-3s%5d%5d%12ld",a.sdt,a.loaitb,a.tgnoi,a.tgngoai,cuocphi(a));
}
void Nhapsl(int &n){
	do{
		printf("Nhap so luong thue bao:");	scanf("%d",&n);
	}while(n <= 0 || n > 100);
}
//a Nhap danh sach thue bao
void Nhapds(TBDT a[],int n){
	for(int i=0; i<n; i++){
		printf("\n\tNhap thue bao dien thoai thu %d: ",i+1);
		Nhap1tb(a[i]);
	}
}
//b Xuat danh xuatthue bao
void Xuatds(TBDT a[],int n){
	for(int i=0; i<n; i++){
		Xuat1tb(a[i]);
	}
}
//c Them thue bao
void themtb(TBDT a[],int &n){
	printf("\n\tNhap thue bao muon them vao danh sach:");
	Nhap1tb(a[n]);
	n++;
}
//d Sap xep giam dan theo ma thue bao
void sxtbgiam(TBDT a[],int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(stricmp(a[i].matb,a[j].matb) < 0){
				TBDT tam;
				tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
	}
}
//e Tim theo ten thue bao
void timtentb(TBDT a[],int n,char ten[]){
	printf("\n\tCac thue bao dien thoai co ten %s",ten);
	for(int i=0; i<n; i++){
		if(stricmp(a[i].tenchutb,ten) == 0){
			Xuat1tb(a[i]);
		}
	}
}
//f Xuat thue bao theo laoi
void timloaitb(TBDT a[],int n,char loai[]){
	printf("\n\tCac thue bao theo loai %s: ",loai);
	for(int i=0; i<n; i++){
		if(stricmp(a[i].loaitb,loai) == 0){
			Xuat1tb(a[i]);
		}
	}
}
//g Xuat thue bao dang ky sau nam 2010
void tbsau2010(TBDT a[],int n){
	for(int i=0; i<n; i++){
		if(a[i].ngaydk.nam > 2010){
			Xuat1tb(a[i]);
		}
	}
}
//h Cuoc phi moi thue bao
long cuocphi(TBDT x){
	return x.tgnoi*1500 + x.tgngoai*3000;
}
//i Dem so luong thue bao tra truoc (TT)
int demsltbTT(TBDT a[],int n){
	int dem = 0;
	for(int i=0; i<n; i++){
		if(stricmp(a[i].loaitb,"TT") == 0){
			dem++;
		}
	}
	return dem;
}

int main(){
	TBDT a[MAX];
	int n;
	Nhapsl(n);
	Nhapds(a,n);
	printf("\n\tDanh sach thue bao dien thoai: ");
	Xuatds(a,n);
	themtb(a,n);
	printf("\n\tDanh sach thue bao sau khi them:");
	Xuatds(a,n);
	sxtbgiam(a,n);
	printf("\n\tDanh sach thue bao sau khi sap xep:");
	Xuatds(a,n);
	char ten[15];
	fflush(stdin);	printf("\n\tNhap ten muon tim: ");	gets(ten);
	timtentb(a,n,ten);
	char loai[3];
	do{
		fflush(stdin);	printf("\n\tNhap loai thue bao muon xuat: ");	gets(loai);
	}while(stricmp(loai,"TT")!=0 && stricmp(loai,"TS")!=0);
	timloaitb(a,n,loai);
	printf("\n\tDanh sach thue bao dang ky sau nam 2010");
	tbsau2010(a,n);
	int dem = demsltbTT(a,n);
	printf("\n\tSo luong thue bao tra truoc trong danh sach: %d",dem);
}
