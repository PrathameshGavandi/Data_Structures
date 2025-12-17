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

int Minimum(PNODE Head)
{
    int iMin = Head -> data;
    while (Head != NULL)
    {
        if(Head -> data < iMin)
        {
            iMin = Head -> data;
        }
        Head = Head -> next;
    }
    return iMin;
    
}




int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,640);
    InsertFirst(&First,240);
    InsertFirst(&First,230);
    InsertFirst(&First,110);

    Display(First);
    
    iRet = Minimum(First);
    printf("Smallest elements from singly linear Linked list is : %d", iRet);

    return 0;
}