#include<stdio.h>
#define MAX 100
// Nhap mang
int Nhappt(int &n){
	do{
		printf("Nhap n phan tu: ");
		scanf("%d",&n);
		if(n<=0 || n>100)
			printf("Nhap sai, Nhap lai");
	} while(n<=0 || n>100);
}
void Nhapmang(int a[],int n){
	for(int i=0; i<n; i++){
		printf("Phan tu a[%d]",i);
		scanf("%d",&a[i]);
	}
}
//Xuat mang
void Xuatmang(int a[],int n){
	for(int i=0; i<n; i++)
		printf("%d\t",a[i]);
}
//Vi tri pt lon nhat
int Vtmax(int a[],int n){
	int vt = 0;
	int max = a[0];
	for(int i=0; i<n; i++)
		if(max < a[i]){
			max = a[i];
			vt = i;
		}
	return vt;
}
//Xoa pt dau tien
void Xoapt(int a[],int n){
	for(int i=0; i<n; i++)
		a[i] = a[i+1];
	n--;
}
//Gia tri duong cuoi cung
int Gtdcc(int a[],int n){
	for(int i=n-1; i>=0; i--)
		if(a[i] > 0)
			return a[i];
	return -1;
}
//Vi tri pt duong cuoi cung
int Vtdcc(int a[],int n){
	int vt;
	for(int i=n-1; i>=0; i--)
		if(a[i]>0)
			vt = i;
	return vt;
}

int main(){
	int a[MAX];
	int n;
	Nhappt(n);
	Nhapmang(a,n);
	Xuatmang(a,n);
	int vt = Vtmax(a,n);
	printf("\nVi tri cua phan tu co gia tri lon nhat: %d",vt);
	Xoapt(a,n);
	printf("\nMang sau khi xoa phan tu dau tien: ");
	Xuatmang(a,n);
	int gt = Gtdcc(a,n);
	int vtdcc = Vtdcc(a,n);
	if(gt == -1){
		printf("\nKhong co phan tu co gia tri duong");
	}
	else{
		printf("\nGia tri phan tu duong cuoi cung trong mang: %d",gt);
		printf("\nVi tri phan tu duong cuoi cung trong mang: %d",vtdcc);
	}
	return 0;
}
