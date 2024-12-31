//Khai bao thu vien stdio.h vi no chua ham printf
#include<stdio.h>
int main()
{
//1a
	for(int i=1; i<=10; i++){	//Khai bao i=1 theo kieu int, voi dieu kien i nho hon hoac bang 10 va i tang dan 1 don vi
		printf("XIN CHAO CAC BAN\t");	//Xuat ra man hinh 10 dong "XIN CHAO CAC BAN"
	}
//1b
	int n;	//Khai bao bien va nhap vao n
	printf("Nhap n: ");
	scanf("%d",&n);
	for(int i=1; i<=n; i++){	//Khai bao i=1 theo kieu int, voi dieu kien i nho hon hoac bang 10 va i tang dan 1 don vi
		printf("XIN CHAO CAC BAN\n");	//Xuat ra man hinh dong chu cho den khi vong lap ket thuc (i lon hon thi vong lap dung lai)
	}
	return 0;
}

