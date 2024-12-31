#include <stdio.h>
#include <conio.h>

//DINH NGHIA CAU TRUC 
typedef int infotype;
struct node
{
	infotype info;	//info chua thong tin kieu infotype
	node *next;		//next kieu con tro node
};
typedef struct node *NODE;
//KHOI TAO
void init(NODE &phead)
{
	phead = NULL;
}
//KT RONG
int isEmpty(NODE phead)
{
	return(phead == NULL);
}
//TAO NUT
NODE createNode(infotype x)
{
	NODE p = new node;
	p->info = x;
	p->next = NULL;
	return p;
}
//THEM DAU
void insertFirst(NODE &phead, infotype x)
{
	NODE p = createNode(x);
	p->next = phead;
	phead = p;
}
//THEM CUOI
void insertLast(NODE &phead, infotype x)
{
	NODE p = createNode(x);
	if(phead == NULL)
		phead = p;
	else{
		NODE q;
		q = phead;
		//Duyet den cuoi DS
		while(q->next != NULL)
			q = q->next;
		//Moc cuoi phead voi p
		q->next = p;
	}
}
//NHAP
void input(NODE &phead)
{
	int n,x;
	do{	
		printf("\nNhap so luong phan tu: ");
		scanf("%d",&n);
	}while(n < 0);
	for(int i=0; i<n; i++){
		printf("Nhap so can them vao danh sach: ");
		scanf("%d",&x);
		insertLast(phead,x);
	}
}
//DUYET DS (XUAT)
void showList(NODE &phead)
{
	NODE p = phead;
	if(phead == NULL)
		printf("\nEmpty list");
	else
		while(p != NULL){
			printf("\t%d",p->info);
			p = p->next;
		}
}
//SO NUT
int sizeList(NODE phead)
{
	NODE p = phead;
	int n = 0;
	while(p != NULL){
		n++;
		p = p->next;
	}
	return n;
}
//XAC DINH VI TRI CO GIA TRI x (TIM)
NODE search(NODE &phead, infotype x)
{
	NODE p = phead;
	while(p != NULL && p->info != x)
		p = p->next;
	return p;
}
//(CHEN) GIA TRI x SAU NUT p
void insertAter(NODE phead, infotype x, NODE p)
{
	if(p != phead){
		NODE q = phead;
		while(q != p && q != NULL)
			q = q->next;
		if(q != NULL){
			NODE m;
			m = new node;
			m->info = x;
			m->next = p->next;
			p->next = m;
		}
	}
}
//SAP XEP
//INTERCHANGE SORT
void interchangeSort(NODE &phead)
{
	NODE dt;
	infotype data;
	bool cbit = false;
	while(!cbit){
		cbit = true;
		for(dt = phead; dt->next != NULL; dt = dt->next){
			if(dt->info > dt->next->info){
				data = dt->next->info;
				dt->next->info = dt->info;
				dt->info = data;
				cbit = false;
			}
		}
	}
}
//BUBBLE SORT
void bubbleSort(NODE &phead)
{
	NODE dt;
	NODE dt2;
	infotype data;
	for(dt = phead; dt->next != NULL; dt = dt->next)
		for(dt2 = dt->next; dt2 != NULL; dt2 = dt2->next)
			if(dt->info > dt2->info){
				data = dt->info;
				dt->info = dt2->info;
				dt2->info = data;
			}
}
//CHEN
//INSERT ORDER (da sort)
void insertOrder(NODE &phead, infotype x)
{
	NODE p = createNode(x);
	NODE q = phead;
	if(phead == NULL)		//neu ds rong
		phead = p;
	else if(q->info >= x){	//neu nut dau >=x thi chen x vao dau
		p->next = phead;
		phead = p;
	}
	else{
		//Dich den cuoi cung <x trong ds
		while(q->next->info < x && q->next != NULL)
			q = q->next;
		//Moc noi
		p->next = q->next;
		q->next = p;
	}
}
//INSERT ORDER 2
void insertOrder2(NODE &phead, infotype x)
{
	insertLast(phead,x);
	bubbleSort(phead);
}


//HAM MAIN
int main()
{
	NODE a;
	infotype n;
	init(a);
//NHAP DS
	input(a);
//XUAT DS
	printf("\nDay so vua nhap: ");
	showList(a);
//SO NUT
	printf("\nSo nut cua danh sach: %d",sizeList(a));
//TIM			!!!
	infotype x;
	//printf("\nNhap gia tri can tim: ");	scanf("%d",&x);
	//printf("\nGia tri %d o vi tri %d",x,search(a,x));
//CHEN			!!!
	infotype x1;
	//printf("\nNhap gia tri can them: ");	scanf("%d",&x1);
//SAP XEP
	interchangeSort(a);
	printf("\nDanh sach sau khi sap xep: ");
	showList(a);
	return 0;
}
