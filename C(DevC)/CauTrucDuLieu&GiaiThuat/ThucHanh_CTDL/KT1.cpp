#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//DINH NGHIA CAU TRUC
typedef struct HoaDon
{
    char mahd[11];
    char tenkh[30];
    float tongtien;
}HOADON;
typedef struct node
{
    HOADON data;
    node* next;
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
NODE* createNode(HOADON x) 
{
    NODE *p;
    p = new NODE;
    if (p==NULL) {
        printf ("KHONG DU BO NHO");
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}
//CHEN DAU
void addHead(LIST &a, NODE* p)
{
	if(a.head == NULL){
		a.head = p;
		a.tail = p;
	}
	else{
		p->next = a.head;
		a.head = p;
	}
}
//CHEN CUOI
void insertLast(LIST &a, NODE *p)
{
    if (a.head==NULL) {
        a.head=p;
        a.tail=p;
    }
    else {
        a.tail->next=p;
        a.tail=p;
    }
}
//a. NHAP DSSV
void input(LIST &a, int n)
{
    printf("NHAP THONG TIN HOA DON\n");
    for(int i = 0; i < n; i++){
        HOADON x;
        printf ("Ma hoa don: ");fflush(stdin);
        scanf("%s",&x.mahd);
        printf ("Ten khach hang: ");fflush(stdin);
        gets(x.tenkh);
        printf("Tong tien phai tra: ");
        scanf("%f",&x.tongtien);
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
        printf("%s\t %s\t %.1f\n", p->data.mahd, p->data.tenkh, p->data.tongtien);
    }
}
//c. XOA CUOI
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
//d. SAP XEP
void sort(LIST &a)
{
    NODE *p, *q;
    for(p = a.head; p != a.tail; p=p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(p->data.tongtien < q->data.tongtien){
                HOADON x = p->data;
                p->data = q->data;
                q->data = x; 
            }
        }
    }
}
//e. Chen x sau k=2
void insert(LIST &a,NODE *q,NODE *p)
{
	if(q != NULL){
		p->next = q->next;
		q->next = p;
		if(a.tail == q)
			a.tail = p;
	}
	else
		addHead(a,p);
}


int main()
{
    LIST a;
    init(a);
    int chon;
    do{
    	printf("\n1. Nhap vao danh sach cac hoa don");
    	printf("\n2. Xuat danh sach hoa don");
    	printf("\n3. Xoa hoa don cuoi cung trong danh sach");
    	printf("\n4. Danh sach hoa don giam dan theo tong tien");
    	printf("\n5. Them 1 hoa don vao sau hoa don thu 2 trong danh sach");
    	printf("\nNhap chon: ");	scanf("%d",&chon);
    	switch(chon){
    		case 1:
  				int n;
    			printf("\nNhap so hoa don: ");
    			scanf("%d",&n);
    			input(a,n);
    			break;
    		case 2:
    			printf("\nDANH SACH HOA DON\n");
			 	output(a);
	 			break;
    		case 3:
    			printf("\nDANH SACH HOA DON SAU KHI XOA\n");
    			deleteLast(a);
    			output(a);
    			break;
    		case 4:
			 	printf("\nDANH SACH HOAD DON SAU KHI SAP XEP\n");
    			sort(a);
    			output(a);
    			break;
    		case 5:
    			//NODE* x = createNode();
    			//insert(a,p,q);
    			output(a);
				break;
			default:
				printf("\nNhap lai");
		}
	}while(chon != 0);
}
