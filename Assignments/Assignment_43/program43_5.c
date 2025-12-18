#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc (sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*Head == NULL)  // LInked list empty
    {
        (*Head) = newn;
    }
    else                // Linked list contains atleast 1 node
    {
        newn -> next = (*Head);
        (*Head) = newn;
    }
}

void Display(PNODE Head)
{
    while (Head != NULL)
    {
        printf("| %d |->", Head ->data);
        Head = Head -> next;
    }
    printf("NULL \n");
    
}

void SumDigits(PNODE Head)
{
    while (Head != NULL)
    {
        int iRem = 0,iSum = 0;
        while ((Head -> data) != 0)
        {
            iRem = (Head -> data) % 10;
            iSum = iSum + iRem;
            (Head -> data) = (Head -> data) / 10;
        }
        printf("%d\t",iSum);
        Head = Head -> next;
    }
      
}



int main()
{
    PNODE First = NULL;
    
    InsertFirst(&First,640);
    InsertFirst(&First,240);
    InsertFirst(&First,20);
    InsertFirst(&First,230);
    InsertFirst(&First,110);

    Display(First);

    SumDigits(First);
    
    
    return 0;
}