#include<stdio.h>
#include<string.h>
#define MAX 100
struct SACH{
	char masach[5];
	char tensach[15];
	char tentg[15];
	char loaisach[3];
	int namxb,giatien,sl;
};
void Nhap1sach(SACH &a){
	printf("\nMa sach: ");	scanf("%s",&a.masach);
	fflush(stdin);	printf("Ten sach: ");	gets(a.tensach);
	fflush(stdin);	printf("Ten tac gia: ");	gets(a.tentg);
	do{
		fflush(stdin);	printf("Loai sach(TN hoac XH): ");	scanf("%s",&a.loaisach);
	}while(stricmp(a.loaisach,"TN")!=0 && stricmp(a.loaisach,"XH")!=0);
	printf("Nam xuat ban: ");	scanf("%d",&a.namxb);
	printf("Gia tien: ");	scanf("%d",&a.giatien);
	printf("So luong: ");	scanf("%d",&a.sl);
}
void Xuat1sach(SACH a){
	printf("\n%-6s%-15s%-15s",a.masach,a.tensach,a.tentg);
	if(stricmp(a.loaisach,"TN")==0)
		printf("  Tu nhien  ");
	else
		printf("  Xa hoi    ");
	printf("%6d%12d%8d",a.namxb,a.giatien,a.sl);
}
void Nhapsl(int &n){
	do{
		printf("Nhap so luong sach:");	scanf("%d",&n);
	}while(n <= 0 || n > 100);
}
//a Nhap danh sach
void Nhapds(SACH a[],int n){
	for(int i=0; i<n; i++){
		printf("\n\tNhap sach thu %d: ",i+1);
		Nhap1sach(a[i]);
	}
}
//b Xuat danh sach
void Xuatds(SACH a[],int n){
	for(int i=0; i<n; i++)
		Xuat1sach(a[i]);
}
//c Them sach
void themsach(SACH a[],int &n){
	printf("\n\tNhap thong tin sach them vao:");
	Nhap1sach(a[n]);
	n++;
}
//d Tinh tong tat ca cac cuon sach
long tinhtong(SACH a[],int n){
	long tong = 0;
	for(int i=0; i<n; i++)
		tong += a[i].giatien * a[i].sl;
	return tong;
}
//e Sap xep danh sach thue giam dan theo ma thue bao
void sxsachgiamdan(SACH a[],int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(stricmp(a[i].masach,a[j].masach) < 0){
				SACH tam;
				tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
	}
}
//f Tim theo ten sach
void timtensach(SACH a[],int n,char ten[]){
	printf("\n\tSach co ten %s:",ten);
	for(int i=0; i<n; i++){
		if(stricmp(a[i].tensach,ten) == 0){
			Xuat1sach(a[i]);
		}
	}
}
//g Xuat sach xuat ban truoc nam 2000
void xbtruoc2000(SACH a[],int n){
	for(int i=0; i<n; i++){
		if(a[i].namxb < 2000){
			Xuat1sach(a[i]);
		}
	}
}
//h Dem so luong sach co gia tren 50000
int demslgiahon50000(SACH a[],int n){
	int dem = 0;
	for(int i=0; i<n; i++){
		if(a[i].giatien > 50000){
			dem++;
		}
	}
	return dem;
}
//i Xuat sach theo loai
void xuatloaisach(SACH a[],int n,char loai[]){
	printf("\n\tSach loai %s",loai);
	for(int i=0; i<n; i++){
		if(stricmp(a[i].loaisach,loai) == 0){
			Xuat1sach(a[i]);
		}
	}
}

int main()
{
	SACH a[100];
	int n;
	Nhapsl(n);
	Nhapds(a,n);
	printf("\n\tDanh sach sach: ");
	Xuatds(a,n);
	themsach(a,n);
	printf("\n\tDanh sach sach sau khi them vao:");
	Xuatds(a,n);
	int tong = tinhtong(a,n);
	printf("\n\tTong thanh tien cua danh sach = %ld",tong);
	sxsachgiamdan(a,n);
	printf("\n\tDanh sach giam dan theo ma sach");
	Xuatds(a,n);
	char ten[15];
	fflush(stdin); printf("\n\tNhap ten sach can tim: "); gets(ten);
	timtensach(a,n,ten);
	printf("\n\tDanh sach co nam xuat ban truoc nam 2000");
	xbtruoc2000(a,n);
	int dem = demslgiahon50000(a,n);
	printf("\n\tCo %d sach co gia ban tren 50000",dem);
	char loai[3];
	do{
	fflush(stdin);	printf("\n\tLoai sach can tim(TN hoac XH): ");	scanf("%s",&loai);
	}while(stricmp(loai,"TN")!=0 && stricmp(loai,"XH")!=0);
	printf("\n\tDacnh sach loai sach can tim:");
	xuatloaisach(a,n,loai);
	return 0;
}
