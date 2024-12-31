#include<stdio.h>
#include<string.h>
typedef struct sinhvien{
	char ten[11];
	char mssv[11];
	char lop[8];
	char gioitinh;
	int namsinh;
	float toan,ly,tin,DTB;
}sv;
//Nhap so luong SV
void NhapSoSV(int &n){
	printf("Nhap so SV: ");
	scanf("%d",&n);
}
//3a Nhap 1 SV
void Nhap1sv(sv &a){
	fflush(stdin);
	printf("\nNhap ten SV: ");	gets(a.ten);
	printf("Nhap MSSV: ");	gets(a.mssv);
	printf("Nhap lop: ");	scanf("%s",a.lop);
	fflush(stdin);
	printf("Gioi tinh (Nam y/Nu x): ");	scanf("%c",&a.gioitinh);
	printf("Nhap nam sinh: ");	scanf("%d",&a.namsinh);
	printf("Nhap diem toan: "); scanf("%f",&a.toan);
	printf("Nhap diem ly: "); scanf("%f",&a.ly);
	printf("Nhap diem tin: "); scanf("%f",&a.tin);
	a.DTB = (a.toan + a.ly + a.tin)/3;
}
//3b Xuat 1 SV
void Xuat1sv(sv a){
	printf("\nTen sinh vien: %s",a.ten);
	printf("\nMa so sinh vien: %s",a.mssv);
	printf("\nLop: %s",a.lop);
	if(a.gioitinh == 'x')
		printf("\nGioi tinh: nu");
	else
		printf("\nGioi tinh: nam");
	printf("\nNam sinh: %d",a.namsinh);
	printf("\nDiem toan: %f",a.toan);
	printf("\nDiem ly: %f",a.ly);
	printf("\nDiem tin: %f",a.tin);
	printf("\nDiem TB: %f",a.DTB);
}
//3c Nhap DSSV
void NhapDSSV(sv a[],int n){
	for(int i=0; i<n; i++){
		printf("\tNhap sinh vien thu %d: ",i+1);
		Nhap1sv(a[i]);
	}
}
//3d Xuat DSSV
void XuatDSSV(sv a[],int n){
	for(int i=0; i<n; i++){
		printf("\nSinh vien thu %d",i+1);
		Xuat1sv(a[i]);
	}
}
//3e Tim SV co ten la "x"
void timtensv(sv a[],int n, char x[]){
	int flag = 0;
	for(int i=0; i<n; i++)
		if(strcmp(a[i].ten,x) == 0){
			Xuat1sv(a[i]);
			flag = 1;
		}
	if(flag == 0)
		printf("Khong co ten sv can tim");
}
//3f Dem so luong sinh vien co diem trung binh tren 5
int Cau3f(sv a[],int n){
	int dem = 0;
	for(int i=0; i<n; i++)
		if(a[i].DTB > 5)
			dem++;
	return dem;
}
//3g Xuat DSSV nu
void XuatDSSVnu(sv a[],int n){
	int flag = 0;
	for(int i=0; i<n; i++)
		if(a[i].gioitinh == 'x'){
			Xuat1sv(a[i]);
			flag = 1;
		}
	if(flag == 0)
		printf("Khong co sv nu trong lop");
}
//3h Xep hang SV tang dan
void Cau3h(sv a[],int n){
	sv tam;
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i].DTB > a[j].DTB){
				tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
	XuatDSSV(a,n);
}

int main()
{
	sv b;
//3a
	Nhap1sv(b);
//3b
	Xuat1sv(b);
	int n;
	sv a[50];
	NhapSoSV(n);
//3c
	NhapDSSV(a,n);
//3d
	XuatDSSV(a,n);
//3e
	char x[11];
	printf("\n\t3e. Nhap ten SV can tim: ");
	scanf("%s",&x);
	timtensv(a,n,x);
//3f
	int dem = Cau3f(a,n);
	printf("\n\t3f.  So SV co DTB > 5: %d",dem);
//3g
	printf("\n\t3g. Danh sach SV nu: ");
	XuatDSSVnu(a,n);
//3h
	printf("\n\t3h. Xep hang sinh vien co DTB tang dan: ");
	Cau3h(a,n);
	return 0;
}
