#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
struct DATE{
	int ngay,thang,nam;
};
typedef struct SinhVien{
	char msv[6];
	char ten[15];
	struct DATE ns;
	struct DATE ngaynhaphoc;
	char gt;
	char lop[8];
	float dtb;
}SV;
void NhapDATE(DATE *x){
	scanf("%d%*c%d%*c%d",&x->ngay,&x->thang,&x->nam);
}
void XuatDATE(DATE *x){
	printf("  %02d/%02d/%4d  ",x->ngay,x->thang,x->nam);
}
void Nhapsv(SV *a){
	printf("\nMSSV: ");	scanf("%s",&a->msv);
	printf("Ho ten: ");	fflush(stdin);	gets(a->ten);
	printf("Ngay sinh: ");	NhapDATE(&a->ns);
	printf("Ngay nhap hoc: ");	NhapDATE(&a->ngaynhaphoc);
	do{
		printf("Gioi tinh(x/y): ");	fflush(stdin); scanf("%c",&a->gt);
	}while(a->gt != 'x' && a->gt != 'y');
	printf("Lop: "); fflush(stdin);	scanf("%s",&a->lop);
	printf("DTB: "); scanf("%f",&a->dtb);
}
void Xuatsv(SV *a){
	printf("\n%-6s%-15s",a->msv,a->ten);
	XuatDATE(&a->ns);
	XuatDATE(&a->ngaynhaphoc);
	if(a->gt == 'x')	printf("  Nu   ");
	else				printf("  Nam  ");
	printf("%-10s%5.1f\n",a->lop,a->dtb);
}
void Nhapsl(int &n){
	do{
		printf("Nhap so luong sinh vien: ");	scanf("%d",&n);
	} while(n<=0 || n>100);
}
//5a Nhap Danh sach sinh vien
void Nhapds(SV *a,int n){
	for(int i=0; i<n; i++){
		printf("\n\tNhap SV thu %d: ",i+1);
		Nhapsv(a+i);
	}
}
//5b Xuat Danh sach sinh vien
void Xuatds(SV *a,int n){
	for(int i=0; i<n; i++){
		Xuatsv(a+i);
	}
}
//5h Tim sinh vien ma nhap tu ban phim
int xuatSVma(SV *a,int n,char *ma){
	for(int i=0; i<n; i++){
		if(stricmp((a+i)->msv,ma) == 0){	
			Xuatsv(a+i);
		}
	}
}
//5d Sinh vien thuoc nganh Cong nghe thong tin
void svcntt(SV *a,int n){
	for(int i=0; i<n; i++){
		if(((a+i)->lop[3]=='t' && (a+i)->lop[4]=='h') || ((a+i)->lop[3]=='T' && (a+i)->lop[4]=='H')){
			Xuatsv(a+i);
		}
	}
}
//5g SInh vien nu thuoc nganh cong nghe thong tin
void XuatnuCNTT(SV *a,int n){
	for(int i=0; i<n; i++){
		if(((a+i)->gt =='x' || (a+i)->gt =='X') && ((a+i)->lop[3] =='t' && (a+i)->lop[4] =='h') || ((a+i)->lop[3] =='T' && (a+i)->lop[4] =='H')){
			Xuatsv(a+i);
		}
	}
}
//5h Tim sinh vien theo ten
void timSVten(SV *a,int n,char *tensv){
	for(int i=0; i<n; i++){
		if(stricmp((a+i)->ten,tensv) == 0){	
			Xuatsv(a+i);
		}
	}
}
//5i Tim sinh vien theo MSSV
int timSVma(SV *a,int n,char *masv){
	for(int i=0; i<n; i++){
		if(stricmp((a+i)->msv,masv) == 0){	
			return i;
		}
	}
	return -1;
}
//5j Xuat SV theo lop
int XuatLopSV(SV *a,int n,char *lopsv){
	for(int i=0; i<n; i++){
		if(stricmp((a+i)->lop,lopsv) == 0){	
			Xuatsv(a+i);
		}
	}
}

int main()
{
	int n;
	Nhapsl(n);
	SV *a;
	a = (SV*)malloc(n*sizeof(SV));
	Nhapds(a,n);
	printf("\n\tDanh sach sinh vien:");
	Xuatds(a,n);
	char *ma;
	ma = (char*)malloc(6*sizeof(char));
	printf("\n\tNhap ma sinh vien muon tim: "); scanf("%s",ma);
	printf("\tXuat SV co ma so la %s",ma);
	xuatSVma(a,n,ma);
	printf("\n\tDanh sach sinh vien thuoc nganh cong nghe thong tin: ");
	svcntt(a,n);
	printf("\n\tDanh sach SV nu thuoc nganh CNTT: ");
	XuatnuCNTT(a,n);
	char tensv[15];
	printf("\n\tNhap ten sinh vien muon tim: "); fflush(stdin);	gets(tensv);
	printf("\tXuat SV co ma so la %s",ma);
	timSVten(a,n,tensv);
	printf("\n\tSinh vien co ma %s: ",ma);
	int vt = timSVma(a,n,ma);
	if(vt == -1)	printf("\n\tKhong co SV ma %s",ma);
	else 			Xuatsv(a+vt);
	free(ma);
	char lop[8];
	printf("\n\tNhap lop muon tim: ");	fflush(stdin);	scanf("%s",lop);
	XuatLopSV(a,n,lop);
	free(a);
	return 0;
}
