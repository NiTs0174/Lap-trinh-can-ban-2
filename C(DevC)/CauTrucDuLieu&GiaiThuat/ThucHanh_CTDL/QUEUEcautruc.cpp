#include <stdio.h>
#define MAXQUEUE 100
//DINH NGHIA STACK
typedef struct benhnhan
{
	int stt;
	char hoten[31];
	int tuoi;
}BN;
typedef struct node
{
	BN info;
	struct node *next;
}NODE;
typedef struct Queue
{
	NODE* front;
	NODE* rear;
}QUEUE;
//KHOI TAO
void init(QUEUE &q)
{
	q.front = q.rear = NULL;
}
//KT RONG
int isEmpty(QUEUE &q)
{
	return(q.front == NULL);
}
//KT DAY
//int isFull(QUEUE q)
//{
//	return((q.front - q.front + 1) % MAXQUEUE == 0);
//}
//TAO NODE
NODE* createNode(BN x)
{
    NODE *p = new NODE;
    if (p==NULL) {
        printf ("KHONG DU BO NHO");
        return NULL;
    }
    p->info = x;
    p->next = NULL;
    return p;
}
//Dem so luong
int soluong(QUEUE Q) {
    int dem = 0;
    for (NODE* M = Q.front; M != NULL; M = M->next) {
        dem++;
    }
    return dem;
}
//THEM PT 
int enQueue(QUEUE &q, BN x)
{
	NODE *p = createNode(x);
	if(isEmpty(q))	q.front = q.rear = p;
	else{
		q.rear->next = p;
		q.rear = p;
	}
}
//LAY PT
int deQueue(QUEUE &q)
{
	q.front = q.front->next;
}
//Nhap 1 benh nhan
void nhap1bn(BN &a)
{
	printf("\nHo ten: ");	fflush(stdin);	scanf("%s",&a.hoten);
	printf("\ntuoi: ");	scanf("%d",&a.tuoi);
}
//xuat 1 benh nhan
void xuat1bn(BN a)
{
	printf("%3d%-31s%4d",a.stt,a.hoten,a.tuoi);
}
//NHAP
void input(QUEUE &q,int n)
{
	BN x;
	for(int i=0; i<n; i++){
		printf("\nBenh nhan thu %d: ",i+1);	scanf("%d",&x);
		nhap1bn(x);
		enQueue(q,x);
	}
}
//XUAT
void output(QUEUE q)
{
	for(NODE* i=q.front; i!=NULL; i=i->next){
		xuat1bn(i->info);
	}
}
//ADD ANY
void add(QUEUE& Q, QUEUE& Q2, int k, BN x) {
    init(Q2);
    BN sv;
    int a = soluong(Q) - (k - 1);
    for (int i = 0; i < k - 1; i++) {
        sv = Q.front->info;
        deQueue(Q);
        enQueue(Q2, sv);
    }
    enQueue(Q2, x);
 
    for (int i = 0; i < a; i++) {
        sv = Q.front->info;
        deQueue(Q);
        enQueue(Q2, sv);
    }
    Q = Q2;
 
}
//XOA BAT KY
void DeleteAny(QUEUE& Q, QUEUE& Q2, int k) {
    init(Q2);
    BN sv;
    int a = (soluong(Q) - (k - 1)) - 1;
    for (int i = 0; i < k - 1; i++) {
        sv = Q.front->info;
        deQueue(Q);
        enQueue(Q2, sv);
    }
    deQueue(Q);
    for (int i = 0; i < a; i++) {
        sv = Q.front->info;
        deQueue(Q);
        enQueue(Q2, sv);
    }
    Q = Q2;
}



int main()
{
	BN a;
	QUEUE q, q2;
	init(q);
	int n,chon;
	do{
		printf("So luong BN: ");	scanf("%d",&n);
	}while(n<=0);
	do{
		printf("\n1. THEM 1 BENH NHAN VAO QUEUE.");
		printf("\n2. LAY BENH NHAN TIEP THEO SE KHAM.");
		printf("\n3. CHO BIET SO LUONG NGUOI DA KHAM.");
		printf("\n4. CHO BIET SO LUONG NGUOI CHUA KHAM.");
		printf("\n5. XUAT DANH SACH BENH NHAN CON TRONG HANG DOI CHO KHAM.");
		printf("\n0. thoat.");
		printf("\nNhap lua chon: ");	scanf("%d",&chon);
		switch(chon){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
		}
	}while(chon != 0);
	return 0;
}
