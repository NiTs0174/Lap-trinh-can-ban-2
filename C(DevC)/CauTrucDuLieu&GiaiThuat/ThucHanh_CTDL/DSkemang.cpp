#include <stdio.h>
#define MAXLIST 100
//DINH NGHIA
typedef int DataType;
typedef struct list
{
	int num;
	DataType nodes[MAXLIST];
}List;
//KHOI TAO
void init(List &a)
{
	a.num = 0;
}
//MANG 1 CHIEU
void input(List &a)
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
void output(List &a)
{
	for(int i=0; i<a.num; i++)
		printf("\t%d",a.nodes[i]);
}
//XAC DINH NUT
int listsize(List plist)
{
	return plist.num;
}
//FULL CHECK
int isfull(List plist)
{
	return(plist.num == MAXLIST);
} 
//EMPTY CHECK
int isempty(List plist)
{
	return(plist.num == 0);
}
//TRUY XUAT
int retrieve(List plist, int pos)
{
	if(pos<0 || pos>=listsize(plist))
	{
		printf("Vi tri %d khong hop le",pos);
		return 0;
	}
	else
		if(isempty(plist))
		{
			printf("danh sach rong");
			return 0;
		}
		else
			return plist.nodes[pos];
}
//INSERT
void insert(List &plist, int pos, int x)
{
	if(pos<0 || pos>listsize(plist))
		printf("\nVi tri chen khong phu hop");
	else
	{
		if(isfull(plist))
		{
			printf("Danh sach bi day");
		return;
		}
		else
		{
			for(int i=listsize(plist)-1; i>=pos; i--)
			{
				plist.nodes[i+1] = plist.nodes[i];
			}
			plist.nodes[pos] = x;
		plist.num++;
		}
	}
}
//REMOVE
int remove(List &plist, int pos)
{
	int x = -1;
	if(pos<0 || pos >= listsize(plist))
		return x;
	else
	{
		if(isempty(plist))
		return x;
		else
		{
			x = plist.nodes[pos];
			for(int i =pos; i<listsize(plist)-1; i++)
			{
				plist.nodes[i] = plist.nodes[i+1];
			}
			plist.num--;
		}
	}
	return x;
}
//REPLACE
void replace(List &plist, int pos, int x)
{
	if(pos < 0 || pos >= listsize(plist))
	{
		printf("\nVi tri hieu chinh khong dung");
		return;
	}
	else 
	{
		if(isempty(plist))
		{
			printf("\nDanh sach khong co phan tu");
			return;
		}
		else 
			plist.nodes[pos] = x;
	}
}
//SHOW LIST
//void showlist(List plist)
//{
//	if(isempty(plist))
//	{
//		printf("\nDanh sach khong co phan tu");
//		return;
//	}
//	for(int i=0; i<plist.num; i++)
//	{
//		printf("\n%d",plist.nodes[i]);
//	}
//}
//SEARCH
int search(List plist, int x)
{
	int vitri=0;
	while(plist.nodes[vitri] != x && vitri < plist.num)
		vitri++;
	if(vitri == plist.num)
		return -1;
	return vitri;
}
//SORT
void sort(List &plist)
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
	List a;
	init(a);
	input(a);
	output(a);
	printf("\nSize: %d",listsize(a));
//EMPTY CHECK
	if(isempty(a) == 1)
		printf("\nEmpty list");
	else
		printf("\nNot empty");
//FULL CHECK
	if(isfull(a) == 1)
		printf("\nFull list");
	else
		printf("\nNot full");
//INSERT
	int pos,x;
	printf("\nNhap vi tri can chen: ");	
	scanf("%d",&pos);
	printf("\nNhap gia tri can chen: ");	
	scanf("%d",&x);
	insert(a,pos,x);
	output(a);
//REMOVE
	int pos2;
	printf("\nNhap vi tri can xoa: ");	
	scanf("%d",&pos2);
	remove(a,pos2);
	output(a);
//REPLACE
	int pos3, x3;
	printf("\nNhap vi tri can thay: ");	
	scanf("%d",&pos3);
	printf("\nNhap gia tri can thay: ");	
	scanf("%d",&x3);
	replace(a,pos3,x3);
	output(a);
//DUYET 
	//showlist(a);
//SEARCH
	int x4;
	printf("\nNhap gia tri can tim: ");	
	scanf("%d",&x4);
	printf("Vi tri gia tri can tim: a[%d]",search(a,x4));
//SORT
	sort(a);
	output(a);
	
	return 0;
}
