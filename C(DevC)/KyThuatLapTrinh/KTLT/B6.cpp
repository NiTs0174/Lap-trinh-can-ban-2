#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct HocVien{
	char mahv[10];
	char tenhv[40];
	int tuoi;	
}HV;
//	Nhap 1 hocv ien
void Nhap1HV(HV &x){
	printf("\nMa hoc vien: ");	scanf("%s",&x.mahv);
	printf("Ten hoc vien: ");	fflush(stdin);	gets(x.tenhv);
	printf("Tuoi: ");	scanf("%d",&x.tuoi);
}
//	Xuat 1 hoc vien
void Xuat1HV(HV x){
	printf("\n%-11s%-40s%3d",x.mahv,x.tenhv,x.tuoi);
}
//	Nhap DSHV va ghi vao file 
void NhapDSHV(HV a[],int &n){
	FILE *f;
	f = fopen("dssv.bat","wb");
	if(f == NULL){
		printf("Khong mo duoc File!");
		return;
	}
	do{
		printf("\nNhap so luong hoc vien: ");	scanf("%d",&n);
	}while(n <= 0);
	for(int i=0; i<n; i++){
		printf("\tNhap hoc vien thu %d",i+1);
		Nhap1HV(a[i]);
		fwrite(&a[i],sizeof(a[i]),1,f);
	}
	fclose(f);
}
//	Doc file dssv.bat xuat ra DSHV
void XuatDSHV(HV a[],int n){
	FILE *f;
	f = fopen("dssv.bat","rb");
	if(f == NULL){
		printf("Khong mo duoc File!");
		return;
	}
	for(int i=0; i<n; i++){
		fread(&a[i],sizeof(a[i]),1,f);
		while(!feof(f)){
			Xuat1HV(a[i]);
			fread(&a[i],sizeof(a[i]),1,f);
		}
	}
	fclose(f);
}
//	Hoan doi vi tri(hoan vi)
void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}
// Interchange Sort
void InterchangeSort(HV a[],int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(stricmp(a[i].mahv,a[j].mahv) > 0){
				HV temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
}
//	Bubble sort
void BubbleSort(HV a[],int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=n-1; j>i; j++)
			if(stricmp(a[j].mahv,a[j-1].mahv) > 0){
				HV temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
}
//tim kiem bang tim kiem nhi phan
int binarySearch(HV a[],int n,char ma[])
{
	int left, right, mid;
	left = 0;	right = n-1;
	while(left <= right){
		mid = (left+right)/2;
		if(stricmp(a[mid].mahv,ma) == 0)	return mid;
		else
			if(stricmp(a[mid].mahv,ma) == 0)	left = mid + 1;
			else							right = mid -1;
	}
	return -1;
}

int main()
{
	HV x;
	HV a[100];
	int n;
//	printf("\tNhap thong tin 1 hoc vien: ");
//	Nhap1HV(x);
//	printf("\tThong tin 1 hoc vien vua nhap: ");
//	Xuat1HV(x);
	NhapDSHV(a,n);
	printf("\tDanh sach thong tin hoc vien:");
	XuatDSHV(a,n);
	InterchangeSort(a,n);
	printf("\n\tSap xep bang Intechange Sort: ");
	XuatDSHV(a,n);
//	char ma[10];
//	printf("\nNhap ma hoc vien can tim: ");	scanf("%s",&ma);
//	int tim = binarySearch(a,n,ma);
//	if(tim == -1)	printf("\nKhong co hoc vien ma %s",ma);
//	else
	return 0;
}
