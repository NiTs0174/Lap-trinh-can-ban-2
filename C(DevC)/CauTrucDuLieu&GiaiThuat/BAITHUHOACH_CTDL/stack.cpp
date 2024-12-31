//STACK(NGAN XEP)
#include <stdio.h>
#define MAX 100
//DN CAU TRUC
typedef int item;
typedef struct stack
{
    int top;
    item data[MAX];
}STACK;
//KHOI DONG
void init(STACK &s)
{
    s.top = 0;
}
//KT RONG
int isempty(STACK s)
{
    return(s.top == 0);
}
//KT DAY
int isfull(STACK s)
{
    return (s.top == MAX);
}
//THEM 1 PT VAO STACK
void push(STACK &s, item x)
{
    if (!isfull(s))
    {
        s.data[s.top] = x;
        s.top ++;
    }
}
//
//int peak(STACK s)
//{
//    return s.data[s.top-1];
//}
//LAY 1 PT RA  KHOI STACK
int pop(STACK &s)
{
    if(!isempty(s))
    {
        s.top --;
        return s.data[s.top];
    }
}
//NHAP STACK
void input (STACK &s)
{
    int n;
    item x;
    do
    {
        printf("Nhap so luong pt: ");
        scanf("%d",&n);
    } while (n>MAX || n<1);
    for (int i=0; i<n; i++)
    {
        printf("Nhap phan tu thu %d : ",i+1);
        scanf("%d",&x);
        push(s,x);
    }
}
//XUAT STACK
void output(STACK s)
{
    for (int i=s.top-1; i>=0; i--)
        printf("%d   ",s.data[i]);
    printf("\n");
}



int main()
{
    STACK s;
    init(s);
    input(s);
    output(s);
    int chon;
    do{
	    printf("\n\n1. Kiem tra Stack rong");
	    printf("\n2. Kiem tra Stack day");
	    printf("\n3. Them phan tu vao Stack");
	    printf("\n4. Xoa phan tu trong Stack");
	    printf("\n0. Thoat");
    	printf("\nMoi chon chuc nang: ");	scanf("%d",&chon);
        switch(chon)
        {
        	case 0:
        		printf("\nThoat!!");
        		break;
            case 1:	//CHECK EMPTY
                if(isempty(s)) 
					printf("\tSTACK empty!!");
                else 
					printf ("\tNot STACK empty!!");
                break;
            case 2:	//CHECK FULL
                if(isfull(s)) 
					printf("\tSTACK full!!");
                else 
					printf ("\tNot STACK full!!");
                break;
            case 3:	//THEM
                item x;
                printf ("\tNhap pt can them: ");	
				scanf("%d",&x);
            	printf ("\tDANH SACH STACK SAU KHI THEM: ");
                push(s,x);
                output(s);
                break;
            case 4:	//XOA
            	printf ("\tDANH SACH STACK SAU KHI XOA: ");
                pop(s);
                output(s);
                break;
            default:
            	printf("\tNhap khong hop le!!");
            	break;
        }
    }while(chon != 0);
    return 0;
}
