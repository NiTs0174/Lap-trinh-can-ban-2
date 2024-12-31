//DSLK KEP(DOI)
#include <stdio.h>
#include <stdlib.h>
//DN CAU TRUC
struct Node
{
    int data;
    Node *next;
    Node *prev;
};
typedef struct Node NODE;
struct doulist
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct doulist DLIST;
//KHOI DONG
void init(DLIST &ds)
{
    ds.pHead = NULL;
    ds.pTail = NULL;
}
//TAO NUT
NODE* createNode(int x) 
{
    NODE *p = new NODE;
    if (p == NULL) 
	{
        printf ("KHONG DU BO NHO");
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
//THEM DAU
void insertFirst(DLIST &ds, NODE *p) 
{
    if (ds.pHead == NULL)
	{
        ds.pHead = ds.pTail = p;
    }
	else 
	{
        p->next = ds.pHead;
        ds.pHead->prev = p;
        ds.pHead = p;
    }
}
//THEM CUOI
void insertLast(DLIST &ds, NODE*p)
{
    if (ds.pHead == NULL)
	{
        ds.pHead = ds.pTail = p;
    }
	else
	{
        ds.pTail->next = p;
        p->prev = ds.pTail;
        ds.pTail = p;
    }
}
//NHAP
void input(DLIST &ds, int n)
{
    for(int i = 0; i < n; i++)
	{
        int x;
        printf("Nhap vao so %d: ",i);
        scanf("%d",&x);
        NODE *p = new NODE;
        p = createNode(x);
        insertLast(ds,p);
    }
}
//XUAT
void output(DLIST ds)
{
    NODE *p = new NODE;
    for(p = ds.pHead; p!= NULL; p=p->next)
	{
        printf("%d\t",p->data);
    }
}
//TIM KIEM
NODE* search(DLIST ds, int x)
{
    NODE *p;
    p = ds.pHead;
    while ((p!=NULL) && (p->data!=x))
	{
        p=p->next;
    }
    return p;
}
//XOA DAU
void delFirst(DLIST &ds){
    NODE *p = ds.pHead;
    ds.pHead = ds.pHead->next;
    ds.pHead->prev = NULL;
    if (ds.pHead == NULL)
	{
        ds.pTail = NULL;
    }
    p->next = NULL;
    delete p;
}
//XOA CUOI
void delLast(DLIST &ds)
{
    NODE *p = ds.pTail;
    ds.pTail = ds.pTail->prev;
    ds.pTail->next = NULL;
    if (ds.pTail == NULL)
	{
        ds.pHead = NULL;
    }
    p->prev = NULL;
    delete p;
}
//XOA BAT KY
void anyDel(DLIST &ds, int k)
{
    NODE *p = search(ds,k);
    if(p != NULL)
	{
        if (p->prev == NULL)
		{
            delFirst(ds);
            return;
        }
        if (p->next == NULL)
		{
            delLast(ds);
            return;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->prev = NULL; 
        p->next = NULL;
        delete p;
    }
}



int main(){
    DLIST ds;
    init(ds);
//INPUT
    int n;
    do{
    	printf("Nhap so luong phan tu: ");
    	scanf("%d",&n);
	}while(n < 0);
    input(ds,n);
//OUTPUT
    printf("DANH SACH VUA NHAP: ");
    output(ds);
//INSERT FIRST
	int x;
	printf("\nNhap pt can them vao dau ds: ");	scanf("%d",&x);
	NODE* p = createNode(x);
	printf("DANH SACH SAU KHI XOA DAU: ");
	insertFirst(ds,p);
    output(ds);
//SEARCH
    int x1;
    printf("\nNhap gia tri can tim: ");	scanf("%d",&x1);
    NODE* p1 = search(ds,x1);
    if(p1 == NULL)
        printf("Khong tim thay ket qua!!");
	else
	{
        printf("Tim thay ket qua: ");
        printf("%d",p1->data);
    }
//DELETE FIRST
	printf("\nDANH SACH SAU KHI XOA DAU: ");
	delFirst(ds);
	output(ds);
}
