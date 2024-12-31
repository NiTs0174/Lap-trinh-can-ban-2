#include<stdio.h>
int KiemTra(int h){
	if(h>=6 && h<=18)
		return 1;
	return 0;
}
int TinhLuong(int h,int k){
	int luong;
	if(k <= 12)
		luong = (k-h)*6000;
	else if(h > 12)
		luong = (k-h)*7500;
	else
		luong = (12-h)*6000 + (k-12)*7500;
	return luong;
}

int main(){
	int h,k;
	printf("Nhap gio vao ca: ");
	scanf("%d",&h);
	printf("Nhap gio ra ca: ");
	scanf("%d",&k);
	if(KiemTra(h)==0 || KiemTra(k)==0){ 
		printf("Nhap sai gio");
	}
	else{
		printf("Tien luong ngay cho cong nhan la: %d",TinhLuong(h,k));
	}
	return 0;
}
