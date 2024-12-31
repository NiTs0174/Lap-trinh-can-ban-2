//DANH SACH LIEN KET DON
#include <stdio.h>
#include <conio.h>
//DN CAU TRUC 
typedef int datatype;
typedef struct node
{
	datatype info;
	struct node *next;
}Node;
typedef Node *NODEPTR;
//KHOI DONG
void init(NODEPTR &phead)
{
	phead = NULL;
}
//KT RONG
int isEmpty(NODEPTR phead)
{
	return(phead == NULL);
}
//TAO NUT
NODEPTR createNode(datatype x)
{
	NODEPTR p = new node;
	p->info = x;
	p->next = NULL;
	return p;
}
//THEM DAU
void insertFirst(NODEPTR &phead, datatype x)
{
	NODEPTR p = createNode(x);
	p->next = phead;
	phead = p;
}
//THEM CUOI
void insertAfter(NODEPTR &phead, datatype x)
{
	NODEPTR p = createNode(x);
	if(phead == NULL)
		phead = p;
	else
	{
		NODEPTR q;
		q = phead;
		while(q->next != NULL)
			q = q->next;
		q->next = p;
	}
}
//NHAP DS
void input(NODEPTR &phead)
{
	int n,x;
	do{	
		printf("\nNhap so luong phan tu: ");
		scanf("%d",&n);
	}while(n < 0);
	for(int i=0; i<n; i++)
	{
		printf("Nhap so can them vao danh sach: ");
		scanf("%d",&x);
		insertAfter(phead,x);
	}
}
//DUYET(XUAT) DS
void showList(NODEPTR &phead)
{
	NODEPTR p = phead;
	if(phead == NULL)
		printf("\nEmpty list");
	else
		while(p != NULL)
		{
			printf("\t%d",p->info);
			p = p->next;
		}
}
//XOA DAU
void deleteFirst(NODEPTR &phead)
{
	NODEPTR p;
	if(isEmpty(phead))
		printf("\nList is empty!");
	else
	{
		p = phead;
		phead = phead->next;
		delete p;	
	}	
}
//XOA SAU
void deleteAfter(NODEPTR p)
{
	NODEPTR q;
	if(p==NULL || p->next==NULL)
		printf("\nCannot delete node!");
	else
	{
		q = p->next;
		p->next = q->next;
		delete q;
	}
}
//XOA TAT CA CAC NUT
void clearList(NODEPTR &phead)
{
	NODEPTR p;
	while(phead != NULL)
	{
		p = phead;
		phead = p->next;
		delete p;
	}
}
//TIM KIEM
NODEPTR search(NODEPTR phead, datatype x)
{
	NODEPTR p = phead;
	while(p->info != x && p!=NULL)
		p = p->next;
	return p;
}
//SAP XEP(SELECTION SORT)
void sort(NODEPTR &phead)
{
	NODEPTR p,q,pmin;
	datatype min;
	for(p=phead; p->next!=NULL; p=p->next)
	{
		min = p->info;
		pmin = p;
		for(q=p->next; q!=NULL; q=q->next)
		{
			if(q->info < min)
			{
				min = q->info;
				pmin = q;
			}
		}
		pmin->info = p->info;
		p->info = min;
	}
}
//XAC DINH NUT THU i, TRA VE VT NUT i
NODEPTR nodePointer(NODEPTR phead, int i)
{
	NODEPTR p = phead;
	int vitri = 0;
	while(p!=NULL && vitri<i)
	{
		p = p->next;
		vitri++;
	}
	return p;
}
//XAC DINH VT NUT p
int position(NODEPTR phead, NODEPTR p)
{
	int vitri  = 0;
	NODEPTR q = phead;
	while(q!=NULL && q!=p)
	{
		q=q->next;
		vitri++;
	}
	if(q==NULL)
		return -1;
	return vitri;
}
//XAC DINH NUT TRUOC NUT p
NODEPTR preNode(NODEPTR phead, NODEPTR p)
{
	NODEPTR q;
	if(p == phead)
		return NULL;
	q=phead;
	while(q!=NULL && q->next!=p)
		q=q->next;
	return q;
}
//THEM 1 CO ND x TREN DSLK CO THU TU
void place(NODEPTR &phead, datatype x)
{
	NODEPTR p,q;
	q=NULL;
	for(p=phead; p!=NULL && x>p->info; p=p->next)
	{
		q=p;
	}
	if(q==NULL)
		insertFirst(phead,x);
	else
		insertAfter(q,x);
} 



int main()
{
	NODEPTR a;
	datatype n;
	init(a);
//NHAP DS
	input(a);
//XUAT DS
	printf("\nDay so vua nhap: ");
	showList(a);
//XOA DAU
	deleteFirst(a);
	printf("\nDay so sau khi xoa pt dau: ");
	showList(a);
//XOA SAU PT DAU
	deleteAfter(a);
	printf("\nDay so sau khi xoa pt sau: ");
	showList(a);
//SEARCH (CHUA RA VT)
	int x;
	printf("\nNhap gia tri can tim: ");	scanf("%d",&x);
	NODEPTR	p = new node;
	p = search(a,x);
	if(p == NULL)
		printf("\nKhong tim thay!!");
	else
		printf("\nTim thay ket qua");
//NODE POINTER	(CHUA RA VT)
// 	int i;
//	printf("\nNhap gia tri can tim: ");	scanf("%d",&i);
//	NODEPTR p1 = new node;
//	p1 = nodePointer(a,i);
//	if(p1 == NULL)
//        printf("\nKhong tim thay!!");
//    else
//        printf("\nTim thay ket qua");
//POSITION	!!!
//	int x2;
//	NODEPTR p2 = new node;
//	p2 = position(a,x2);
//	printf("\nNhap gia tri can tim: ");	scanf("%d",&x2);
//	if(p2 == -1)
//		printf("\nKhong tim thay!!");
//	else
//    	printf("\nVi tri nut can tim: %d",p2);
//PRE-NODE
//
//SORT
	sort(a);
	printf("\nDanh sach sau khi sap xep: ");
	showList(a);
//PLACE
	datatype x3;
	printf("\nNhap gia tri can them: ");	scanf("%d",&x3);
	place(a,x3);
	showList(a);
//CLEAR LIST
	clearList(a);
	showList(a);
	printf("\nDa xoa DS");
	return 0;
}
