#include<stdio.h>
#include<string.h>
#define MAX 100
struct DATE{
	int ngay,thang,nam;
};
typedef struct SinhVien{
	char msv[5];
	char ten[15];
	char gt;
	struct DATE ns;
	char lop[8];
	float dtb;
}SV;
void NhapDATE(DATE &x){
	scanf("%d%*c%d%*c%d",&x.ngay,&x.thang,&x.nam);
}
void XuatDATE(DATE x){
	printf("  %02d/%02d/%4d  ",x.ngay,x.thang,x.nam);
}
void Nhapsv(SV &a){
	printf("\nMSSV: ");	scanf("%s",&a.msv);
	fflush(stdin);	printf("Ho ten: ");	gets(a.ten);
//	do{
//		printf("Gioi tinh(x/y): "); scanf("%c",&a.gt);
//	}while(a.gt!='x' && a.gt!='y' && a.gt!='X' && a.gt!='Y');
//	printf("Ngay sinh (d/m/yyyy): ");	NhapDATE(a.ns);
//	fflush(stdin);	printf("Lop: "); scanf("%s",&a.lop);
//	printf("DTB: "); scanf("%f",&a.dtb);
}
void Xuatsv(SV a){
	printf("\n%-5s%-15s",a.msv,a.ten);
//	if(a.gt=='x' || a.gt=='X')
//		printf("  Nu  ");
//	if(a.gt=='y' || a.gt=='Y')
//		printf("  Nam  ");
//	XuatDATE(a.ns);
//	printf("%-8s%8.1f\n",a.lop,a.dtb);
}
void Nhapsl(int &n){
	do{
		printf("Nhap so luong sinh vien: ");	scanf("%d",&n);
	} while(n<=0 || n>100);
}
//5a Nhap Danh sach sinh vien
void Nhapds(SV a[],int n){
	for(int i=0; i<n; i++){
		printf("\n\tNhap SV thu %d: ",i+1);
		Nhapsv(a[i]);
	}
}
//5b Xuat Danh sach sinh vien
void Xuatds(SV a[],int n){
	for(int i=0; i<n; i++){
		Xuatsv(a[i]);
	}
}
//5c Sinh vien co Diem trung binh tren 5
void dtbtren5(SV a[],int n){
	for(int i=0; i<n; i++){
		if(a[i].dtb > 5){
			Xuatsv(a[i]);
		}
	}
}
//5d Sinh vien thuoc nganh Cong nghe thong tin
void svcntt(SV a[],int n){
	for(int i=0; i<n; i++){
		if((a[i].lop[3]=='t' && a[i].lop[4]=='h') || (a[i].lop[3]=='T' && a[i].lop[4]=='H')){
			Xuatsv(a[i]);
		}
	}
}
//5e So luong sinh vien nu
int slnu(SV a[],int n){	
	int dem = 0;
	for(int i=0; i<n; i++){
		if(a[i].gt=='x' || a[i].gt=='X'){
			dem++;
		}
	}
	return dem;
}
//5f Sinh vien co diem trung binh cao nhat
float dtbmax(SV a[],int n){	
	int max = a[0].dtb;
	for(int i=0; i<n; i++){
		if(max < a[i].dtb){
			Xuatsv(a[i]);
		}
	}
	return max;
}
void xuatdtbmax(SV a[],int n){
	float max = dtbmax(a,n);
	for(int i=0; i<n; i++){
		if(a[i].dtb == max){
			Xuatsv(a[i]);
		}
	}
}
//5g Them sinh vien vao cuoi danh sach
void themsv(SV a[],int &n){
	printf("\n\tNhap sv them vao: ");
	Nhapsv(a[n]);
	n++;
}
//them sv vao vtri x
SV themx(SV a[],int n,int x){
	printf("\n\tNhap sv them vao: ");
	for(int i=n; i>=x; i--){
		a[i] = a[i-1];
	}
	a[x] = Nhapsv(a,n);
	n++;
}
///	int y,z;
//	printf("\nNhap pt muon them: ");	scanf("%d",&y);
//	printf("\nNhap vt muon them: ");	scanf("%d",&z);
//	while(z>n){
//		printf("\nNhap vt khong hop le");
//		printf("\nNhap vt muon them: ");	scanf("%d",&z);
//	}
//	printf("\nMang sau khi them pt bat ky: ");
//	for(int i=n; i>=z; i--)
//		a[i] = a[i-1];
//	a[z] = y;
//	n++;
//	XuatMang(a,n);
//}
//5h Tim sinh vien ma X
int timsv(SV a[],int n,char ma[]){
	for(int i=0; i<n; i++){
		if(stricmp(a[i].msv,ma) == 0){
			return i;
		}
	}
	return -1;
}
//	Xoa sinh vien x da khi tim thay
void xoasv(SV a[],int &n,int vt){
	for(int i=vt; i<n; i++){
		a[i] = a[i+1];
	}
	n--;
}
//5i Sap xep theo diem trung binh
void sapxepdtb(SV a[],int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i].dtb > a[j].dtb){
				SV tam;
				tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
	}
}

int main()
{
	SV a[MAX];
	int n;
	Nhapsl(n);
	Nhapds(a,n);
	printf("\n\tDanh sach sinh vien:");
	Xuatds(a,n);
//	printf("\n\tDanh sach sinh vien co dien trung binh > 5: ");
//	dtbtren5(a,n);
//	printf("\n\tDanh sach sinh vien thuoc nganh cong nghe thong tin: ");
//	svcntt(a,n);
//	printf("\n\tCo %d sinh nu trong danh sach",slnu(a,n));
//	printf("\n\tDanh sach sinh vien co diem trung binh cao nhat: ");
//	xuatdtbmax(a,n);
//	themsv(a,n);
	int x;
	printf("Nhap vi tri muon them sv vao:");	scanf("%d",&x);
	themx(a,n,x);
	Xuatds(a,n);
//	char ma[5];
//	printf("\tNhap ma sinh vien muon tim: "); scanf("%s",&ma);
//	int vt = timsv(a,n,ma);
//	if(vt == -1)
//		printf("Khong co sinh vien ma %s",ma);
//	else{
//		xoasv(a,n,vt);
//		printf("\n\tDanh sach sinh vien sau khi xoa: ");
//		Xuatds(a,n);
//	}
//	sapxepdtb(a,n);
//	printf("\n\tDanh sap sinh vien sau khi xep diem trung binh tang dan: ");
//	Xuatds(a,n);
	return 0;
}
