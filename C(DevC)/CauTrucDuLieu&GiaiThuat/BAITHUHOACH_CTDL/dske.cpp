//DANH SACH KE
#include <stdio.h>
#define MAXLIST 100
//DINH NGHIA CUA TRUC
typedef int datatype;
typedef struct list
{
	int num;
	datatype nodes[MAXLIST];
}LIST;
//KHOI DONG DS
void init(LIST &plist)
{
	plist.num = 0;
}
//XAC DINH SO NUT
int listSize(LIST plist)
{
	return plist.num;
}
//KIEM TRA RONG
int isEmpty(LIST plist)
{
	return(plist.num == 0);
}
//KIEM TRA DAY
int isFull(LIST plist)
{
	return(plist.num == MAXLIST);
} 
//NHAP DS
void input(LIST &a)
{
	do{
		printf("Nhap so luong pt: ");
		scanf("%d",&a.num);
	}while(a.num < 0);
	for(int i=0; i<a.num; i++)
	{
		printf("a[%d]: ",i);
		scanf("%d",&a.nodes[i]);
	}
}
//XUAT DS
void output(LIST &a)
{
	for(int i=0; i<a.num; i++)
		printf("\t%d",a.nodes[i]);
}
//TRUY XUAT 1 PT
int retrieve(LIST plist, int pos)
{
	if(pos<0 || pos>=listSize(plist))
	{
		printf("Vi tri %d khong hop le",pos);
		return 0;
	}
	else
		if(isEmpty(plist))
		{
			printf("danh sach rong");
			return 0;
		}
		else	
			return plist.nodes[pos];
}
//THEM 1 PT
void insert(LIST &plist, int pos, int x)
{
	if(pos<0 || pos>listSize(plist))
		printf("\nVi tri chen khong phu hop");
	else
	{
		if(isFull(plist))
		{
			printf("Danh sach bi day");
			return;
		}
		else
		{
			for(int i=listSize(plist)-1; i>=pos; i--)
			{
				plist.nodes[i+1] = plist.nodes[i];
			}
			plist.nodes[pos] = x;
			plist.num++;
		}
	}
}
//XOA 1 PT
int remove(LIST &plist, int pos)
{
	int x = -1;
	if(pos<0 || pos>=listSize(plist))
		return x;
	else
	{
		if(isEmpty(plist))
		return x;
		else
		{
			x = plist.nodes[pos];
			for(int i =pos; i<listSize(plist)-1; i++)
			{
				plist.nodes[i] = plist.nodes[i+1];
			}
			plist.num--;
		}
	}
	return x;
}
//THAY THE 1 PT
void replace(LIST &plist, int pos, int x)
{
	if(pos<0 || pos>=listSize(plist))
	{
		printf("\nVi tri hieu chinh khong dung");
		return;
	}
	else 
	{
		if(isEmpty(plist))
		{
			printf("\nDanh sach khong co phan tu");
			return;
		}
		else 
			plist.nodes[pos] = x;
	}
}
//DUYET DS
void showList(LIST plist)
{
	if(isEmpty(plist))
	{
		printf("\nDanh sach khong co phan tu");
		return;
	}
	for(int i=0; i<plist.num; i++)
	{
		printf("\n%d",plist.nodes[i]);
	}
}
//TIM KIEM 1 PT
int search(LIST plist, int x)
{
	int vitri=0;
	while(plist.nodes[vitri]!=x && vitri<plist.num)
		vitri++;
	if(vitri == plist.num)
		return -1;
	return vitri;
}
//SAP XEP CAC PT
void sort(LIST &plist)
{
	int i,j,vtmin,min;
	for(i=0; i<plist.num-1; i++)
	{
		min = plist.nodes[i];
		vtmin = i;
		for(j=i+1; j<plist.num; j++)
		{
			if(min > plist.nodes[j])
			{
				min = plist.nodes[j];
				vtmin = j;
			}
		}
		plist.nodes[vtmin] = plist.nodes[i];
		plist.nodes[i] = min;
	}
}



int main()
{
	LIST a;
	init(a);
	input(a);
	output(a);
	int chon;
	do{
		printf("\n\n1. Kiem tra DS rong");
		printf("\n2. Kiem tra DS day");
		printf("\n3. Xac dinh so nut trong DS");
		printf("\n4. Truy xuat 1 pt trong DS");
		printf("\n5. Them 1 pt moi vao DS");
		printf("\n6. Xoa 1 pt ra khoi DS");
		printf("\n7. Thay the 1 pt cua DS");
		printf("\n8. Duyet DS");
		printf("\n9. Tim kiem 1 pt trong DS");
		printf("\n10. Sap xep cac pt ben trong DS");
		printf("\n0. Thoat");
		printf("\nMoi nhap chuc nang: "); 	scanf("%d",&chon);
		switch(chon)
		{
			case 1:		//EMPTY CHECK
				if(isEmpty(a) == 1)
					printf("\tEmpty list");
				else
					printf("\tNot empty list");
				break;
			case 2:		//FULL CHECK
				if(isFull(a) == 1)
					printf("\tFull list");
				else
					printf("\tNot full");
				break;
			case 3:		//LIST SIZE
				printf("\tKich thuoc DS: %d",listSize(a));
				break;
			case 4:		//RETRIEVE
				int pos0;
				printf("\tNhap vi tri can truy xuat: ");	scanf("%d",&pos0);
				printf("\tGia tri truy xuat duoc la: %d",retrieve(a,pos0));
				break;
			case 5:		//INSERT
				int pos,x;
				printf("\tNhap vi tri can chen: ");	scanf("%d",&pos);
				printf("\tNhap gia tri can chen: ");	scanf("%d",&x);
				printf("\tDS sau khi them: ");
				insert(a,pos,x);
				output(a);
				break;
			case 6:		//REMOVE
				int pos2;
				printf("\tNhap vi tri can xoa: ");	scanf("%d",&pos2);
				printf("\tDS sau khi xoa: ");
				remove(a,pos2);
				output(a);
				break;
			case 7:		//REPLACE
				int pos3, x3;
				printf("\tNhap vi tri can thay: ");	scanf("%d",&pos3);
				printf("\tNhap gia tri can thay: ");	scanf("%d",&x3);
				printf("\tDS sau khi thay the: ");
				replace(a,pos3,x3);
				output(a);
				break;
			case 8:		//SHOWLLIST
				showList(a);
				break;
			case 9:		//SEARCH
				int x4;
				printf("\tNhap gia tri can tim: ");	scanf("%d",&x4);
				printf("\tVi tri gia tri can tim: a[%d]",search(a,x4));
				break;
			case 10:	//SORT
				printf("\tDS sau khi sap xep: ");		
				sort(a);
				output(a);
				break;
			default:
				printf("Nhap khong hop le!!");
		}
	}while(chon != 0);
	return 0;
}
