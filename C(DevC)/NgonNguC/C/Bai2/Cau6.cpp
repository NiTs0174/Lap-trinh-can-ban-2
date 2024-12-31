#include<stdio.h>
int main()
{
	int ngay,thang,nam;
	printf("Nhap ngay: ");
	scanf("%d",&ngay);
	printf("Nhap thang: ");
	scanf("%d",&thang);
	printf("Nhap nam: ");
	scanf("%d",&nam);
	switch(thang){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if(ngay>0 && ngay<=31){
				printf("Ngay %d thang %d nam %d hop le",ngay,thang,nam);
		 	}
			else{
				printf("Ngay %d khong hop le",ngay);
			}
			break;
		case 4: case 6: case 9: case 11:
			if(ngay>0 && ngay<=30){
				printf("Ngay %d thang %d nam %d hop le",ngay,thang,nam);
			}
			else{
				printf("Ngay %d khong hop le",ngay);
			}
			break;
		case 2:
			if(ngay>0 && ngay<=29){
				if(nam%4==0 && nam%100!=0 || nam%400==0){
					printf("Ngay %d thang %d nam %d hop le (Nam nhuan)",ngay,thang,nam);
				}
				else if(ngay<29){
					printf("Ngay %d thang %d nam %d hop le",ngay,thang,nam);
				}
				else{
					printf("Ngay %d khong hop le",ngay);
				}
			}
			else{
				printf("Ngay %d khong hop le",ngay);
			}
			break;
		default:
			printf("Thang %d khong hop le",thang);
	}
	return 0;
}
