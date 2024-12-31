#include<stdio.h>
#define MAX 100
//2a
void NhapSLpt(int &n){
	do{
 		printf("Nhap n: ");
 		scanf("%d",&n);
 		if(n<=0 || n>100){
 			printf("Nhap sai, Nhap lai");
		}
	} while(n<=0 || n>100);
}
void NhapMang(int a[],int n){ 
	for(int i=0; i<n;i++){
		printf("Nhap a[%d]",i);
		scanf("%d",&a[i]);
	}
}
//2b
void XuatMang(int a[],int n){
	for(int i=0; i<n;i++)
		printf("%d\t",a[i]);
}

//2c
int VtDuongDau(int a[], int n){
	for(int i=0; i<n;i++)
		if(a[i] > 0)
			return i;
	return -1;
}
int GtDuongDau(int a[],int n){
	for(int i=0; i<n; i++)
		if(a[i] > 0)
			return a[i];
	return -1;
}
//2d
int VtDuongCuoi(int a[], int n){
	for(int i=n-1; i>=0; i--)
		if(a[i] > 0)
			return i;
	return -1;
}
int GtDuongCuoi(int a[],int n){
	for(int i=n-1; i>=0; i--)
		if(a[i] > 0)
			return a[i];
	return -1;
}
//2e
int PtMax(int a[],int n){
	int max = a[0];
	for(int i=0; i<n;i++)
		if(a[0] < a[i])
			max = a[i];
	return max;
}
//2f
int DemMax(int a[],int n){
	int d = 0;
	for(int i=0; i<n; i++)
		if(PtMax(a,n) == a[i])
			d++;
	return d;
}
//2g
void XuatVtMax(int a[],int n){
	for(int i=0; i<n; i++)
		if(PtMax(a,n) == a[i])
			printf("%d,",i);
}
//2h
void ThemptDau(int a[],int &n){
	int x;
	printf("\nNhap pt them vao: ");
	scanf("%d",&x);
	printf("\nMang sau khi them pt dau: ");
	for(int i=n+1; i>=0; i--)
		a[i] = a[i-1];
	a[0] = x;
	n++;
	XuatMang(a,n);
}
//2i
void Themptbk(int a[],int &n,int &y,int &z){
//	int y,z;
	printf("\nNhap pt muon them: ");	scanf("%d",&y);
	printf("\nNhap vt muon them: ");	scanf("%d",&z);
	while(z>n){
		printf("\nNhap vt khong hop le");
		printf("\nNhap vt muon them: ");	scanf("%d",&z);
	}
	printf("\nMang sau khi them pt bat ky: ");
	for(int i=n; i>=z; i--)
		a[i] = a[i-1];
	a[z] = y;
	n++;
	XuatMang(a,n);
}
//2j
void XoaptDau(int a[],int &n){
	for(int i=0; i<n-1; i++)
		a[i] = a[i+1];
	n--;
	XuatMang(a,n);
}
//2k
void XoaVtk(int a[],int &n, int &k){
//	int k;
	printf("\nNhap vi tri muon xoa: ");
	scanf("%d",&k);
	for(int i=k; i<n-1; i++)
		a[i] = a[i+1];
	n--;
	XuatMang(a,n);
}
//2l
int KtLe(int a[],int n){
	for(int i=0; i<n; i++)
		if(a[i]%2 != 0)
			return 1;
	return 0;
}
//2m
int MangChan(int a[], int n){
	for(int i=0; i<n; i++)
		if(a[i]%2 == 0)
			printf("%d\t",a[i]);
}
 
int main()
{
	int n,k,y,z;
	int a[MAX];
	NhapSLpt(n);
	NhapMang(a,n); //2a
	XuatMang(a,n); //2b
	printf("\nVi tri va gia tri phan tu duong dau tien la: %d, %d",VtDuongDau(a,n),GtDuongDau(a,n)); // 2c
	printf("\nVi tri va gia tri phan tu duong cuoi cung la: %d, %d",VtDuongCuoi(a,n),GtDuongCuoi(a,n)); //2d
	int max = PtMax(a,n); //2e
	printf("\nGia tri phan tu lon nhat la: %d",max);
	int dem = DemMax(a,n); //2f
	printf("\nDem gia tri phan tu lon nhat la: %d",dem);
	printf("\nVi tri cua cac phan tu lon nhat la: "); 
	XuatVtMax(a,n);	//2g
	ThemptDau(a,n);	//2h
	Themptbk(a,n,y,z);	//2i
	printf("\nMang sau khi Xoa phan tu dau mang la: ");
	XoaptDau(a,n); //2j
	XoaVtk(a,n,k); //2k
	int kt = KtLe(a,n);	//2l
	if(kt == 1){
		printf("\nMang co chua so le");
	}
	else{
		printf("\nMang khong chua so le");
	}
	printf("\nMang cac so chan: ");
	MangChan(a,n);	//2m
	return 0;
}
