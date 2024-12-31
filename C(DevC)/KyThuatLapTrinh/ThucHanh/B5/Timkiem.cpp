#include<stdio.h>
#include<stdlib.h>
void xuatmang(int a[],int n){
	for(int i=0; i<n; i++){
		printf("%4d",a[i]);
	}
}
void sinhmang(int a[],int &n){
	do{
		printf("Nhap so luong pt: ");	scanf("%d",&n);
	}while(n<=0 || n>100);
	for(int i=0; i<n; i++){
		a[i] = rand()%100;
	}
	printf("Mang vua sinh ngau nhien:\n\t");
	xuatmang(a,n);
}
//tim tuan tu
int timTuanTu(int a[],int n,int x){
	for(int i=0; i<n; i++){
		if(a[i] == x){
			return i;
		}
	}
	return -1;
}
void swap(int &a,int &b){
	int tam = a;
	a = b;
	b = tam;
}
//tim nhi phan
//sx giam
void bubblegiam(int a[],int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){
			if(a[j] < a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}
int timnhiphangiam(int a[],int n,int x){
	bubblegiam(a,n);
	printf("\nMang sau khi sap xep giam dan: ");
	xuatmang(a,n);
	int left = 0, right = n-1,mid;
	while(left <= right){
		mid = (left+right)/2;
		if(a[mid] == x){
			return mid;
		}
		if(a[mid] < x)	right = mid -1;
		else 			left = mid + 1;
	}
	return -1;
}
//sx tang
void interchangetang(int a[],int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i] > a[j]){
				swap(a[i],a[j]);
			}
		}
	}	
}
int timnhiphantang(int a[],int n,int x){
	interchangetang(a,n);
	printf("\nMang sau khi sap xep tang dan: ");
	xuatmang(a,n);
	int left = 0, right = n-1,mid;
	while(left <= right){
		mid = (left+right)/2;
		if(a[mid] == x){
			return mid;
		}
		if(a[mid] > x){
			right = mid -1;
		}
		else{
			left = mid + 1;
		}
	}
	return -1;
}

int main()
{
	int a[100],n,x;
	sinhmang(a,n);
	printf("\nNhap gia tri muon tim: ");	scanf("%d",&x);
	int kq = timTuanTu(a,n,x);
	if(kq == -1)	printf("\nKhong co gia tri can tim!!");
	else			printf("\nGia tri tim thay tra ve vi tri %d",kq);
	int kq1 = timnhiphangiam(a,n,x);
	if(kq1 == -1)	printf("\nMang khong co gia tri can tim!!");
	else 			printf("\nGia tri %d xuat hien tai vi tri %d",x,kq1);
	int kqnp = timnhiphantang(a,n,x);
	if(kqnp == -1)	printf("\nMang khong co gia tri can tim!!");
	else 			printf("\nGia tri %d xuat hien tai vi tri %d",x,kqnp);
	return 0;
}
