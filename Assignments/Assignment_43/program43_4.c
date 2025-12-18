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

int SecMaximum(PNODE Head)
{
    int iFirstMax = -2147483648;
    int iSecondMax = -2147483648;

    while (Head != NULL)
    {
        if (Head->data > iFirstMax)
        {
            iSecondMax = iFirstMax;
            iFirstMax = Head->data;
        }
        else if ((Head->data > iSecondMax) && (Head->data != iFirstMax))
        {
            iSecondMax = Head->data;
        }
        Head = Head->next;
    }

    return iSecondMax;
}



int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,41);
    InsertFirst(&First,32);
    InsertFirst(&First,20);
    InsertFirst(&First,11);

    Display(First);

    iRet = SecMaximum(First);
    printf("Second maximum element is : %d", iRet);
    
    
    return 0;
}