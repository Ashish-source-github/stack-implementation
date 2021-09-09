#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *next;
}Node;

Node *head=NULL,*top=NULL,*cur=NULL;
int top1=-1;

void push()
{
    char ch='y';
    while(ch=='y'||ch=='Y')
    {
        top=(Node *)malloc(sizeof(Node));
        printf("\n\tEnter the element\t");
        scanf("%d",&top->data);
        if(head==NULL)
        {
            head=top;
            top->next=NULL;
            cur=top;
            top1++;

        }
        else
        {
            cur->next=top;
            top->next=NULL;
            cur=top;
            top1++;
        }
        printf("\n\tTo push more elements enter y/Y else n/N\t");
        fflush(stdin);
        scanf("%c",&ch);
    }
}

void pop()
{
    int c=1;
    cur=head;
    while(cur->next!=NULL)
        cur=cur->next;

    while(top1>=0&&c==1)
    {
        printf("\n\tDeleted element from the stack :%d",cur->data);
        top1--;
        free(cur);
        cur=NULL;
        printf("\n\tTo pop out more elements from the stack press 1 else 0\t");
        fflush(stdin);
        scanf("%d",&c);
    }
}

void display()
{
    cur=head;
    if(cur==NULL)
        printf("\n\tStack is empty");
    else
    {
        printf("\n\tElements in the Stack :\n");
        while(cur!=NULL)
        {
            printf("\t%d",cur->data);
            cur=cur->next;
        }
    }

}
void main()
{
    int n=0,ch=0;
    do
    {
        printf("\n\tWELCOME");
        printf("\n\t1.To push elements in the stack using Linked List");
        printf("\n\t2.To Display the stack");
        printf("\n\t3.To pop the element from the stack");
        printf("\n\t4.To Exit\n\t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                display();
                break;
            case 3:
                if(top1<0)
                    printf("\n\tStack Underflow");
                else
                    pop();
                break;
            case 4:
                exit(0);
                break;
        default:
            printf("\n\t!!Wrong Choice Entered");
        }
        printf("\n\tTo re-enter the choices enter 1 else 0 to exit\t");
        scanf("%d",&n);
    }while(n==1);
}

