#include<stdio.h>
int main()
{
	unsigned int ngay,thang,nam;
	printf("Nhap ngay: ");
	scanf("%u",&ngay);
	printf("Nhap thang: ");
	scanf("%u",&thang);
	printf("Nhap nam: ");
	scanf("%u",&nam);
	
	switch(thang) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (ngay <= 31){
				printf("Ngay %u thang %u nam %u hop le",ngay,thang,nam);
		 	}
			else {
				printf("Ngay %u khong hop le",ngay);
			}
			break;
		case 4: case 6: case 9: case 11:
			if (ngay <= 30){
				printf("Ngay %u thang %u nam %u hop le",ngay,thang,nam);
			}
			else {
				printf("Ngay %u khong hop le",ngay);
			}	
			break;
		case 2:
			if (ngay <= 29){
				if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0){
					printf("Ngay %u thang %u nam %u hop le",ngay,thang,nam);
				}
				else if (ngay < 29){
					printf("Ngay %u thang %u nam %u hop le",ngay,thang,nam);
				}
				else{
					printf("Ngay %u khong hop le",ngay);
				}
			}
			else {
				printf("Ngay %u khong hop le",ngay);
			}
			break;
		default: 
			printf("Thang %u khong hop le",thang);
	}
	return 0;
}
