#include<stdio.h>
int main()
{
	int thang;
	printf("Nhap 1 thang trong nam: ");
	scanf("%d",&thang);
	switch(thang){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			printf("Thang %d co 31 ngay",thang); 
			break;
		case 4: case 6: case 9: case 11:
			printf("Thang %d co 30 ngay",thang); 
			break;
		case 2:
			int nam;
			printf("Nhap nam: ");	
			scanf("%d",&nam);
			if(nam%4==0 && nam%100!=0 || nam%400==0){
				printf("Thang %d co 29 ngay (Nam nhuan)",thang);
			}
			else{
			}
			break;
		default: printf("khong ton tai thang nay");
	}
	return 0;
}

