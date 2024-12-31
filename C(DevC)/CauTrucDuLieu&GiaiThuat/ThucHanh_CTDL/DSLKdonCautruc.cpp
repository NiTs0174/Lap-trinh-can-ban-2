#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//DINH NGHIA
typedef struct sinhvien 
{
    char masv[10];
    char hoten[40];
    float dtb;
}SV;
typedef struct node
{
    SV data;
    node * next;
}NODE;
typedef struct list
{
    NODE *head;
    NODE *tail;
}LIST;
//KHOI TAO
void init(LIST &a)
{
    a.head = NULL;
    a.tail = NULL;
}
//KIEM TRA RONG
int isEmpty(LIST a)
{
    if (a.head == NULL)
        return 1;
    return 0;
}
//TAO NODE
NODE* createNode(SV x) 
{
    NODE *p;
    p = new NODE;
    if (p==NULL) {
        printf ("KHONG DU BO NHO");
        return NULL;
    }
    p->data=x;
    p->next=NULL;
    return p;
}
//CHEN CUOI
void insertLast(LIST &ds, NODE *p)
{
    if (ds.head==NULL) {
        ds.head=p;
        ds.tail=p;
    }
    else {
        ds.tail->next=p;
        ds.tail=p;
    }
}
//a. NHAP DSSV
void input(LIST &a, int n)
{
    printf("NHAP THONG TIN SINH VIEN\n");
    for(int i = 0; i < n; i++){
        SV x;
        printf ("Ma sinh vien: ");fflush(stdin);
        scanf("%s",&x.masv);
        printf ("Ho ten: ");fflush(stdin);
        gets(x.hoten);
        printf("Dien trung binh: ");
        scanf("%f",&x.dtb);
        printf ("\n \n");
        NODE *p = new NODE;
        p = createNode(x);
        insertLast(a,p);
    }
}
//b. XUAT DSSV
void output(LIST a)
{
    for(NODE *p = a.head; p!= NULL; p=p->next){
        printf("%s\t %s\t %.1f\n", p->data.masv, p->data.hoten, p->data.dtb);
    }
}
//c. SV co DTB > 5
void dtbHon5(LIST a)
{
	for(NODE *p = a.head; p!= NULL; p=p->next)
		if(p->data.dtb > 5)
			output(a);
}
//e. SAP XEP
void interChangeSort(LIST &a)
{
    NODE *p, *q;
    for(p = a.head; p != a.tail; p=p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(p->data.dtb > q->data.dtb){
                SV x = p->data;
                p->data = q->data;
                q->data = x; 
            }
        }
    }
}
//h. XOA CUOI
void deleteLast(LIST &a)
{
    for(NODE *k = a.head; k != NULL; k = k ->next)
    {
        if(k->next == a.tail)
        {
            delete a.tail;
            k->next = NULL;
            a.tail = k;
        }
    }
}



int main()
{
    LIST a;
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d",&n);
    init(a);
//a.. 
    input(a,n);
//b.
    printf("\nDANH SACH SINH VIEN\n");
    output(a);
//c.
	printf("\nDANH SACH SINH VIEN CO DTB LON HON 5\n");
	dtbHon5(a);
////e.
//    printf("\nDANH SACH SINH VIEN SAP XEP TANG DAN THEO DTB\n");
//    interChangeSort(a);
//    output(a);
////h.
//    printf("\nDANH SACH SINH VIEN DA XOA PHAN TU CUOI\n");
//    deleteLast(a);
//    output(a);
}
