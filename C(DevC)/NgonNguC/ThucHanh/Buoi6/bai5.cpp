//bai 5
#include<stdio.h>
typedef struct thongtinsach{
	char tensach[31];
	char tentacgia[31];
	int namXB;
	char NXB[31];
	long giaban;
	int soluong;
	int slton;
}sach;
void Nhap1sach(sach &s){
	fflush(stdin);
	printf("Ten sach: ");	gets(s.tensach);
	printf("Ten tac gia: "); gets(s.tentacgia);
	printf("Nha xuat ban: "); gets(s.NXB);
	printf("Nam xuat ban: "); scanf("%d",&s.namXB);
	printf("Gia ban: "); scanf("%ld",&s.giaban);
	printf("So luong: "); scanf("%d",&s.soluong);
	printf("So luong ton: "); scanf("%d",&s.slton);
}
void Xuat1sach(sach s){
	printf("%s\t%s\t%d\t%s\t%ld\t%d",s.tensach,s.tentacgia,s.namXB,s.NXB,s.giaban,s.slton);
}
int TienBanSach(sach s){
	return s.giaban*(s.soluong-s.slton);
}

int main()
{
	sach s;
	Nhap1sach(s);
	Xuat1sach(s);
	int tong = TienBanSach(s);
	printf("\nSo tien ban duoc sach la %d",tong);
	return 0;
}
