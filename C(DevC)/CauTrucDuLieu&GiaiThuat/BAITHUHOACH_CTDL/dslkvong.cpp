#include <stdio.h>
#include <iostream>
//KHAI BAO
struct Node
{
	int data;
	Node *next;
};
typedef struct List
{
	Node *head;
	Node *tail;
}LIST;

//KHOI tao
void init(LIST &a)
{
	a.head = NULL;
	a.tail = NULL;
}

//TAO NODE
Node *createNode(int x)
{
	Node *p = new Node;
	if(p == NULL)
		return NULL;
	p->data = x;
	p->next = NULL;
	return p;
}

//KIEM TRA RONG
int isEmpty(LIST a)
{
	return(a.head == NULL);
}

//FIRST INSERT
void addHead(LIST &a,int x)
{
	Node *p = createNode(x);
	if(isEmpty(a))
		a.head = a.tail = p;
	else{
		p->next = a.head;
		a.head = p;
	}
	a.tail->next = a.head; //khep vong don
}

//SEARCH
Node *search(LIST a, int x)
{
	Node *p = a.head;
	do{
		if(p->data == x)
			return p;
		else 
			p = p->next;
	}while(p != a.head);
	return NULL;
}

//INPUT
void input(LIST &a){
	int n;
	printf("\nNhap so phan tu: ");	
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		addHead(a,i);
}
//OUT PUT
void output(LIST a)
{
	if(a.head)
	{
		printf("\nCac phan tu cua danh sach: \n");
		Node *p = a.head;
		do{
			printf("\t%d",p->data);
			p = p->next;
		}while(p != a.head);
	}
	else 
		printf("\nDanh sach rong!");
}

//FIRST DELETE
void delHead(LIST &a)
{
	if(!isEmpty(a))
	{
		if(a.head != a.tail)
		{
			Node *p = a.head;
			a.head = a.head->next;
			a.tail->next = a.head;
			delete p;
		}
		else
			a.head = NULL;
	}
}

//Xuat MENU
void menu()
{
	LIST a;
	init(a);
	input(a);
	output(a);
	int chon;
	do{
		printf("\n1.Kiem tra rong");
		printf("\n2.Chen dau");
		printf("\n3.Xoa dau");
		printf("\n4.Tim kiem");
		printf("\n0.Thoat");
		printf("\nNhap lua chon: ");
		scanf("%d",&chon);
		switch(chon)
		{
			case 0:
				printf("THOAT");
				break;
			case 1: 	//ISEMPTY
				if(isEmpty(a) == 1)
					printf("\nEmpty list");
				else
					printf("\nNot empty");
				break;
			case 2:	//ADDHEAD
				{
					int x1;
					printf("\nNhap gia tri: ");	
					scanf("%d",&x1);
					addHead(a,x1);
					output(a);
					break;
				}
			case 3:	//DELETEHEAD
				{
					delHead(a);
					output(a);
					break;
				}
			case 4:	//SEARCH
				{
					int x2;
					printf("\nNhap gia tri can tim: ");	
					scanf("%d",&x2);
					Node* kt = search(a,x2);
					if(kt == NULL)
						printf("\tKhong tim thay!!");
					else
						printf("\tTim thay %d trong DS!!",x2);
					break;
				}
			default:
				printf("\nVui long chon lai!!");
		}
	}while(chon != 0);
}



int main()
{
	menu();
	return 0;
}
